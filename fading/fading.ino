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
int d0 = 100; //relative fade speed
int d2 = 1000; //time to pause on each color
static uint8_t hues[] = {ORANGE, BLUE, AQUA};

CRGB leds[NUM_LEDS];
static uint8_t hue;
static uint8_t value; // unsigned integer 0 - 255

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
}

void loop(){
  //fading
  static uint8_t hue1; 
  static uint8_t hue2;
  int i = 0;
  int n = sizeof(hues);

  while (true){
    hue1 = hues[i%n];
    hue2 = hues[(i+1)%n];
    i++;

    int d1 = d0 / (abs(hue2-hue1)); //modify delay such that transition time is same for any 2 colors
    
    if (hue2 > hue1){
       if (abs(hue2-hue1) <= 128){ //the colors do not need to wrap around 255-0
        while (hue1 != hue2){
          FastLED.showColor(CHSV(hue1++, 255, 255));
          delay(d1);
        }
        delay(d2);
       }
       else{ //colors need to wrap around
        while(hue1 != hue2){
          FastLED.showColor(CHSV(hue1--, 255, 255));
          if (hue1 == 0){
            hue1 = 255;      
          }
          delay(d1);
        }
        delay(d2);
       }
    }
  
      if (hue2 < hue1){
       if (abs(hue2-hue1) <= 128){ //the colors do not need to wrap around 255-0
        while (hue1 != hue2){
          FastLED.showColor(CHSV(hue1--, 255, 255));
          delay(d1);
        }
        delay(d2);
       }
       else{ //colors need to wrap around
        while(hue1 != hue2){
          FastLED.showColor(CHSV(hue1++, 255, 255));
          if (hue1 == 255){
            hue1 = 0;      
          }
          delay(d1);
        }
        delay(d2);
       }
    }
  }
}
