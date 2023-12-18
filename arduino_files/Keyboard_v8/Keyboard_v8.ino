#include <Keyboard.h>
#include <Mouse.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_NeoPixel.h>
#define numOfLEDs 35
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numOfLEDs,10, NEO_GRB + NEO_KHZ800);
Adafruit_SSD1306 display(128, 32, &Wire, -1);
                                                     
byte inputs[] = {1, 0, 4, 5, 6, 7};//declaring inputs and outputs
byte outputs[] = {A2, A1, A0, 15, 14, 16};
#define inCount sizeof(inputs)
#define outCount sizeof(outputs)

char profile[6][6] = {  //layout grid for characters
     {'`', '1', '2', '3', '4', '5'},   //pin 1
     {179 ,'q', 'w', 'e', 'r', 't'},   //pin 0
     {193, 'a', 's', 'd', 'f', 'g'},   //pin 4
     {129, 'z', 'x', 'c', 'v', 'b'},   //pin 5
     {128,'\0', 130, ' ','\0', 177},   //pin 6
     {199, 198, 197, 196, 195, 194},   //pin 7
//pins A2   A1   A0   15   14   16
};
// this is a 2d array that keeps track of when a key is pressed down. When a key is pressed, its row and col are put into the array, and its value is asssigned to true, and then when the key is released, its value is assigned to false
bool keyDown[outCount][inCount];
// this represents the index for each LED, starting at 0 and going to 34
int LEDnum = 0;
// this represents the index for the profile
int profileNum = 0;
// this represents the index for the LED color. 0 is off, 1-6 are static colors, 7 is the rainbow wave thingy
int colorProfile = 7;
#define numOfProfiles 2
#define numOfColors 8
// these are the RGB values used by the LEDs for the ranbow function
int r, g, b;
// this counter is used as the time variable in the wave function for the rainbow effect
int counter;

// these store the analog stick position in terms of x and y
int xAnalog = 0;
int yAnalog = 0;
// these help calibrate the analog stick by centering it, defining a deazone, and setting sensitivity
#define xAnalogCalibrate -7
#define yAnalogCalibrate 4
#define xDeadZone 50
#define yDeadZone 50
#define xSensitivity 25
#define ySensitivity 25
// these are the different characters that the stick can press
char analogKeys[4] = {'6', '7', '8', '9'};
// this array stores the bool values of whether or not the stick has been tilted and in what direction, so that way you can keep track of when a key is pressed and released
bool tilt[4];
// these keep track of when certain modifier keys are pressed, which helps with functions
bool fn;
bool shift;
bool ctrl;
// counter for the scroll wheel which makes it so that it scrolls as a slower speed
int scrollCounter = 0;

//sets up the display and creates a String array that stores all the lines being displayed
#define numLines 4
String displayQueue[numLines];

void setup(){                
 
 for(int i=0; i<outCount; i++){    //declaring all the outputs and setting them high
    pinMode(outputs[i],OUTPUT);
    digitalWrite(outputs[i],HIGH);
  }
  for(int i=0; i<inCount; i++){     //declaring all the inputs and activating the internal pullup resistor
    pinMode(inputs[i],INPUT_PULLUP);
  }
  pinMode(A8,INPUT);
  pinMode(A9,INPUT);
 
  Serial.begin(9600);               //establishing Serial link and initializing keyboard
  Keyboard.begin();
  Mouse.begin();
  pixels.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

// display setup
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.display();
}

//Main loop going through all the keys, then waiting 0.5ms
void loop() {
  for (int i = 0; i < outCount; i++){    
    digitalWrite(outputs[i], LOW);   //setting one row low
    delayMicroseconds(5);           //giving electronics time to settle down
    for(int j = 0; j < inCount; j++){
      if(digitalRead(inputs[j]) == LOW && !keyDown[j][i]){
        keyPressed(j, i);
      }            //calling keyPressed function if one of the inputs reads low
      if(digitalRead(inputs[j]) == HIGH && keyDown[j][i]){   //resetting the key if it is not pressed any more
        resetKey(j, i);
      }
    }
    digitalWrite(outputs[i], HIGH);
    delayMicroseconds(500);
  }//setting the row high and waiting 0.5ms until next cycle

//goes through all the LEDs and updates them
  for(int i = 0; i < numOfLEDs; i ++){
    LEDnum = i;
    LEDs();
  }
  pixels.show();

//if on the rainbow LED mode
  if(colorProfile == 7){ 
    counter ++;
    if(counter > 1023){counter = 0;}
    r = waveFN(counter);
    g = waveFN(counter + (1023 / 3));
    b = waveFN(counter + 2 * (1023 / 3));
  }
 
  //this takes the inputs from the analog stick and centers it at 0, ranging from -512 to +512
  xAnalog = analogRead(A8) - 512 + xAnalogCalibrate;
  yAnalog = analogRead(A9) - 512 + yAnalogCalibrate;

  //these read the analog values to tell when the stick is tilted, then calls the tilt and release functions when necessary
  if(profileNum == 0){
  // if in the mouse mode, tilting the stick moves the cursor
    if(fn){
      scrollCounter ++;
      if(scrollCounter % 15 == 0){
      Mouse.move(0, 0, -yAnalog / 100);
      }
    }else{
      Mouse.move(xAnalog / xSensitivity, yAnalog / ySensitivity, 0);
    }
    // if not in mouse mode, tilting the stick presses keys instead
  }else{
    if(xAnalog <= -xDeadZone && !tilt[1]){tiltStick(1);}
    if(xAnalog > -xDeadZone && tilt[1]){releaseStick(1);}
    if(xAnalog >= xDeadZone && !tilt[3]){tiltStick(3);}
    if(xAnalog < xDeadZone && tilt[3]){releaseStick(3);}
    if(yAnalog <= -yDeadZone && !tilt[0]){tiltStick(0);}
    if(yAnalog > -yDeadZone && tilt[0]){releaseStick(0);}
    if(yAnalog >= yDeadZone && !tilt[2]){tiltStick(2);}
    if(yAnalog < yDeadZone && tilt[2]){releaseStick(2);}
  }

}
                                                                                                                                                                                                                                                                                                                                                                                                                                                       
//if a key is pressed, this Funtion is called and outputs to serial the key location, it also sends the keystroke if not already done so
void keyPressed(int row, int col){
  //this prints out the input value of the key, the output value, and the key being pressed
  Serial.print("press:   Output: ");
  Serial.print(row);
  Serial.print(" Input: ");
  Serial.print(col);
  Serial.print(" ");
  Serial.println(profile[row][col]);
  displayLines("press: " + String(profile[row][col]));
  //this lets the program know that the key has been pressed, so it'll know whether or not to release the key if the key isn't being pressed anymore
  keyDown[row][col] = true;
  // these change some bool variables which keep track of when specific mod keys are pressed which are used for special functions
  if(row == 4 && col == 1){fn = true;}
  if(row == 3 && col == 0){shift = true;}
  if(row == 4 && col == 0){ctrl = true;}
  // if FN and 1 are pressed, function 1 is called, which switches the color of the LEDs
  if(fn && row == 0 && col == 1){
    colorProfile++;
    Serial.println("function: 1");
    displayLines("function: 1");
    if(colorProfile > numOfColors - 1){colorProfile = 0;}
    displayLines("color: " + String(colorProfile));
    return;
  }
  // if FN and 2 are pressed, function 2 is called, which changes the function of the analog stick
  if(fn && row == 0 && col == 2){
    profileNum++;
    Serial.println("function: 2");
    displayLines("function: 2");
    if(profileNum > numOfProfiles - 1){profileNum = 0;}
    displayLines("profile: " + String(profileNum));
    return;
  }
  //if the board is in the mouse profile and the button under the stick is pressed, either a left click or a right click is sent. Left click by default, right click if shift is being held
  if(profileNum == 0 && row == 4 && col == 4){
    if(fn){
      Mouse.press(MOUSE_RIGHT);
    }else{
    Mouse.press(MOUSE_LEFT);
    }
  }
  //this actually presses the key
  Keyboard.press(profile[row][col]);
}
         
void resetKey(int row, int col){ //resetting the variables after key is released
  //this prints out the input, output, and the released key, which helps troubleshoot
  Serial.print("release: Output: ");
  Serial.print(row);
  Serial.print(" Input: ");
  Serial.print(col);
  Serial.print(" ");
  Serial.println(profile[row][col]);
  displayLines("release: " + String(profile[row][col]));
  //and this actually releases the key
  Keyboard.release(profile[row][col]);
  // this lets the program know that the key has actually been released, so it doesn't have to keep track of it anymore
  keyDown[row][col] = false;
  // sets these bool vars false once their respective key has been released
  if(row == 4 && col == 1){fn = false;}
  if(row == 3 && col == 0){shift = false;}
  if(row == 4 && col == 0){ctrl = false;}
  // releases the mouse press
  if(profileNum == 0 && row == 4 && col == 4){
    if(fn){
      Mouse.release(MOUSE_RIGHT);
    }else{
    Mouse.release(MOUSE_LEFT);
    }
  }
}

// presses the keys when the stick is tilted
void tiltStick(int index){
  Serial.print("stick tilt:    ");
  Serial.println(analogKeys[index]);
  displayLines("tilt: " + String(analogKeys[index]));
  Keyboard.press(analogKeys[index]);
  tilt[index] = true;
}

// releases the stick keys
void releaseStick(int index){
  Serial.print("stick release: ");
  Serial.println(analogKeys[index]);
  displayLines("release: " + String(analogKeys[index]));
  Keyboard.release(analogKeys[index]);
  tilt[index] = false;
}

//changes the color of the LEDs based on what the colorProfile var equals
void LEDs(){
  switch(colorProfile){
    case 1:
      pixels.setPixelColor(LEDnum, pixels.Color(255, 0, 0));
      break;
    case 2:
      pixels.setPixelColor(LEDnum, pixels.Color(255, 255, 0));
      break;
    case 3:
      pixels.setPixelColor(LEDnum, pixels.Color(0, 255, 0));
      break;
    case 4:
      pixels.setPixelColor(LEDnum, pixels.Color(0, 255, 255));
      break;
    case 5:
      pixels.setPixelColor(LEDnum, pixels.Color(0, 0, 255));
      break;
    case 6:
      pixels.setPixelColor(LEDnum, pixels.Color(255, 0, 255));
      break;
    case 7:
      pixels.setPixelColor(LEDnum, pixels.Color(r, g, b));
      break;
    default:
      pixels.setPixelColor(LEDnum, pixels.Color(0, 0, 0));
      break;
  }
}

// custom wave function used for the rainbow effect. function starts at 0, gradually increases to 255, holds at 255, gradually decreases to 0, holds at 0, then repeats
int waveFN(int i){
  int x = i % 1023;
  int y;
  if(x <= 255){
    y = x;
  }
  if(x > 255 && x <= 511){
    y = 255;
  }
  if(x > 511 && x <= 767){
    y = 767 - x;
  }
  if(x > 767 && x <= 1023){
    y = 0;
  }
  return y;
}

//Queues a new line on the display and pushes the other lines down to make space
void displayLines(String s){
  for(int i = numLines - 1; i > 0; i--){
    displayQueue[i] = displayQueue[i-1];
  }
  displayQueue[0] = s;

  display.clearDisplay();
  for(int i = 0; i < numLines; i++){
    display.setCursor(0, 8*i);
    display.print(displayQueue[i]);
  }
  display.display();
}