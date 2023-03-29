#include <Adafruit_NeoPixel.h>
#define PIN 13
#define NUM_LEDS 6

Adafruit_NeoPixel strip(NUM_LEDS, PIN);

void setup() {
  Serial.begin(9600);

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
 
  int value = analogRead(A0);
  Serial.println(value);

  int colorValue = map(value, 0, 1024, 0, 255);
  int color = strip.Color(colorValue*2, 255-colorValue*2, 0);

  delay(100);

  //strip.setPixelColor(0, color);

  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, color);
  }

  strip.show();

  delay(100);

}


