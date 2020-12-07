#include <Adafruit_NeoPixel.h>

#define LED_PIN 6

#define LED_COUNT 300

#define MAX_BRIGHTNESS 20

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int red = 30;
int green = 0;
int blue = 30;
bool ascending = true;
int highlight = 0;
int offset = 0;

void setup(){
    Serial.begin(9600);

    strip.begin();
    strip.show();

    setStrip();

    strip.show();
}

void loop(){
    delay(10);
    if(highlight >= 299){
        ascending = false;
    }

    if(highlight <= 0){
        ascending = true;
    }

    if (ascending){
        highlight++;
    }else{
        highlight--;
    }

    setStrip();    
    strip.setPixelColor(highlight, 255, 255, 255);
    strip.show();
}

void setStrip(){
    int red = MAX_BRIGHTNESS;
    int green = 0;
    int blue = 0;

    if(offset <= 114){
        offset++;
    }else{
        offset = 0;
    }

    for(int i = offset - 114; i < LED_COUNT + 144; i++){
        
        if(red >= MAX_BRIGHTNESS){
            if(green < MAX_BRIGHTNESS && blue <= 0){                
                green++;
            }else{
                blue--;
            }
        }
        if(green >= MAX_BRIGHTNESS){
            if(blue < MAX_BRIGHTNESS && red <= 0){
                blue++;
            }else{
                red--;
            }
        }
        if(blue >= MAX_BRIGHTNESS){
            if(red < MAX_BRIGHTNESS && green <= 0){
                red++;
            }else{
                green--;
            }
        }

        if(i >= 0 && i < 300){
            strip.setPixelColor(i, red, green, blue);
        }
    }
}