// Author: Alexander Nistor
#include <Keyboard.h>
#include <Mouse.h>
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(29,9, NEO_GRB + NEO_KHZ800);
                                                     
byte inputs[] = {14,16,10,1,0,2};//declaring inputs and outputs
#define inCount sizeof(inputs)/sizeof(inputs[0])
byte outputs[] = {A3,A2,A1,A0,15};
#define outCount sizeof(outputs)/sizeof(outputs[0])

char profile_1[5][6] = {  //layout grid for characters (profile 1)
     {'`','1','2','3','4',177},  //pin A3
     {179,'q','w','e','r',' '},  //pin A2
     {193,'a','s','d','f',128},  //pin A1
     {129,'z','x','c','v',130},  //pin A0
     {199,198,197,196,195,194},  //pin 15
//pins 7,  6,  5,  4,  3,  2     
};

char profile_alt[5][6] = {  //layout grid for characters (mode shift)
     {'5','6','7','8','9',177},  //pin A3
     {179,'t','y','u','i',' '},  //pin A2
     {193,'g','h','j','k',128},  //pin A1
     {129,'b','n','m',',',130},  //pin A0
     {205,204,203,202,201,200},  //pin 15
//pins 7,  6,  5,  4,  3,  2     
};

char profile_alt_2[5][6] = {  //layout grid for characters (mode shift)
     {'0','-','=',178, 92,177},  //pin A3
     {179,'o','p','[',']',' '},  //pin A2
     {193,'l',';', 39,176,128},  //pin A1
     {129,'.','/',133,131,130},  //pin A0
     {209,212,215,216,217,218},  //pin 15
//pins 7,  6,  5,  4,  3,  2     
};

/*int LEDs[5][6] = {  //layout grid for characters (profile 1)
     { 7,15,16,24,25, 6},
     { 8,14,17,23,24,20}, 
     { 9,13,18,22,25,11}, 
     {10,12,19,21,26,13},  
     { 0, 1, 2, 3, 4, 5}, 
};*/
           
int keyDown[outCount][inCount];

int button_detect;
int profile_counter = 0;
int color_counter = 1;
int LED_NUM = 0;
float RGB_counter = 0;
int mode_switch = 0;

int x_analog;
int y_analog;

char left_analog_1 = 'a';
char right_analog_1 = 'd';
char up_analog_1 = 'w';
char down_analog_1 = 's';

char left_analog_2 = '2';
char right_analog_2 = '4';
char up_analog_2 = '1';
char down_analog_2 = '3';

int left_analog_counter = 0;
int right_analog_counter = 0;
int up_analog_counter = 0;
int down_analog_counter = 0;

int x_DPI = 50;
int y_DPI = 50;

int F1 = 0;
int F2 = 0;
int F3 = 0;
int F4 = 0;
int M1 = 0;

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
  Mouse.begin();
  pixels.begin();

  pinMode(7,INPUT);
  pinMode(4,INPUT);
  pinMode(8,INPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
}

//Main loop going through all the keys, then waiting 0.5ms
void loop() {
for (int i=0; i<outCount; i++){    
  digitalWrite(outputs[i],LOW);   //setting one row low
  delayMicroseconds(5);           //giving electronics time to settle down
    for(int j=0; j<inCount; j++){
      if(digitalRead(inputs[j]) == LOW){
        keyPressed(i,j);}            //calling keyPressed function if one of the inputs reads low
        else if(keyDown[i][j] != 0){   //resetting the key if it is not pressed any more
          resetKey(i,j);}} 
            digitalWrite(outputs[i],HIGH);
            delayMicroseconds(500);}         //setting the row high and waiting 0.5ms until next cycle

button_detect = digitalRead(7);

if(button_detect == 1){
  if(F1 == 1){
    color_counter ++;
      if(color_counter > 9){color_counter = 1;}
        delay(250);}
  if(F2 == 1){
      if(x_DPI > 10){x_DPI -= 10;}
      if(y_DPI > 10){y_DPI -= 10;}
        delay(250);}
  if(F3 == 1){
      if(x_DPI < 100){x_DPI += 10;}
      if(y_DPI < 100){y_DPI += 10;}
        delay(250);}        
  if(F1 == 0 & F2 == 0 & F3 == 0 & F4 == 0){
  profile_counter ++;
    if(profile_counter > 1){profile_counter = 0;}
      delay(250);}  } 
            
RGB_counter ++;
int r = 128 * sin(RGB_counter/200) + 128;
int g = 128 * sin(RGB_counter/200 + (M_PI*2/3)) + 128;
int b = 128 * sin(RGB_counter/200 + (M_PI*4/3)) + 128;

if(color_counter == 1){pixels.setPixelColor(LED_NUM, pixels.Color(255,0,0));}
if(color_counter == 2){pixels.setPixelColor(LED_NUM, pixels.Color(255,255,0));}
if(color_counter == 3){pixels.setPixelColor(LED_NUM, pixels.Color(0,255,0));}
if(color_counter == 4){pixels.setPixelColor(LED_NUM, pixels.Color(0,255,255));}
if(color_counter == 5){pixels.setPixelColor(LED_NUM, pixels.Color(0,0,255));}
if(color_counter == 6){pixels.setPixelColor(LED_NUM, pixels.Color(255,0,255));}
if(color_counter == 7){pixels.setPixelColor(LED_NUM, pixels.Color(255,255,255));}
if(color_counter == 8){pixels.setPixelColor(LED_NUM, pixels.Color(r,g,b));}
if(color_counter == 9){pixels.setPixelColor(LED_NUM, pixels.Color(0,0,0));}
pixels.show();
LED_NUM ++;
if(LED_NUM >= 29){LED_NUM = 0;}
if(RGB_counter >= 400*M_PI){RGB_counter = 0;}

x_analog = analogRead(A8);
y_analog = analogRead(A6);

if(profile_counter == 0){
  Mouse.move(-(x_analog - 512)/x_DPI,(y_analog - 512)/y_DPI,0);
  analogWrite(3,0);
  analogWrite(5,0);
  analogWrite(6,0);}

if(profile_counter == 1){
    if(448>=x_analog){mode_switch = 2;}
      if(x_analog>=576){mode_switch = 1;}
        if(x_analog<=576 & 448<=x_analog){mode_switch = 0;}    
                  
  analogWrite(3,0);
  analogWrite(5,0);
  analogWrite(6,100);}

  Serial.println(M1);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                       
//if a key is pressed, this Funtion is called and outputs to serial the key location, it also sends the keystroke if not already done so
void keyPressed(int row, int col){

  Serial.print("Output: "); 
  Serial.print(row);
  Serial.print(" Input: ");
  Serial.print(col);
  Serial.print(" ");

  if(mode_switch == 0){
    Serial.println(profile_1[row][col]);
    Keyboard.press(profile_1[row][col]);}
  if(mode_switch == 1){
    Serial.println(profile_alt[row][col]);
    Keyboard.press(profile_alt[row][col]);}
  if(mode_switch == 2){
    Serial.println(profile_alt_2[row][col]);
    Keyboard.press(profile_alt_2[row][col]);}
  
  keyDown[row][col]++;

if(row == 0 & col == 1){F1 = 1;}
if(row == 0 & col == 2){F2 = 1;}
if(row == 0 & col == 3){F3 = 1;}
if(row == 0 & col == 4){F4 = 1;}
if(row == 0 & col == 4){F4 = 1;}
//if(row == 3 & col == 3){
//  M1 = 1;
//  Mouse.press(MOUSE_LEFT);}





}
          
void resetKey(int row, int col){ //resetting the variables after key is released

  keyDown[row][col] = 0;
  Keyboard.release(profile_1[row][col]);
  Keyboard.release(profile_alt[row][col]);
  Keyboard.release(profile_alt_2[row][col]);
    if(F1 >= 1){F1 = 0;}
    if(F2 >= 1){F2 = 0;}
    if(F3 >= 1){F3 = 0;}
    if(F4 >= 1){F4 = 0;}
//    if(row == 3 & col == 3){
//      M1 = 0;
//      Mouse.release(MOUSE_LEFT);}

}  
     
  
