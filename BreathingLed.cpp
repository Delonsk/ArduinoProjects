#include <Adafruit_NeoPixel.h>

const int pot = A0;
const int ledPin = 3;

const int perCycle = 1;

int ledOne = 255;
int ledTwo = 255;
int ledThree = 255;
int ledFour = 255;


Adafruit_NeoPixel led = Adafruit_NeoPixel(4,ledPin,NEO_GRB + NEO_KHZ800);


unsigned long previousMillis = 0;
unsigned long currentMillis;

int interval = 2000;

bool dim = false;

void setup()
{
  Serial.begin(9600);
  pinMode(pot, INPUT);
  led.begin();
  
  for(int i = 0; i < 4; i++){
    led.setPixelColor(i, 50,0,0);
    led.show();
  }
  
}

void loop()
{
  
 int potValue = analogRead(pot);
 
 interval = map(potValue, 0, 1023, 500, 4000);
 int cycle = interval/255;
 Serial.println(perCycle);
 currentMillis = millis();

 

 if(currentMillis - previousMillis >= cycle){
  
 previousMillis = currentMillis; 

if(dim){
 ledOne = ledOne - perCycle;
 ledTwo = ledTwo - perCycle;
 ledThree = ledThree - perCycle;
 ledFour = ledFour - perCycle;
}else if(!dim){
  ledOne = ledOne + perCycle;
  ledTwo = ledTwo + perCycle;
  ledThree = ledThree + perCycle;
  ledFour = ledFour + perCycle;
}

if(dim && ledOne <= 0){
  dim = false;
}else if(!dim && ledOne >= 255){
  dim = true;
}
  
 led.setPixelColor(0, ledOne, 0,0);
 led.setPixelColor(1, 0, ledTwo,0);
 led.setPixelColor(2, 0, 0,ledThree);
 led.setPixelColor(3, ledFour/2, 0,ledFour/2);

 led.show();

    
} 
}