
#include <Adafruit_NeoPixel.h>

#define PIN        6 //strip

#define NUMPIXELS 100 // number of pixels

#define potentiometer A0

byte height = 0;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(19200);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

  pixels.clear();
  pixels.show();
}

void loop() {
  pixels.setBrightness((byte)((float)analogRead(potentiometer) / 4));
}

void serialEvent()
{
  pixels.clear();
  height = Serial.read();
  for(int i = 0; i < height; i++)
  {
    pixels.setPixelColor(i, pixels.Color(52,27,82));
  }
  pixels.show();
}
