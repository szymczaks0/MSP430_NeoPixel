/*
 * patterns.c
 *
 *  Created on: Dec 22, 2018
 *      Author: Steve
 */
#include <msp430.h>
#include "helpers.h"
#include "patterns.h"
#include <math.h>
#include <stdarg.h>
#include "ws2812.h"

static u_int green[3] = {0, 255, 0};  // green
static u_int blue[3] = {0, 0, 255};  // blue
static u_int magenta[3] = {255, 0, 255};  // magenta
static u_int yellow[3] = {255, 255, 0};  // yellow
static u_int cyan[3] = {0, 255, 255};  // cyan
static u_int red[3] = {255, 0, 0};  // red
static u_int white[3] = {255, 255, 255}; //white
static u_int off[3] = {0, 0, 0};

void gradualFill(u_int n, u_int r, u_int g, u_int b){
    char i;
    char count;
    for (i = 0; i < n; i++){        // n is number of LEDs
        setLEDColor(i, r, g, b);
        showStrip();
        for(count = 0; count < 250; count++){
        _delay_cycles(10000);       // lazy delay
        }
    }
}

void strobeAll(u_int period, u_int pattern[],u_int pattern_length) {
    char i;

    const char dcycleOn = period * 50;
    const char dcycleOff = period * 50;

    fillPattern(period,pattern,pattern_length);
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
void fadeAll(u_int period, u_int color1[3], u_int color2[3]){
        char i = 0;
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
void colorWheel(char period){
    fadeAll(period,green,cyan);
    fadeAll(period,cyan,blue);
    fadeAll(period,blue,magenta);
    fadeAll(period,magenta,red);
    fadeAll(period,red,yellow);
    fadeAll(period,yellow,green);
}

void breatheAll(u_int period, u_int color1[3], u_int color2[3]){
    fadeAll(period,color1,off);
    fadeAll(period,off,color2);
    fadeAll(period,color2,off);
    fadeAll(period,off,color1);

}
/*
void breatheAll(u_int period, u_int color1[3], u_int color2[3]){
    fadeAll(period,color1,off);
    fadeAll(period,off,color2);
    fadeAll(period,color2,off);
    fadeAll(period,off,color1);

}

 */
void setPattern2(u_int period, u_int color1[3], u_int color2[3]){
    char i = 0;
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

void fillPattern(u_int period, u_int pattern[], u_int pattern_length){
    int i = 0;
    int j = 0;
    int k = 0;
    u_int color[3];
    u_int *pattern_ptr;
    pattern_ptr = pattern;
    while(i < NUM_LEDS){
        for(j = 0; j < pattern_length; j++){
            for(k = 0; k < 3; k++){
                color[k]=*(pattern_ptr + j * pattern_length + k);
            }
            setLEDColor(i,color[0],color[1],color[2]);
            i++;
        }
    }
    showStrip();
    for (i = 0; i < period; i++){
        _delay_cycles(1000);
    }
}

void shift(char right, u_int period, u_int pattern[], u_int pattern_length){
    u_int i = 0;
    u_int j = 0;
    u_int k = 0;
    u_int x = 0;
    u_int temp = 0;
    u_int color[3];
    u_int *pattern_ptr;
    pattern_ptr = pattern;
    for(x = 0; x < pattern_length; x++){
        while(i < NUM_LEDS){
            for(j = 0; j < pattern_length - x; j++){
                for(k = 0; k < 3; k++){
                    temp = (j * pattern_length) + k + (x * 3); // + (x * 3);
                    color[k]=*(pattern_ptr + temp);
                }
                setLEDColor(i,color[0],color[1],color[2]);
                i++;
            }
            for(j = 0; j < x; j++){
                for(k = 0; k < 3; k++){
                    color[k]=*(pattern_ptr + k + 3 * j);
                }
                setLEDColor(i,color[0],color[1],color[2]);
                i++;
            }
        }
        showStrip();
        for (i = 0; i < (period * 50); i++){
            _delay_cycles(1000);
        }
        i = 0;
    }
}


