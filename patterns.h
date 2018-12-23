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
void gradualFill(u_int n, u_char r, u_char g, u_char b);

//Strobe light effect that can have varying speed and colors needs to be in a loop to appear to strobe.
void strobeAll(int period,int dcycle, u_char color[3]);

//Starts at color1 and "fades" to color2, speed is dependent on period.
void fadeAll(u_int period, u_char color1[3], u_char color2[3]);

//fades through all primary and secondary rgb colors, speed is dependent on period.
void colorWheel(int period);

//Decreases brightness of the given color1 until off, then increases brightness of color2.
void breatheAll(u_int period, u_char color1[3], u_char color2[3]);

//Potentially outdated, time spent in this function dependent on period.
void setPattern2(u_int period, u_char color1[3], u_char color2[3]);

//Takes an array pattern, in which each set of 3 indices contains r g and b values.
void fillPattern(u_int period, u_char* pattern,u_int pattern_length);

#endif /* PATTERNS_H_ */