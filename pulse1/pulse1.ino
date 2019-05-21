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
static uint8_t hues[] = {RED, ORANGE, YELLOW, GREEN, AQUA, BLUE, PURPLE, PINK};
int d = 5; //delay


CRGB leds[NUM_LEDS];
static uint8_t value; // unsigned integer 0 - 255

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
}

void loop(){
  //pulse
  for (int i = 0; i < sizeof(hues); i++){
    value = 255;
    while (value > 1){
      FastLED.showColor(CHSV(hues[i], 255, --value));
      delay(3); 
    }
  }
}
 
