#include <Adafruit_NeoPixel.h>

const int pot = A0;
const int ledPin = 3;

Adafruit_NeoPixel led = Adafruit_NeoPixel(5,ledPin,NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(9600);
  pinMode(pot, INPUT);
  led.begin();
  
  for(int i = 0; i < 5; i++){
    if(i == 2){
      led.setPixelColor(i, 255,0,0);
      led.show();
    }else{
    led.setPixelColor(i, 0,255,0);
    led.show();
    }
  }
}

void loop()
{

  int potValue = analogRead(pot);
  int ledPlace = map(potValue, 0, 684, 0, 4);

  for(int i = 0; i < 5; i++){
    if(i == ledPlace){
      led.setPixelColor(i, 255,0,0);
      led.show();
    }else{
      led.setPixelColor(i, 0,255,0);
      led.show();
    }
  }

}