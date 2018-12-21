#include <msp430.h> 
#include "ws2812.h"
#include <math.h>
#include <stdarg.h>
/**
 * main.c
 *  Created on: Dec 15, 2018
 *      Author: Stephen Szymczak
 *      GitHub credit: https://github.com/mjmeli/MSP430-NeoPixel-WS2812-Library/blob/master/example/main.c
 */
extern LED leds[NUM_LEDS] = { { 0, 0, 0 } };
const u_char green[3] = {0, 255, 0};  // green
const u_char blue[3] = {0, 0, 255};  // blue
const u_char magenta[3] = {255, 0, 255};  // magenta
const u_char yellow[3] = {255, 255, 0};  // yellow
const u_char cyan[3] = {0, 255, 255};  // cyan
const u_char red[3] = {255, 0, 0};  // red
const u_char white[3] = {255, 255, 255}; //white
const u_char off[3] = {0, 0, 0};

u_char color_now[3][100];

void gradualFill(u_int n, u_char r, u_char g, u_char b);
void strobeAll(int period, int dcycle, u_char color[3]);
void fadeAll(u_int period, u_char color1[3], u_char color2[3]);
void breatheAll(u_int period, u_char color1[3], u_char color2[3]);
void colorWheel(int period);
void setPattern2(u_int period, u_char color1[3], u_char color2[3]);


int main(void) {
    WDTCTL = WDTPW + WDTHOLD;  // Stop WDT
    if (CALBC1_16MHZ==255)    // If calibration constant erased
    {
        while(1);              // do not load, trap CPU!!
    }

    // configure clock to 16 MHz
    BCSCTL1 = CALBC1_16MHZ;    // DCO = 16 MHz
    DCOCTL = CALDCO_16MHZ;

    // initialize LED strip
    initStrip();  // ***** HAVE YOU SET YOUR NUM_LEDS DEFINE IN WS2812.H? ******

    while (1) {
        colorWheel(1);
        //setPattern2(5000,red,green);
        //setPattern2(5000,green,red);
        //breatheAll(100,magenta,cyan);
        //fadeAll(100,green,red);
        //fadeAll(100,red,green);
        //fadeall(100,red,off);
        //fadeall(100,off,green);
        //gradualFill(NUM_LEDS, 0, 255, 0);  // green
        //gradualFill(NUM_LEDS, 255, 0, 0);  // blue
        //strobeAll(5,50, white);
    }
}

void gradualFill(u_int n, u_char r, u_char g, u_char b){
    int i;
    int count;
    for (i = 0; i < n; i++){        // n is number of LEDs
        setLEDColor(i, r, g, b);
        showStrip();
        for(count = 0; count < 250; count++){
        _delay_cycles(10000);       // lazy delay
        }
    }
}
/*
gradualFill(NUM_LEDS, 0, 255, 0);  // green
gradualFill(NUM_LEDS, 0, 0, 255);  // blue
gradualFill(NUM_LEDS, 255, 0, 255);  // magenta
gradualFill(NUM_LEDS, 255, 255, 0);  // yellow
gradualFill(NUM_LEDS, 0, 255, 255);  // cyan
gradualFill(NUM_LEDS, 255, 0, 0);  // red
*/

void strobeAll(int period,int dcycle, u_char color[3]) {
    int i;

    const int dcycleOn = period * dcycle;
    const int dcycleOff = period * (100 - dcycle);

    fillStrip(color[0], color[1], color[2]);
    for (i = 0; i < dcycleOn; i++){
        _delay_cycles(1000);
    }
    i = 0;

    //showStrip();
    clearStrip();
    for (i = 0; i < dcycleOff; i++){
        _delay_cycles(1000);
    }
}
//color1 is 50 50 50. color 2 is 200 200 20
void fadeAll(u_int period, u_char color1[3], u_char color2[3]){
        int i = 0;
        float j = 0;
        float color_current[3];
        float slope[3];
        color_current[0] = color1[0];
        color_current[1] = color1[1];
        color_current[2] = color1[2];

        slope[0] = color2[0] - color1[0];
        slope[1] = color2[1] - color1[1];
        slope[2] = color2[2] - color1[2];

        while (j < 1){
            for (i = 0; i < 3; i++){
                    color_current[i] = color1[i] + round(slope[i]*j);
            }
            fillStrip(color_current[0], color_current[1], color_current[2]);
            for (i = 0; i < period; i++){
                _delay_cycles(1000);
            }
            j += 0.005;
        }
}
    //fillStrip(theColors[1][1], theColors[1][2], theColors[1][3]);
   // fillStrip(theColors[2][1], theColors[2][2], theColors[2][3]);
   // fillStrip(theColors[3][1], theColors[3][2], theColors[3][3]);

void colorWheel(int period){
    fadeAll(period,green,cyan);
    fadeAll(period,cyan,blue);
    fadeAll(period,blue,magenta);
    fadeAll(period,magenta,red);
    fadeAll(period,red,yellow);
    fadeAll(period,yellow,green);
}

void colorNow(void){
    int i = 0;
    for(i = 0; i < NUM_LEDS; i++){
       color_now[0][i] = leds[i].red;
       color_now[1][i] = leds[i].green;
       color_now[2][i] = leds[i].blue;
    }
}

void breatheAll(u_int period, u_char color1[3], u_char color2[3]){
    int i = 0;
    fadeAll(period,color1,off);
    fadeAll(period,off,color2);
    fadeAll(period,color2,off);
    fadeAll(period,off,color1);

}

void setPattern2(u_int period, u_char color1[3], u_char color2[3]){
    int i = 0;
    for(i = 0; i < NUM_LEDS; i++){
        setLEDColor(i, color1[0], color1[1], color1[2]);
        i++;
        setLEDColor(i, color2[0], color2[1], color2[2]);
    }
    showStrip();
    for (i = 0; i < period; i++){
        _delay_cycles(1000);
    }
}
