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
  Serial.begin(9600);

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

  Serial.print("Port '");
  Serial.print(port);
  Serial.print("' ");

  Serial.print("value '");
  Serial.print(value);
  Serial.print("' ");

  Serial.println("");

  int colorValue = map(value, 0, 1024, 0, 255);
  return colorValue;
}

void loop() {
 
  int value_strip_0 = readPortGetColorValue(A0);
  int color_strip_0 = strip_0.Color(value_strip_0*2, 255-value_strip_0*2, 0);
  for (int i = 0; i < NUM_LEDS; i++) {
    strip_0.setPixelColor(i, color_strip_0);
  }

  int value_strip_1 = readPortGetColorValue(A1);
  int color_strip_1 = strip_0.Color(value_strip_1*2, 255-value_strip_0*1, 0);
  for (int i = 0; i < NUM_LEDS; i++) {
    strip_1.setPixelColor(i, color_strip_1);
  }

  int value_strip_2 = readPortGetColorValue(A2);
  int color_strip_2 = strip_0.Color(value_strip_1*2, 255-value_strip_0*1, 0);
  for (int i = 0; i < NUM_LEDS; i++) {
    strip_2.setPixelColor(i, color_strip_2);
  }

  int value_strip_3 = readPortGetColorValue(A3);
  int color_strip_3 = strip_0.Color(value_strip_1*2, 255-value_strip_0*1, 0);
  for (int i = 0; i < NUM_LEDS; i++) {
    strip_3.setPixelColor(i, color_strip_3);
  }


  strip_0.show();
  strip_1.show();
  strip_2.show();
  strip_3.show();

  delay(500);

}


