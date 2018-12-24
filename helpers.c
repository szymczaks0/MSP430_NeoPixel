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

static u_int green[3] = {0, 255, 0};  // green
static u_int blue[3] = {0, 0, 255};  // blue
static u_int magenta[3] = {255, 0, 255};  // magenta
static u_int yellow[3] = {255, 255, 0};  // yellow
static u_int cyan[3] = {0, 255, 255};  // cyan
static u_int red[3] = {255, 0, 0};  // red
static u_int white[3] = {255, 255, 255}; //white
static u_int off[3] = {0, 0, 0};

u_int * makePattern(u_int arr[][3], u_int num_of_colors){
    int i = 0;
    int j = 0;
    u_int pattern[18] = {0};
    for(i = 0; i < num_of_colors; i++){
        for(j = 0; j < 3; j++){
            pattern[3 * i + j] = arr[0][j];
        }
        arr++;
    }
    return pattern;
}

void swap_pointers(u_int **a, u_int **b)
{
    u_int *temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

