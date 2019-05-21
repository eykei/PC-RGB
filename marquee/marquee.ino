#include <FastLED.h>
#include <string.h>

#define LED_PIN 7
#define NUM_LEDS  34
#define RED 0
#define ORANGE  32
#define YELLOW  64
#define GREEN 96
#define AQUA 128
#define BLUE 160
#define PURPLE 192
#define PINK 224

//setup


CRGB leds[NUM_LEDS];
static uint8_t hues[] = {ORANGE, PURPLE}; // first color is background, second color is marquee
int u = 20; // length of marquee
int d = 50; //speed



void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
}



void loop(){
  //marquee
  for (int i = 0; i < NUM_LEDS; i++){
    for (int j = 0; j < NUM_LEDS; j++){
      leds[j] = CHSV(hues[0], 255, 255);
    }
    for (int k = 0; k < u; k++){
      leds[(i+k)%NUM_LEDS] = CHSV(hues[1], 255, 255);
    }
    FastLED.show();
    delay(d);
  }
}
