/*	Written by: Jourdan Rampoldi
 * */


/* C Header Files */
#include <stdio.h>
#include <stdlib.h>

/* Written Header Files */
#include <linked.h>
#include <parse_function.h>
#include <k_map_attr.h>
#include <find_bits.h>
#include <gen_func.h>

int main(int argc, char *argv[]){

	if (argc != 2) {
		
		/* One argument string expected */
		printf("ERROR: WRONG NUMBER OF ARGS.\nARG SIZE: %d\n", argc);

	} else {
		
		/* initialize assets */
		int outputOfFour[4] = {0};
		int outputOfEight[8] = {0};
		int outputOfSixteen[16] = {0};

		/* Initialize Group lists to store groups */
		GroupList *singleBits = malloc(sizeof(GroupList));
		GroupList *groupsOfTwo = malloc(sizeof(GroupList));
		GroupList *groupsOfFour = malloc(sizeof(GroupList));
		GroupList *groupsOfEight = malloc(sizeof(GroupList));

		/* Initialize EPI GroupLists */
		GroupList *EPIGroupsOfTwo = malloc(sizeof(GroupList));
		GroupList *EPIGroupsOfFour = malloc(sizeof(GroupList));
		GroupList *EPIGroupsOfEight = malloc(sizeof(GroupList));

		GroupList *allGroups[7] = {EPIGroupsOfEight, EPIGroupsOfFour, EPIGroupsOfTwo, 
			groupsOfEight, groupsOfFour, groupsOfTwo, singleBits
		};
		/* parse function string for input */ 
		char *binary_function = argv[1];
		int inputSize = getInputSize(binary_function);

		switch(inputSize){

			case 2: 

				/* Parse output values */
				getOutputValues(binary_function, outputOfFour, 4); 
				outputToKMap(outputOfFour, inputSize);
				
				/* Search for EPI Groups */
				findGroupsOfTwo(groupsOfTwo, inputSize);
				locateEPI(EPIGroupsOfTwo, groupsOfTwo);

				searchForEPI = 0x0;

				/* Search for PI Groups */
				findGroupsOfTwo(groupsOfTwo, inputSize);
				findSingleBits(singleBits, inputSize);

				break;

			case 3: 

				/* Parse output values */
				getOutputValues(binary_function, outputOfEight, 8); 
				outputToKMap(outputOfEight, inputSize);

				/* Search for EPI Groups */

				/* Look for groups of four */
				findGroupsOfFour(groupsOfFour, inputSize);
				locateEPI(EPIGroupsOfFour, groupsOfFour);
				
				/* Look for groups of two */
				findGroupsOfTwo(groupsOfTwo, inputSize);
				locateEPI(EPIGroupsOfTwo, groupsOfTwo);

				searchForEPI = 0x0;

				/* Search for PI Groups */
				findGroupsOfFour(groupsOfFour, inputSize);
				findGroupsOfTwo(groupsOfTwo, inputSize);
				findSingleBits(singleBits, inputSize);

				break;

			case 4: 

				/* Parse output values */
				getOutputValues(binary_function, outputOfSixteen, 16); 
				outputToKMap(outputOfSixteen, inputSize);

				/* Search for EPI Groups */

				/* Look for groups of eight */
				findGroupsOfEight(groupsOfEight);
				locateEPI(EPIGroupsOfEight, groupsOfEight);

				/* Look for groups of four */
				findGroupsOfFour(groupsOfFour, inputSize);
				locateEPI(EPIGroupsOfFour, groupsOfFour);

				/* Look for groups of two */
				findGroupsOfTwo(groupsOfTwo, inputSize);
				locateEPI(EPIGroupsOfTwo, groupsOfTwo);

				searchForEPI = 0x0;
				
				/* Search for PI Groups */
				findGroupsOfEight(groupsOfEight);
				findGroupsOfFour(groupsOfFour, inputSize);
				findGroupsOfTwo(groupsOfTwo, inputSize);
				findSingleBits(singleBits, inputSize);

				break;

			default: 
				puts("ERROR: INPUT SIZE INVALID");
		}

		/* display map */
		printMap(inputSize);


		/* display groups found */
		(EPIGroupsOfEight->size > 0) ? printGroup(EPIGroupsOfEight, 8) : NULL;
		(EPIGroupsOfFour->size > 0) ? printGroup(EPIGroupsOfFour, 4) : NULL;
		(EPIGroupsOfTwo->size > 0) ? printGroup(EPIGroupsOfTwo, 2) : NULL;

		(groupsOfEight->size > 0) ? printGroup(groupsOfEight, 8) : NULL;
		(groupsOfFour->size > 0) ? printGroup(groupsOfFour, 4) : NULL;
		(groupsOfTwo->size > 0) ? printGroup(groupsOfTwo, 2) : NULL;
		(singleBits->size > 0) ? printGroup(singleBits, 1) : NULL;

		/* print simplified function */
		generateSimplifiedFunction(allGroups, inputSize);
		puts(""); // newline

	}
	
	/* Exit success */
	return 0;
}
