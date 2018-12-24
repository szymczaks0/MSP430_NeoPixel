/*
 * helpers.c
 *
 *  Created on: Dec 22, 2018
 *      Author: Steve
 */
#include "helpers.h"
#include "patterns.h"
#include "ws2812.h"
#include <math.h>
#include <stdarg.h>

static u_char green[3] = {0, 255, 0};  // green
static u_char blue[3] = {0, 0, 255};  // blue
static u_char magenta[3] = {255, 0, 255};  // magenta
static u_char yellow[3] = {255, 255, 0};  // yellow
static u_char cyan[3] = {0, 255, 255};  // cyan
static u_char red[3] = {255, 0, 0};  // red
static u_char white[3] = {255, 255, 255}; //white
static u_char off[3] = {0, 0, 0};

u_char * makePattern(u_char arr[][3], u_int num_of_colors){
    int i = 0;
    int j = 0;
    u_char pattern[20] = {0};
    for(i = 0; i < num_of_colors; i++){
        for(j = 0; j < 3; j++){
            pattern[3 * i + j] = arr[0][j];
        }
        arr++;
    }
    return pattern;
}

void swap_pointers(u_char **a, u_char **b)
{
    u_char *temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

