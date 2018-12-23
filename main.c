#include <msp430.h> 
#include "ws2812.h"
#include "helpers.h"
#include "patterns.h"
#include <math.h>
#include <stdarg.h>
/**
 * main.c
 *  Created on: Dec 15, 2018
 *      Author: Stephen Szymczak
 *      GitHub credit: https://github.com/mjmeli/MSP430-NeoPixel-WS2812-Library/blob/master/example/main.c
 */
static u_char green[3] = {0, 255, 0};  // green
static u_char blue[3] = {0, 0, 255};  // blue
static u_char magenta[3] = {255, 0, 255};  // magenta
static u_char yellow[3] = {255, 255, 0};  // yellow
static u_char cyan[3] = {0, 255, 255};  // cyan
static u_char red[3] = {255, 0, 0};  // red
static u_char white[3] = {255, 255, 255}; //white
static u_char off[3] = {0, 0, 0};

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
    /*u_char color_pattern[15];
    int i = 0;
    int j = 0;
    for(i = 0; i < 5; i++){
        for(j = 0; j < 3; j++){
            color_pattern[5 * i + j]= j * 84;
        }
    }*/
    u_char color_pattern[][3] = {
                         {0,255,0},
                         {0,0,255},
                         {255,255,0}
    };

    u_char pattern[] = makePattern(color_pattern,3);
    fillPattern(100,pattern,3);
    while (1) {
        //colorWheel(100);


        //makePattern(3,green,cyan,magenta);

        //setPattern2(5000,red,green);
        //setPattern2(5000,green,red);
        //breatheAll(15,magenta,cyan);
        //fadeAll(100,blue,magenta);
        //fadeAll(100,magenta,blue);
        //fadeall(100,red,off);
        //fadeall(100,off,green);
        //gradualFill(NUM_LEDS, 0, 255, 0);  // green
        //gradualFill(NUM_LEDS, 255, 0, 0);  // blue
        //strobeAll(14,50, red);
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


    //fillStrip(theColors[1][1], theColors[1][2], theColors[1][3]);
   // fillStrip(theColors[2][1], theColors[2][2], theColors[2][3]);
   // fillStrip(theColors[3][1], theColors[3][2], theColors[3][3]);






