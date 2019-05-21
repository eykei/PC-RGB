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
static uint8_t hue = 0; // unsigned integer 0 - 255
static uint8_t saturation = 0; //white color
static uint8_t value = 255; 


CRGB leds[NUM_LEDS];


void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
}

void loop(){
  //static
  FastLED.showColor(CHSV(hue, saturation, value));
}
