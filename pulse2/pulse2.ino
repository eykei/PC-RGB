#include <FastLED.h>
#include <string.h>

#define LED_PIN     7
#define NUM_LEDS    34
#define RED    0
#define ORANGE 32
#define YELLOW 64
#define GREEN 96
#define AQUA 128
#define BLUE 160
#define PURPLE 192
#define PINK 224

//setup 
int d1 = 150; // "beat" speed
int d2 = 4; // "fade" speed
static uint8_t hues[] = {RED, ORANGE, YELLOW, GREEN, AQUA, BLUE, PURPLE, PINK};

CRGB leds[NUM_LEDS];
static uint8_t hue;
static uint8_t value; // unsigned integer 0 - 255

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
}


void loop(){
  //pulse 2
  for (int i = 0; i < sizeof(hues); i++){
    hue = hues[i];
    value = 255;
    FastLED.showColor(CHSV(hue, 255, value));
    delay(d1); 
    FastLED.showColor(CHSV(hue, 255, 0));
    delay(d1 * 0.6);
    FastLED.showColor(CHSV(hue, 255, value));
    delay(d1);
    while (value > 1){
      FastLED.showColor(CHSV(hue, 255, --value));
      delay(d2); 
    }
  }
}
