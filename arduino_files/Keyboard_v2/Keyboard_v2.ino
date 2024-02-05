// Author: Alexander Nistor
#include <Keyboard.h>
#include <Adafruit_NeoPixel.h>

int LED_PIN = 12;
int NUM_PIXELS = 23;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);
int z = 0;
int q = 0;
int x = 0;
int y = 0;
int LED1, LED24 = 0;
int LED2 = 0;
int LED3 = 0;
int LED4 = 0;
int LED5 = 0;
int LED6 = 0;
int LED7 = 0;
int LED8 = 0;
int LED9 = 0;
int LED10 = 0;
int LED11 = 0;
int LED12 = 0;
int LED13 = 0;
int LED14 = 0;
int LED15 = 0;
int LED16 = 0;
int LED17 = 0;
int LED18 = 0;
int LED19 = 0;
int LED20 = 0;
int LED21 = 0;
int LED22 = 0;
int LED23 = 0;
//
  byte inputs[] = {7,6,5,4,3,2};          //declaring inputs and outputs
#define inCount sizeof(inputs)/sizeof(inputs[0])
byte outputs[] = {A0,A1,A2,8};
#define outCount sizeof(outputs)/sizeof(outputs[0])

char profile_1[4][6] = {               //layout grid for characters (profile 1)
     {177,'`','1','2','3','4'},  //pin A0
     {130,179,'q','w','e','r'},  //pin A1
     {128,193,'a','s','d','f'},  //pin A2
     {' ',129,'z','x','c','v'},  //pin 8
//pins 7,  6,  5,  4,  3,  2
}; 

char profile_2[4][6] = {               //layout grid for characters (profile 2)
     {177,'`','1','2','3','4'},  //pin A0
     {130,179,'q','w','e','r'},  //pin A1
     {128,193,'a','s','d','f'},  //pin A2
     {' ',129,'z','x','c','v'},  //pin 8
//pins 7,  6,  5,  4,  3,  2
}; 

char profile_3[4][6] = {               //layout grid for characters (profile 3)
     {177,'`','1','2','3','4'},  //pin A0
     {130,179,'q','w','e','r'},  //pin A1
     {128,193,'a','s','d','f'},  //pin A2
     {' ',129,'z','x','c','v'},  //pin 8
//pins 7,  6,  5,  4,  3,  2
}; 

int x_axis = analogRead(A5);
int y_axis = analogRead(A4);

//analog stick inputs (profile 1)
int x_low_1 = 'd';  //right on stick
int x_high_1 = 'a'; //left on stick 
int y_low_1 = 'w';  //up on stick
int y_high_1 = 's'; //down on stick

//analog stick inputs (profile 2)
int x_low_2 = '2';  //right on stick
int x_high_2 = '4'; //left on stick 
int y_low_2 = '1';  //up on stick
int y_high_2 = '3'; //down on stick

//analog stick inputs (profile 3)
int x_low_3 = '6';  //right on stick
int x_high_3 = '8'; //left on stick 
int y_low_3 = '5';  //up on stick
int y_high_3 = '7'; //down on stick

int x_low_counter = 0;
int x_high_counter = 0;
int y_low_counter = 0;
int y_high_counter = 0;
              
int keyDown[outCount][inCount];
int profileSwitch = 1;
int colorSwitch = 1;

void setup(){                 
  
  for(int i=0; i<outCount; i++){    //declaring all the outputs and setting them high
    pinMode(outputs[i],OUTPUT);
    digitalWrite(outputs[i],HIGH);
  }
  for(int i=0; i<inCount; i++){     //declaring all the inputs and activating the internal pullup resistor
    pinMode(inputs[i],INPUT_PULLUP);
  }

 pinMode(A3,INPUT);
 pinMode(A4,INPUT);
 pinMode(A5,INPUT);

  Serial.begin(9600);               //establishing Serial link and initializing keyboard
  Serial.println("Connected");
  Keyboard.begin();

  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(13,INPUT);
  
}

//Main loop going through all the keys, then waiting 0.5ms
void loop() {

x ++;
y = .125 * x;
int r = 128 * sin(y/20) +128;
int g = 128 * sin(y/20 + 2) +128;
int b = 128 * sin(y/20 + 4) +128;

  if (colorSwitch == 1){pixels.setPixelColor(z, pixels.Color(255,0,0));}
  if (colorSwitch == 2){pixels.setPixelColor(z, pixels.Color(255,255,0));}
  if (colorSwitch == 3){pixels.setPixelColor(z, pixels.Color(0,255,0));} 
  if (colorSwitch == 4){pixels.setPixelColor(z, pixels.Color(0,255,255));}
  if (colorSwitch == 5){pixels.setPixelColor(z, pixels.Color(0,0,255));}
  if (colorSwitch == 6){pixels.setPixelColor(z, pixels.Color(255,0,255));}
  if (colorSwitch == 7){pixels.setPixelColor(z, pixels.Color(r,g,b));}
  if (colorSwitch == 8){
    if (LED1 > 0){LED1 --;}
    if (LED2 > 0){LED2 --;}
    if (LED3 > 0){LED3 --;}
    if (LED4 > 0){LED4 --;}
    if (LED5 > 0){LED5 --;}
    if (LED6 > 0){LED6 --;}
    if (LED7 > 0){LED7 --;}
    if (LED8 > 0){LED8 --;}
    if (LED9 > 0){LED9 --;}
    if (LED10 > 0){LED10 --;}
    if (LED11 > 0){LED11 --;}
    if (LED12 > 0){LED12 --;}
    if (LED13 > 0){LED13 --;}
    if (LED14 > 0){LED14 --;}
    if (LED15 > 0){LED15 --;}
    if (LED16 > 0){LED16 --;}
    if (LED17 > 0){LED17 --;}
    if (LED18 > 0){LED18 --;}
    if (LED19 > 0){LED19 --;}
    if (LED20 > 0){LED20 --;}
    if (LED21 > 0){LED21 --;}
    if (LED22 > 0){LED22 --;}
    if (LED23 > 0){LED23 --;}
    pixels.setPixelColor(0, pixels.Color(LED1, LED1, LED1));
    pixels.setPixelColor(1, pixels.Color(LED2, LED2, LED2));
    pixels.setPixelColor(2, pixels.Color(LED3, LED3, LED3));
    pixels.setPixelColor(3, pixels.Color(LED4, LED4, LED4));
    pixels.setPixelColor(4, pixels.Color(LED5, LED5, LED5));
    pixels.setPixelColor(5, pixels.Color(LED6, LED6, LED6));
    pixels.setPixelColor(6, pixels.Color(LED7, LED7, LED7));
    pixels.setPixelColor(7, pixels.Color(LED8, LED8, LED8));
    pixels.setPixelColor(8, pixels.Color(LED9, LED9, LED9));
    pixels.setPixelColor(9, pixels.Color(LED10, LED10, LED10));
    pixels.setPixelColor(10, pixels.Color(LED11, LED11, LED11));
    pixels.setPixelColor(11, pixels.Color(LED12, LED12, LED12));
    pixels.setPixelColor(12, pixels.Color(LED13, LED13, LED13));
    pixels.setPixelColor(13, pixels.Color(LED14, LED14, LED14));
    pixels.setPixelColor(14, pixels.Color(LED15, LED15, LED15));
    pixels.setPixelColor(15, pixels.Color(LED16, LED16, LED16));
    pixels.setPixelColor(16, pixels.Color(LED17, LED17, LED17));
    pixels.setPixelColor(17, pixels.Color(LED18, LED18, LED18));
    pixels.setPixelColor(18, pixels.Color(LED19, LED19, LED19));
    pixels.setPixelColor(19, pixels.Color(LED20, LED20, LED20));
    pixels.setPixelColor(20, pixels.Color(LED21, LED21, LED21));
    pixels.setPixelColor(21, pixels.Color(LED22, LED22, LED22));
    pixels.setPixelColor(22, pixels.Color(LED23, LED23, LED23));    
  }
  pixels.show();
if (z == 23){z = 0;}
z ++;
q --;



if (digitalRead(A3) == HIGH){
  profileSwitch++;
    if (profileSwitch == 4){
      profileSwitch = 1;
    }
}// detects profile button being pressed and changes profile when pressed

if (digitalRead(13) == HIGH){
  colorSwitch++;
    if (colorSwitch == 9){
      colorSwitch = 1;
    }
}


if (profileSwitch == 1){
  analogWrite(9,255);
  analogWrite(10,0);
  analogWrite(11,0);
  if (x_axis<384){
    Keyboard.press(x_low_1);
    x_low_counter ++;
  }else{
    if (x_low_counter > 0){
      Keyboard.release(x_low_1);
      x_low_counter = 0;
  }}if (x_axis>640){
    Keyboard.press(x_high_1);
    x_high_counter ++;
  }else{
    if (x_high_counter > 0){
      Keyboard.release(x_high_1);
      x_high_counter = 0;  
  }}if (y_axis<384){
    Keyboard.press(y_low_1);
    y_low_counter ++;
  }else{
    if (y_low_counter > 0){
      Keyboard.release(y_low_1);
      y_low_counter = 0;
  }}if (y_axis>640){
    Keyboard.press(y_high_1);
    y_high_counter ++;
  }else{
    if (y_high_counter > 0){
      Keyboard.release(y_high_1);
      y_high_counter = 0;  
  }
  }
  }
  if (profileSwitch == 2){
  analogWrite(9,0);
  analogWrite(10,255);
  analogWrite(11,0);
  if (x_axis<384){
    Keyboard.press(x_low_2);
    x_low_counter ++;
  }else{
    if (x_low_counter > 0){
      Keyboard.release(x_low_2);
      x_low_counter = 0;
  }}if (x_axis>640){
    Keyboard.press(x_high_2);
    x_high_counter ++;
  }else{
    if (x_high_counter > 0){
      Keyboard.release(x_high_2);
      x_high_counter = 0;  
  }}if (y_axis<384){
    Keyboard.press(y_low_2);
    y_low_counter ++;
  }else{
    if (y_low_counter > 0){
      Keyboard.release(y_low_2);
      y_low_counter = 0;
  }}if (y_axis>640){
    Keyboard.press(y_high_2);
    y_high_counter ++;
  }else{
    if (y_high_counter > 0){
      Keyboard.release(y_high_2);
      y_high_counter = 0;  
  }
  }
  }
  if (profileSwitch == 3){
  analogWrite(9,0);
  analogWrite(10,0);
  analogWrite(11,255);
  if (x_axis<384){
    Keyboard.press(x_low_3);
    x_low_counter ++;
  }else{
    if (x_low_counter > 0){
      Keyboard.release(x_low_3);
      x_low_counter = 0;
  }}if (x_axis>640){
    Keyboard.press(x_high_3);
    x_high_counter ++;
  }else{
    if (x_high_counter > 0){
      Keyboard.release(x_high_3);
      x_high_counter = 0;  
  }}if (y_axis<384){
    Keyboard.press(y_low_3);
    y_low_counter ++;
  }else{
    if (y_low_counter > 0){
      Keyboard.release(y_low_3);
      y_low_counter = 0;
  }}if (y_axis>640){
    Keyboard.press(y_high_3);
    y_high_counter ++;
  }else{
    if (y_high_counter > 0){
      Keyboard.release(y_high_3);
      y_high_counter = 0;  
  }
  }
  }

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

  if (profileSwitch == 1){
  Serial.print("Output: "); 
  Serial.print(row);
  Serial.print(" Input: ");
  Serial.print(col);
  Serial.print(" ");
  Serial.println(profile_1[row][col]);

   if(keyDown[row][col]){ 
  Keyboard.press(profile_1[row][col]);
  }
  keyDown[row][col]++;
}  

if (profileSwitch == 2){
  Serial.print("Output: "); 
  Serial.print(row);
  Serial.print(" Input: ");
  Serial.print(col);
  Serial.print(" ");
  Serial.println(profile_2[row][col]);

   if(keyDown[row][col]){ 
  Keyboard.press(profile_2[row][col]);
  }
  keyDown[row][col]++;
}  

if (profileSwitch == 3){
  Serial.print("Output: "); 
  Serial.print(row);
  Serial.print(" Input: ");
  Serial.print(col);
  Serial.print(" ");
  Serial.println(profile_3[row][col]);

   if(keyDown[row][col]){ 
  Keyboard.press(profile_3[row][col]);
  }
  keyDown[row][col]++;
}  

if (profileSwitch == 1){
  if (x_axis<384){
    Keyboard.press(x_low_1);
    x_low_counter ++;
  }else{
    if (x_low_counter > 0){
      Keyboard.release(x_low_1);
      x_low_counter = 0;
  }}if (x_axis>640){
    Keyboard.press(x_high_1);
    x_high_counter ++;
  }else{
    if (x_high_counter > 0){
      Keyboard.release(x_high_1);
      x_high_counter = 0;  
  }}if (y_axis<384){
    Keyboard.press(y_low_1);
    y_low_counter ++;
  }else{
    if (y_low_counter > 0){
      Keyboard.release(y_low_1);
      y_low_counter = 0;
  }}if (y_axis>640){
    Keyboard.press(y_high_1);
    y_high_counter ++;
  }else{
    if (y_high_counter > 0){
      Keyboard.release(y_high_1);
      y_high_counter = 0;  
  }
  }
  }
  if (profileSwitch == 2){
  if (x_axis<384){
    Keyboard.press(x_low_2);
    x_low_counter ++;
  }else{
    if (x_low_counter > 0){
      Keyboard.release(x_low_2);
      x_low_counter = 0;
  }}if (x_axis>640){
    Keyboard.press(x_high_2);
    x_high_counter ++;
  }else{
    if (x_high_counter > 0){
      Keyboard.release(x_high_2);
      x_high_counter = 0;  
  }}if (y_axis<384){
    Keyboard.press(y_low_2);
    y_low_counter ++;
  }else{
    if (y_low_counter > 0){
      Keyboard.release(y_low_2);
      y_low_counter = 0;
  }}if (y_axis>640){
    Keyboard.press(y_high_2);
    y_high_counter ++;
  }else{
    if (y_high_counter > 0){
      Keyboard.release(y_high_2);
      y_high_counter = 0;  
  }
  }
  }
  if (profileSwitch == 3){
  if (x_axis<384){
    Keyboard.press(x_low_3);
    x_low_counter ++;
  }else{
    if (x_low_counter > 0){
      Keyboard.release(x_low_3);
      x_low_counter = 0;
  }}if (x_axis>640){
    Keyboard.press(x_high_3);
    x_high_counter ++;
  }else{
    if (x_high_counter > 0){
      Keyboard.release(x_high_3);
      x_high_counter = 0;  
  }}if (y_axis<384){
    Keyboard.press(y_low_3);
    y_low_counter ++;
  }else{
    if (y_low_counter > 0){
      Keyboard.release(y_low_3);
      y_low_counter = 0;
  }}if (y_axis>640){
    Keyboard.press(y_high_3);
    y_high_counter ++;
  }else{
    if (y_high_counter > 0){
      Keyboard.release(y_high_3);
      y_high_counter = 0;  
  }
  }
  }

if (colorSwitch == 8){
  if (row == 2 & col == 0){
    pixels.setPixelColor(0, pixels.Color(255,255,255));
    LED1 = 255;
    }
  if (row == 3 & col == 1){
    pixels.setPixelColor(1, pixels.Color(255,255,255));
    LED2 = 255;
    }
  if (row == 2 & col == 1){
    pixels.setPixelColor(2, pixels.Color(255,255,255));
    LED3 = 255;
    }
  if (row == 1 & col == 1){
    pixels.setPixelColor(3, pixels.Color(255,255,255));
    LED4 = 255;
    }
  if (row == 0 & col == 1){
    pixels.setPixelColor(4, pixels.Color(255,255,255));
    LED5 = 255;
    }
  if (row == 0 & col == 0){
    pixels.setPixelColor(5, pixels.Color(255,255,255));
    LED6 = 255;
    }
  if (row == 0 & col == 2){
    pixels.setPixelColor(6, pixels.Color(255,255,255));
    LED7 = 255;
    }
  if (row == 1 & col == 2){
    pixels.setPixelColor(7, pixels.Color(255,255,255));
    LED8 = 255;
    }
  if (row == 2 & col == 2){
    pixels.setPixelColor(8, pixels.Color(255,255,255));
    LED9 = 255;
    }
  if (row == 3 & col == 2){
    pixels.setPixelColor(9, pixels.Color(255,255,255));
    LED10 = 255;
    }
  if (row == 3 & col == 3){
    pixels.setPixelColor(10, pixels.Color(255,255,255));
    LED11 = 255;
    }
  if (row == 2 & col == 3){
    pixels.setPixelColor(11, pixels.Color(255,255,255));
    LED12 = 255;
    }
  if (row == 1 & col == 3){
    pixels.setPixelColor(12, pixels.Color(255,255,255));
    LED13 = 255;
    }
  if (row == 0 & col == 3){
    pixels.setPixelColor(13, pixels.Color(255,255,255));
    LED14 = 255;
    }
  if (row == 0 & col == 4){
    pixels.setPixelColor(14, pixels.Color(255,255,255));
    LED15 = 255;
    }
  if (row == 1 & col == 4){
    pixels.setPixelColor(15, pixels.Color(255,255,255));
    LED16 = 255;
    }
  if (row == 2 & col == 4){
    pixels.setPixelColor(16, pixels.Color(255,255,255));
    LED17 = 255;
    }
  if (row == 3 & col == 4){
    pixels.setPixelColor(17, pixels.Color(255,255,255));
    LED18 = 255;
    }
  if (row == 3 & col == 0){
    pixels.setPixelColor(18, pixels.Color(255,255,255));
    LED19 = 255;
    }
  if (row == 3 & col == 5){
    pixels.setPixelColor(19, pixels.Color(255,255,255));
    LED20 = 255;
    }
  if (row == 2 & col == 5){
    pixels.setPixelColor(20, pixels.Color(255,255,255));
    LED21 = 255;
    }
  if (row == 1 & col == 5){
    pixels.setPixelColor(21, pixels.Color(255,255,255));
    LED22 = 255;
    }
  if (row == 0 & col == 5){
    pixels.setPixelColor(22, pixels.Color(255,255,255));
    LED23 = 255;
    }
}  
}  
void resetKey(int row, int col){ //resetting the variables after key is released

  if (profileSwitch == 1){
  keyDown[row][col] = 0;
  Keyboard.release(profile_1[row][col]);
} 

if (profileSwitch == 2){
  keyDown[row][col] = 0;
  Keyboard.release(profile_2[row][col]);
} 

if (profileSwitch == 3){
  keyDown[row][col] = 0;
  Keyboard.release(profile_3[row][col]);
} 

if (profileSwitch == 1){
  if (x_axis<384){
    Keyboard.press(x_low_1);
    x_low_counter ++;
  }else{
    if (x_low_counter > 0){
      Keyboard.release(x_low_1);
      x_low_counter = 0;
  }}if (x_axis>640){
    Keyboard.press(x_high_1);
    x_high_counter ++;
  }else{
    if (x_high_counter > 0){
      Keyboard.release(x_high_1);
      x_high_counter = 0;  
  }}if (y_axis<384){
    Keyboard.press(y_low_1);
    y_low_counter ++;
  }else{
    if (y_low_counter > 0){
      Keyboard.release(y_low_1);
      y_low_counter = 0;
  }}if (y_axis>640){
    Keyboard.press(y_high_1);
    y_high_counter ++;
  }else{
    if (y_high_counter > 0){
      Keyboard.release(y_high_1);
      y_high_counter = 0;  
  }
  }
  }
  if (profileSwitch == 2){
  if (x_axis<384){
    Keyboard.press(x_low_2);
    x_low_counter ++;
  }else{
    if (x_low_counter > 0){
      Keyboard.release(x_low_2);
      x_low_counter = 0;
  }}if (x_axis>640){
    Keyboard.press(x_high_2);
    x_high_counter ++;
  }else{
    if (x_high_counter > 0){
      Keyboard.release(x_high_2);
      x_high_counter = 0;  
  }}if (y_axis<384){
    Keyboard.press(y_low_2);
    y_low_counter ++;
  }else{
    if (y_low_counter > 0){
      Keyboard.release(y_low_2);
      y_low_counter = 0;
  }}if (y_axis>640){
    Keyboard.press(y_high_2);
    y_high_counter ++;
  }else{
    if (y_high_counter > 0){
      Keyboard.release(y_high_2);
      y_high_counter = 0;  
  }
  }
  }
  if (profileSwitch == 3){
  if (x_axis<384){
    Keyboard.press(x_low_3);
    x_low_counter ++;
  }else{
    if (x_low_counter > 0){
      Keyboard.release(x_low_3);
      x_low_counter = 0;
  }}if (x_axis>640){
    Keyboard.press(x_high_3);
    x_high_counter ++;
  }else{
    if (x_high_counter > 0){
      Keyboard.release(x_high_3);
      x_high_counter = 0;  
  }}if (y_axis<384){
    Keyboard.press(y_low_3);
    y_low_counter ++;
  }else{
    if (y_low_counter > 0){
      Keyboard.release(y_low_3);
      y_low_counter = 0;
  }}if (y_axis>640){
    Keyboard.press(y_high_3);
    y_high_counter ++;
  }else{
    if (y_high_counter > 0){
      Keyboard.release(y_high_3);
      y_high_counter = 0;  
  }
  }
  }
q = 255;
} 
     
  
