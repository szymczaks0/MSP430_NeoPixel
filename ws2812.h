/*
 * ws2812.h
 *
 *  Created on: Dec 15, 2018
 *      Author: https://github.com/mjmeli/MSP430-NeoPixel-WS2812-Library/blob/master/ws2812.h
 *      Edited by: Stephen Szymczak
 */

// Configuration - SET THESE!
// Configuration - SET THESE!
#ifndef WS2812_H_
#define WS2812_H_
#define OUTPUT_PIN  (0x80)  // Set to whatever UCB0SIMO is on your processor (Px.7 here)
#define NUM_LEDS    (100)    // NUMBER OF LEDS IN YOUR STRIP

// Useful typedefs
typedef unsigned char u_char;   // 8 bit
typedef unsigned int u_int;     // 16 bit

// Transmit codes
#define HIGH_CODE   (0xF0)      // b11110000
#define LOW_CODE    (0xC0)      // b11000000

typedef struct {
    u_char green;
    u_char red;
    u_char blue;
} LED;
// Configure processor to output to data strip
void initStrip(void);

// Send colors to the strip and show them. Disables interrupts while processing.
void showStrip(void);

// Set the color of a certain LED
void setLEDColor(u_int p, u_char r, u_char g, u_char b);

// Clear the color of all LEDs (make them black/off)
void clearStrip(void);

// Fill the strip with a solid color. This will update the strip.
void fillStrip(u_char r, u_char g, u_char b);
#endif /* WS2812_H_ */
