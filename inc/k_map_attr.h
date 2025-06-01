#ifndef K_MAP_ATTRIBUTES_H_
#define K_MAP_ATTRIBUTES_H_

/* c header files */
#include <stdlib.h>

/* written header files*/
#include <linked.h>

/* Description:
 * 			Function will take array of outputs and
 * 		input size and will handle approprate function 
 * 		call to assign values to global kMap array.
 *
 * Arguments:
 * 		1. Output array (1D)
 * 		2. size of kMap input
 *
 * Return Value:
 * 		1. N/a
 * */
void outputToKMap(int *output, int inputSize);

/* Description:
 * 			Function will take output array of 1D kMap
 * 		values and will place them in a 2D global kMap
 * 		array to approprate position according to a
 * 		2^2 kMap.
 *
 * Arguments:
 * 		1. Output Array (1D)
 *
 * Return Value:
 * 		1. N/a
 *
 * */
void inputOfTwo(int *output);

/* Description:
 * 			Function will take output array of 1D kMap
 * 		values and will place them in a 2D global kMap
 * 		array to approprate position according to a
 * 		2^2 kMap.
 *
 * Arguments:
 * 		1. Output Array (1D)
 *
 * Return Value:
 * 		1. N/a
 *
 * */
void inputOfThree(int *output);

/* Description:
 * 			Function will take output array of 1D kMap
 * 		values and will place them in a 2D global kMap
 * 		array to approprate position according to a
 * 		2^3 kMap.
 *
 * Arguments:
 * 		1. Output Array (1D)
 *
 * Return Value:
 * 		1. N/a
 *
 * */

void inputOfFour(int *output);

/* Description:
 * 			Function will take output array of 1D kMap
 * 		values and will place them in a 2D global kMap
 * 		array to approprate position according to a
 * 		2^4 kMap.
 *
 * Arguments:
 * 		1. Output Array (1D)
 *
 * Return Value:
 * 		1. N/a
 *
 * */
void printMap(int inputSize);

#endif
