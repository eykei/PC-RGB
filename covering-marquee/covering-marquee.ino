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
int d = 50; // speed
static uint8_t hues[] = {0, 10, 20, 30, 40}; //colors, up to 34

CRGB leds[NUM_LEDS];


void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
}

void loop(){
  //covering marquee
  int n = sizeof(hues);
  int m = NUM_LEDS / n;
  for (int x =0; x < NUM_LEDS; x++){
    for (int i = 0; i < n; i++){
      for (int j = i * m ; j < (i+1) * m; j++){
        leds[(j+x)%NUM_LEDS] = CHSV(hues[i], 255, 255);
      }
      FastLED.show();
      delay(d);
    }
  }
}
