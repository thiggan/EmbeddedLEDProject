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

  // strip_1.begin();
  // strip_1.show(); 

  // strip_2.begin();
  // strip_2.show(); 

  //  strip_3.begin();
  //  strip_3.show(); 
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

  Serial.print("ledLights ");
  Serial.print("numLeds '");
  Serial.print(numLeds);
  Serial.print("' ");

  Serial.println("");

  return numLeds;
}

void loop() {

  int value_strip_0 = readPortGetColorValue(A0);
  int leds = ledLights(value_strip_0);
  for (int i = 0; i < NUM_LEDS; i++) {
    if(i <= leds)
    {
      strip_0.setPixelColor(i, strip_0.Color(75, 0, 0));
    }
    else
    {
      strip_0.setPixelColor(i, strip_0.Color(0, 75, 0));
    }
  }

  // strip_0.setPixelColor(0, strip_0.Color(255, 0, 0)); // red
  // strip_0.setPixelColor(1, strip_0.Color(0, 255, 0)); // green
  // strip_0.setPixelColor(2, strip_0.Color(0, 0, 255)); // blue

  // int value_strip_1 = readPortGetColorValue(A1);
  // int color_strip_1 = strip_0.Color(value_strip_1*2, 255-value_strip_1*1, 0);
  // for (int i = 0; i < NUM_LEDS; i++) {
  //   strip_1.setPixelColor(i, color_strip_1);
  // }

  // int value_strip_2 = readPortGetColorValue(A2);
  // int color_strip_2 = strip_0.Color(value_strip_2*2, 255-value_strip_2*1, 0);
  // for (int i = 0; i < NUM_LEDS; i++) {
  //   strip_2.setPixelColor(i, color_strip_2);
  // }

  // int value_strip_3 = readPortGetColorValue(A3);
  // int color_strip_3 = strip_0.Color(value_strip_3*2, 255-value_strip_3*1, 0);
  // for (int i = 0; i < NUM_LEDS; i++) {
  //   strip_3.setPixelColor(i, color_strip_3);
  // }


  strip_0.show();
  //strip_1.show();
  //strip_2.show();
  //strip_3.show();

  delay(50);

}


