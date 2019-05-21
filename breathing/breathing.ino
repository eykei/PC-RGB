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
int d1 = 5; //speed
static uint8_t hues[] = {RED, GREEN};

CRGB leds[NUM_LEDS];
static uint8_t hue; // unsigned integer 0 - 255
static uint8_t value; 

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
}

void loop(){
  //breathing
  for (int i = 0; i < sizeof(hues); i++){
    hue = hues[i];
    while (value  < 255) {
      FastLED.showColor(CHSV(hue, 255, value++));
      delay(d1); 
    }
    while (value > 0){
      FastLED.showColor(CHSV(hue, 255, value--));
      delay(d1); 
    }
    delay(50);
  }
}
