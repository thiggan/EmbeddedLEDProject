#include <Adafruit_NeoPixel.h>

#define PIN_STRIP_0 10
#define PIN_STRIP_1 11
#define PIN_STRIP_2 12
#define PIN_STRIP_3 13

#define NUM_LEDS 6

// todo : figure out how to put these in an array
Adafruit_NeoPixel strip_0(NUM_LEDS, PIN_STRIP_0);
Adafruit_NeoPixel strip_1(NUM_LEDS, PIN_STRIP_1);
Adafruit_NeoPixel strip_2(NUM_LEDS, PIN_STRIP_2);
Adafruit_NeoPixel strip_3(NUM_LEDS, PIN_STRIP_3);

void setup() {
  Serial.begin(31250);

  strip_0.begin();
  strip_0.show(); 

  strip_1.begin();
  strip_1.show(); 

  strip_2.begin();
  strip_2.show(); 

  strip_3.begin();
  strip_3.show(); 
}

int readPortGetColorValue(int port)
{
  int value = analogRead(port);

  // Serial.print("readPortGetColorValue ");
  // Serial.print("Port '");
  // Serial.print(port);
  // Serial.print("' ");

  // Serial.print("value '");
  // Serial.print(value);
  // Serial.print("' ");

  // Serial.println("");

  return value;
}

int ledLights(int number){
  int numLeds = 0;

  if(number > 201 && number < 340){
    numLeds = 1;
  }
  else if(number > 341 && number < 480){
    numLeds = 2;
  }
  else if(number > 481 && number < 620){
    numLeds = 3;
  }
  else if( number > 621 && number < 750){
    numLeds = 4;
  }
  else if(number > 751 && number < 890){
    numLeds = 5;
  }
  else if(number > 891){
    numLeds = 6;
  }

  // Serial.print("ledLights ");
  // Serial.print("numLeds '");
  // Serial.print(numLeds);
  // Serial.print("' ");

  // Serial.println("");

  return numLeds;
}

void loop() {

  int value_strip_0 = readPortGetColorValue(A0);
  int leds_strip_0 = ledLights(value_strip_0);
  for (int i = 0; i < NUM_LEDS; i++) {
    if(i <= leds_strip_0)
    {
      strip_0.setPixelColor(i, strip_0.Color(100, 0, 0));
    }
    else
    {
      strip_0.setPixelColor(i, strip_0.Color(100, 0, 100));
    }
  }

  int value_strip_1 = readPortGetColorValue(A1);
  int leds_strip_1 = ledLights(value_strip_1);
  for (int i = 0; i < NUM_LEDS; i++) {
    if(i <= leds_strip_1)
    {
      strip_1.setPixelColor(i, strip_1.Color(100, 0, 0));
    }
    else
    {
      strip_1.setPixelColor(i, strip_1.Color(100, 0, 100));
    }
  }

  int value_strip_2 = readPortGetColorValue(A2);
  int leds_strip_2 = ledLights(value_strip_2);
  for (int i = 0; i < NUM_LEDS; i++) {
    if(i <= leds_strip_2)
    {
      strip_2.setPixelColor(i, strip_2.Color(100, 0, 0));
    }
    else
    {
      strip_2.setPixelColor(i, strip_2.Color(100, 0, 100));
    }
  }

  int value_strip_3 = readPortGetColorValue(A3);
  int leds_strip_3 = ledLights(value_strip_3);
  for (int i = 0; i < NUM_LEDS; i++) {
    if(i <= leds_strip_3)
    {
      strip_3.setPixelColor(i, strip_3.Color(100, 0, 0));
    }
    else
    {
      strip_3.setPixelColor(i, strip_3.Color(100, 0, 100));
    }
  }

  strip_0.show();
  strip_1.show();
  strip_2.show();
  strip_3.show();

  delay(50);

}


