/*
 * patterns.h
 *
 *  Created on: Dec 22, 2018
 *      Author: Steve
 */

#ifndef PATTERNS_H_
#define PATTERNS_H_
#include "ws2812.h"

//Fills light strip from starting end (index 0) to last LED slow enough for the human eye to see.
void gradualFill(u_int n, u_int r, u_int g, u_int b);

//Strobe light effect that can have varying speed and colors needs to be in a loop to appear to strobe.
void strobeAll(u_int period, u_int pattern[],u_int pattern_length);

//Starts at color1 and "fades" to color2, speed is dependent on period.
void fadeAll(u_int period, u_int color1[3], u_int color2[3]);

//fades through all primary and secondary rgb colors, speed is dependent on period.
void colorWheel(char period);

//Decreases brightness of the given color1 until off, then increases brightness of color2.
void breatheAll(u_int period, u_int color1[3], u_int color2[3]);

//Potentially outdated, time spent in this function dependent on period.
void setPattern2(u_int period, u_int color1[3], u_int color2[3]);

//Takes an array pattern, in which each set of 3 indices contains r g and b values.
void fillPattern(u_int period, u_int pattern[], u_int pattern_length);

//Shift pattern right (right = 1) or left (right = 0), time spent in this function dependent on period.
void shift(char right, u_int period, u_int pattern[], u_int pattern_length);

#endif /* PATTERNS_H_ */
