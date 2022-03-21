#include <Adafruit_NeoPixel.h>

const int pot = A0;
const int ledPin = 3;

const int perCycle = 1;

int ledBrightness = 255;

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
 ledBrightness = ledBrightness - perCycle;
}else if(!dim){
  ledBrightness = ledBrightness + perCycle;
}

if(dim && ledBrightness <= 0){
  dim = false;
}else if(!dim && ledBrightness >= 255){
  dim = true;
}
  
 led.setPixelColor(0, ledBrightness, 0,0);
 led.setPixelColor(1, 0, ledBrightness,0);
 led.setPixelColor(2, 0, 0,ledBrightness);
 led.setPixelColor(3, ledBrightness/2, 0,ledBrightness/2);

 led.show();

} 
}