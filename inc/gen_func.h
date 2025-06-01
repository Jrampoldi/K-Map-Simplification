#ifndef GEN_FUNC_H_
#define GEN_FUNC_H_

/* C Headers */
#include <stdio.h>
#include <string.h>

/* Written Headers */
#include <linked.h>

/* Description:
 * 			generateSimplifiedFunction will take all of the groups
 * 		and the input size and call the approprate function to 
 * 		build a simplified function string, which will then be
 * 		printed to the console
 *
 * Arguments:
 * 			1. GroupList array of all groups 
 * 			2. input size of kMap
 *
 * Return Value:
 * 			1. N/a
 *
 * */
void generateSimplifiedFunction(GroupList *allGroups[7], int inputSize);

/* Description:
 * 			generateProductOfTwo will take individual groups as 
 * 		linked lists and will determine the appropriate terms 
 * 		to add to the buffer. Called in case of 2 term K Map.
 *
 * Arguments: 
 * 			1. LinkedList of one group
 * 			2. String buffer
 *
 * Return Value:
 * 			1. N/a
 *
 * */
void generateProductOfTwo(LinkedList *myList, char *buffer);

/* Description:
 * 			generateProductOfThree will take individual groups as 
 * 		linked lists and will determine the appropriate terms 
 * 		to add to the buffer. Called in case of 3 term K Map.
 *
 * Arguments: 
 * 			1. LinkedList of one group
 * 			2. String buffer
 *
 * Return Value:
 * 			1. N/a
 *
 * */
void generateProductOfThree(LinkedList *myList, char *buffer);

/* Description:
 * 			generateProductOfFour will take individual groups as 
 * 		linked lists and will determine the appropriate terms 
 * 		to add to the buffer. Called in case of 4 term K Map.
 *
 * Arguments: 
 * 			1. LinkedList of one group
 * 			2. String buffer
 *
 * Return Value:
 * 			1. N/a
 *
 * */
void generateProductOfFour(LinkedList *myList, char *buffer);

#endif
