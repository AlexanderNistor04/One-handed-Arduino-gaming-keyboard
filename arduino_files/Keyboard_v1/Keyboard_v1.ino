// Author: Alexander Nistor
#include <Keyboard.h>
#include <Adafruit_NeoPixel.h>

#define ledCount 5                  //how many LEDs are there
#define ledPin 10                   //which pin are they connected to

int longPressDelay = 0;           //customizable keyboard values
int spamSpeed = .001;

byte inputs[] = {4,5,6,7,8};          //declaring inputs and outputs
#define inCount sizeof(inputs)/sizeof(inputs[0])
byte outputs[] = {9,10,11,12};
#define outCount sizeof(outputs)/sizeof(outputs[0])

char layout[4][5] = {               //layout grid for characters (adjust if your grid is not 4x4)
     {'`','1','2','3','4'},  //pin 9
     {179,'q','w','e','r'},  //pin 10
     {193,'a','s','d','f'},  //pin 11
     {129,'z','x','c','v'}   //pin 12
//pins 4,  5 , 6 , 7 , 8
}; 

int keyDown[outCount][inCount];
bool keyLong[outCount][inCount];

Adafruit_NeoPixel strip = Adafruit_NeoPixel(ledCount, ledPin, NEO_GRB + NEO_KHZ800);

void setup(){
  
  for(int i=0; i<outCount; i++){    //declaring all the outputs and setting them high
    pinMode(outputs[i],OUTPUT);
    digitalWrite(outputs[i],HIGH);
  }
  for(int i=0; i<inCount; i++){     //declaring all the inputs and activating the internal pullup resistor
    pinMode(inputs[i],INPUT_PULLUP);
  }
  
  Serial.begin(9600);               //establishing Serial link and initializing keyboard
  Serial.println("Connected");
  Keyboard.begin();

  strip.begin();                    //initializing LEDs and setting them all to white
  
  //------------------------------------------------
  // put your initial LED color configuration here, e.g. this:
  
  for (int i = 0; i<ledCount; i++){
    strip.setPixelColor(i,50,50,50);
  }
  
  //------------------------------------------------
  
  strip.show();
}

//Main loop going through all the keys, then waiting 0.5ms
void loop() {
  for (int i=0; i<outCount; i++)
  {    
    digitalWrite(outputs[i],LOW);   //setting one row low
    delayMicroseconds(5);           //giving electronics time to settle down
    
    for(int j=0; j<inCount; j++)
    {
      if(digitalRead(inputs[j]) == LOW)
      {
        keyPressed(i,j);            //calling keyPressed function if one of the inputs reads low
      }
      else if(keyDown[i][j] != 0)   //resetting the key if it is not pressed any more
      {  
        resetKey(i,j);
      }
    }
    
    digitalWrite(outputs[i],HIGH);
    delayMicroseconds(500);         //setting the row high and waiting 0.5ms until next cycle
  }
}

//if a key is pressed, this Funtion is called and outputs to serial the key location, it also sends the keystroke if not already done so
void keyPressed(int row, int col){
  Serial.print("Output: "); 
  Serial.print(row);
  Serial.print(" Input: ");
  Serial.print(col);
  Serial.print(" ");
  Serial.println(layout[row][col]);
Keyboard.release(layout[row][col]);
  if(keyDown[row][col]==0){         //if the function is called for the first time for this key
    Keyboard.write(layout[row][col]);
  }
  else if(keyLong[row][col] && keyDown[row][col] > spamSpeed){ //if the key has been held long enough to warrant another keystroke set
    Keyboard.write(layout[row][col]);
    keyDown[row][col] = 1;
  }
  else if(keyDown[row][col] > longPressDelay){ //if the key has been held for longer that longPressDelay, it switches into spam mode
    keyLong[row][col] = true;
    Keyboard.press(layout[row][col]);
  }

  keyDown[row][col]++;
}

void resetKey(int row, int col){ //resetting the variables after key is released
  keyDown[row][col] = 0;
  keyLong[row][col] = false;
}
