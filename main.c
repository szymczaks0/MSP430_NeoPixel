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

static u_int green[3] = {0, 255, 0};  // green
static u_int blue[3] = {0, 0, 255};  // blue
static u_int magenta[3] = {255, 0, 255};  // magenta
static u_int yellow[3] = {255, 255, 0};  // yellow
static u_int cyan[3] = {0, 255, 255};  // cyan
static u_int red[3] = {255, 0, 0};  // red
static u_int white[3] = {255, 255, 255}; //white
static u_int off[3] = {0, 0, 0};

char main(void) {
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
    /*u_int color_pattern[15];
    char i = 0;
    char j = 0;
    for(i = 0; i < 5; i++){
        for(j = 0; j < 3; j++){
            color_pattern[5 * i + j]= j * 84;
        }
    }*/
    u_int color_pattern1[][3] = {
                                  {255,255,0},
                                  {0,255,255},
                                  {255,0,255}
    };
    u_int *pattern1_ptr;
    pattern1_ptr = makePattern(color_pattern1,3);
    //fillPattern(10,pattern1,3);

    while (1) {
        //colorWheel(100);
        //shift(1,50,pattern1,3);
        shift(1,50,pattern1_ptr,3);
        //fillPattern(10,pattern1_ptr,3);
        pattern1_ptr = makePattern(color_pattern1,3);
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






