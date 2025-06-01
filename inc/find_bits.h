#ifndef FIND_BITS_H_
#define FIND_BITS_H_

/* written headers */
#include <k_map_attr.h>
#include <linked.h>

/* look for kMaps */
extern int kMap[4][4];
extern int kMapSelect[4][4];

/* look for search criteria */
extern char searchForEPI;

/* Description:
 * 			Function will take a GroupList and input size,
 * 		then will locate isolated, unselected bits to add 
 * 		to the passed GroupList.
 *
 * Arguments:
 * 		1. GroupList for singleBits
 * 		2. inputSize
 *
 * Return Value:
 * 		1. N/a
 *
 * */
void findSingleBits(GroupList* singleBits, int inputSize);

/* Description:
 * 			Function will take a GroupList and input size,
 * 		then will locate groups of two surrounding unselected
 * 		bits and add them to the passed GroupList.
 *
 * Arguments:
 * 		1. GroupList for groupsOfTwo
 * 		2. inputSize
 *
 * Return Type:
 * 		1. N/A
 *
 * */
void findGroupsOfTwo(GroupList* groupsOfTwo, int inputSize);

/* Description:
 * 			Function will take a GroupList and input size,
 * 		then will locate groups of four surrounding unselected
 * 		bits and add them to the passed GroupList.
 *
 * Arguments:
 * 		1. GroupList for groupsOfFour
 * 		2. inputSize
 *
 * Return Type:
 * 		1. N/A
 *
 * */
void findGroupsOfFour(GroupList* groupsOfFour, int inputSize);

/* Description:
 * 			Function will take a GroupList and input size,
 * 		then will locate groups of eight surrounding unselected
 * 		bits and add them to the passed GroupList.
 *
 * Arguments:
 * 		1. GroupList for groupsOfEight
 * 		2. inputSize
 *
 * Return Type:
 * 		1. N/A
 *
 * */
void findGroupsOfEight(GroupList* groupsOfEight);


/* EPI Specific functions */

/* Description:
 *			Function will take the found groups as a 
 *		GroupList pointer (testGroups) and will search for
 *		EPI Groups by looking at, and comparing, the first bit placed in 
 *		the groups.
 *
 * Arguments: 
 * 		1. GroupList for empty EPI group (Destination)
 * 		2. GroupList for found groups (Source)
 *
 * Return Type:
 * 		1.N/a
 *
 * */
void locateEPI(GroupList *EPIGroups, GroupList *testGroups);

/* Description:
 * 			Called within locateEPI function as a way to remove 
 * 		any duplicate groups. Will look at GroupList passed and 
 * 		will compare head->data points in each list with all 
 * 		data points in others. 
 *
 * Arguments:
 * 		1. GroupList of filled EPIGroups
 *
 * Return Type:
 * 		1. N/a
 *
 * */
void removeDoubles(GroupList *EPIGroups);

/* Description:
 * 			Called within locateEPI function to select final 
 * 		processed EPI groups in kMapSelect.
 *
 * Arguments:
 * 		1. GroupList of filled EPI Groups
 *
 * Return Type:
 * 		1. N/a
 *
 * */
void selectEPIBits(GroupList  *myGroup);

#endif
