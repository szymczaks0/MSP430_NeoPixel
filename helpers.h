/*
 * helpers.h
 *
 *  Created on: Dec 22, 2018
 *      Author: Steve
 */

#ifndef HELPERS_H_
#define HELPERS_H_
#include "ws2812.h"

u_int * makePattern(u_int arr[][3], u_int num_of_colors);

void swap_pointers(u_int **a, u_int **b);

#endif /* HELPERS_H_ */
