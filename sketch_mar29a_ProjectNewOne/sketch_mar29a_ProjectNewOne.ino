#include <Adafruit_NeoPixel.h>
#define PIN 13
#define NUMPIXELS 6

Adafruit_NeoPixel pixels(NUMPIXELS, PIN);
void setup() {
  Serial.begin(9600);
  pixels.begin();
 
}

void loop() {
 
  int antennae = analogRead(A0);
  Serial.println(antennae);

  pixels.clear();
    

  if(antennae > 250)
  {
    Serial.println("RED");

    pixels.setPixelColor(0, pixels.Color(100, 0, 0)); 
  }
  else
  {
    Serial.println("GREEN");

    pixels.setPixelColor(0, pixels.Color(0, 100, 0)); 
  }

  pixels.show();

  // pixels.clear();
 
  // for(int i=0; i<NUMPIXELS; i++) { 
    
  //   //map<int, int> led_change;
  //   //led_change.insert({0, 255});
    
  //   //map<int, int> antennae_change;
  //   //antennae_change.insert({0,1026});
      
  //   pixels.show();   

  //   pixels.setPixelColor(i, pixels.Color(100, 0, 0));

  //   // if (led_change.insert < 500){
  //   //   pixels.setPixelColor(i, pixels.Color(100, 0, 0));

  //   // } else {
  //   //   pixels.setPixelColor(i, pixels.Color(0, 100, 0));
  //   // }

  //   delay(50); 
  // }  

  delay(100);

//if (antenna >= 1)
//{
  //antenna = map(antenna, 1, 100, 1, 255);
  //analogWrite(A0, antenna);

}


