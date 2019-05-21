#include <FastLED.h>
#include <string.h>
#define LED_PIN     7
#define NUM_LEDS    34

//setup
int d = 10; //speed

CRGB leds[NUM_LEDS];
static uint8_t hue = 0;

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
}

void loop(){
  //spectrum fade
  FastLED.showColor(CHSV(hue++, 255, 255)); 
  delay(d);
}
