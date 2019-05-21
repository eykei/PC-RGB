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
#define TEST 255, 0, 255

//setup
int d = 300; //speed
static uint8_t hues[] = {RED, GREEN}; //pick 2 colors
int u = 5; //unit size

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
}

void loop(){
  //alternating
  int count = 0;
  while (true){
    for (int i = 0; i < NUM_LEDS; i++){
      if (count%2 == 0){
        leds[i] = CHSV(hues[0], 255, 255);
        leds[i+u] = CHSV(hues[1], 255, 255);
      }
      else{
        leds[i] = CHSV(hues[1], 255, 255);
        leds[i+u] = CHSV(hues[0], 255, 255);
      }

      if (i%u == 0 && i>0){
       i+=u;
      }
      
    }
  FastLED.show();
  delay(d);
  count++;
  }
}
