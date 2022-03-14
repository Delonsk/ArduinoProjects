#include <Adafruit_NeoPixel.h>

const int pot = A0;
const int ledPin = 3;

Adafruit_NeoPixel led = Adafruit_NeoPixel(4,ledPin,NEO_GRB + NEO_KHZ800);

int currentRedLed = 0;

unsigned long previousMillis = 0;
unsigned long currentMillis;

int interval = 500;

bool goForward = true;


void setup()
{
  pinMode(pot, INPUT);
  led.begin();
  
  for(int i = 0; i < 4; i++){
    if(i == 0){
      led.setPixelColor(i, 255, 0, 0);
      led.show();
    }
    else{
      led.setPixelColor(i, 0, 255, 0);
      led.show();
    }
  }
  
}

void loop()
{
  
 int potValue = analogRead(pot);
 
 interval = map(potValue, 0, 1023, 0, 2500);
  
 currentMillis = millis();
  
 if(currentMillis - previousMillis >= interval){
   
  previousMillis = currentMillis;
    
  if(currentRedLed < 3 && goForward){
  	currentRedLed++;
  }else if(currentRedLed > 0 && !goForward){
  	currentRedLed--;
  }
  
  for(int i = 0; i < 4; i++){
    if(i == currentRedLed){
    	led.setPixelColor(i, 255,0,0);
      	led.show();
    }else{
    	led.setPixelColor(i, 0,255,0);
      	led.show();
    }
  }
   if(currentRedLed == 3 && goForward){
   	goForward = !goForward;
   }else if(currentRedLed == 0 && !goForward){
    goForward = !goForward; 
   }      
 }
  
  
}