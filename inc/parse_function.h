#ifndef PARSE_FUNCTION_H_
#define PARSE_FUNCTION_H_

/* C Headers */

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Description:
 * 			Function will take a string, 
 * 		parse to find the amount of inputs 
 * 		passed, and finally return the input 
 * 		size.
 * 
 * Arguments:
 * 		1. Boolean function as a string
 *
 * Return Value:
 * 		2. input size
 *
 * */
int getInputSize(const char *func_str);

/* Description: 
 * 			Function will take a boolean function 
 * 		as a string, parse the output values, and 
 * 		place them in the provided output array. 
 * 			Function will also parse type of 
 * 		boolean function provided and assign 1's
 * 		and 0's appropriately.
 *
 * Arguments:
 * 		1. Boolean function as string
 * 		2. Array to store outputs
 * 		3. Size of array passed
 *
 * Return Value:
 * 		1. N/a
 *
 * */
void getOutputValues(const char *func_str, int *outputs, size_t outputSize);

#endif
