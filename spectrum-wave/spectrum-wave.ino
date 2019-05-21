#include <FastLED.h>
#include <string.h>

#define LED_PIN     7
#define NUM_LEDS    34


CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
}

void loop(){
  //spectrum wave
  for (int i = 0; i < NUM_LEDS; i++){
    for (int j = 0; j < NUM_LEDS; j++){
      leds[(j+i) % NUM_LEDS] = CHSV(j* (255 / NUM_LEDS), 255, 255);
      FastLED.show();
    }
    delay(1);
  }
}
