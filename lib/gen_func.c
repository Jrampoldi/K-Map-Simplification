#include <gen_func.h>

void generateSimplifiedFunction(GroupList *allGroups[7], int inputSize){
	/* Init buffer */
	char buffer[100] = "";

	/* Loop through groups and genereate product based on linked list */
	for (size_t i = 0; i < 7; i++){
		if (allGroups[i]->size > 0){
			LinkedNode *targetGroup = allGroups[i]->head;
			while (targetGroup != NULL){

				if (inputSize == 2){
					generateProductOfTwo(targetGroup->list, buffer);
				} else if (inputSize == 3) {
					generateProductOfThree(targetGroup->list, buffer);
				} else if (inputSize == 4){
					generateProductOfFour(targetGroup->list, buffer);
				}
				
				/* Prepare for additional term */
				if (targetGroup->nextList != NULL){
					strcat(buffer, " + ");
				}

				targetGroup = targetGroup->nextList;
			}
			
			/* Prepare for additional term */
			for (int j = i; j < 6; j++){
				if(allGroups[j + 1]->size > 0){
					strcat(buffer, " + ");
				}
			}

		}
	}

	/* display function */
	printf("Simplified Function: %s\n", buffer);
}

void generateProductOfTwo(LinkedList *myList, char *buffer){
	/* Init Group Size */
	int groupSize = myList->size;

	/* Init Term Variables */
	const char *termOne = "a";
	const char *termTwo = "b";
	const char *compliment = "'";


	if (groupSize == 2){
		int* pointOne = myList->head->data;
		int* pointTwo = myList->head->next->data;

		if (pointOne[0] && pointTwo[0]){

			strcat(buffer, termOne);

		} else if (!pointOne[0] && !pointTwo[0]){

			strcat(buffer, termOne);
			strcat(buffer, compliment);

		}

		if (pointOne[1] && pointTwo[1]){
			
			strcat(buffer,termTwo);

		} else if (!pointOne[1] && !pointTwo[1]){
			strcat(buffer, termTwo);
			strcat(buffer,compliment);
		}

	} else { /* Group size is one */
		int* pointOne = myList->head->data;
		
		if (pointOne[0]){

			strcat(buffer, termOne);

		} else if (!pointOne[0]){

			strcat(buffer, termOne);
			strcat(buffer, compliment);

		}

		if (pointOne[1]){

			strcat(buffer, termTwo);

		} else if (!pointOne[1]){

			strcat(buffer, termTwo);
			strcat(buffer, compliment);
		}
	}
}

void generateProductOfThree(LinkedList *myList, char *buffer){
	
	/* Init Group Size */
	int groupSize = myList->size;

	/* Init Term Variables */
	char *termOne = "a";
	char *termTwo = "b";
	char *termThree = "c";
	char *compliment = "'";
	

	if (groupSize == 4){
		int *pointOne = myList->head->data;
		int *pointTwo = myList->head->next->data;
		int *pointThree = myList->head->next->next->data;
		int *pointFour = myList->head->next->next->next->data;

		/* check for termOne */
		if (pointOne[0] && pointTwo[0] && pointThree[0] && pointFour[0]){

			strcat(buffer, termOne);

		} else if (!pointOne[0] && !pointTwo[0] && !pointThree[0] && !pointFour[0]){

			strcat(buffer, termOne);
			strcat(buffer, compliment);

		}

		/* check for termTwo */
		if ((pointOne[1] > 1) && (pointTwo[1] > 1) && 
		   		(pointThree[1] > 1) && (pointFour[1] > 1)){

			strcat(buffer, termTwo);

		} else if (!(pointOne[1] > 1) && !(pointTwo[1] > 1) &&
				!(pointThree[1] > 1) && !(pointFour[1] > 1)){

			strcat(buffer, termTwo);	
			strcat(buffer, compliment);

		}

		/* check for termThree */
		if ((pointOne[1] > 0 && pointOne[1] < 3) &&
				(pointTwo[1] > 0 && pointTwo[1] < 3) &&
				(pointThree[1] > 0 && pointThree [1] < 3) &&
		   		(pointFour[1] > 0 && pointFour[1] < 3)){

			strcat(buffer, termThree);

		} else if (((pointOne[1] == 0) || (pointOne[1] == 3)) &&
					((pointTwo[1] == 0) || (pointTwo[1] == 3)) &&
					((pointThree[1] == 0) || (pointThree[1] == 3)) &&
		   			((pointFour[1] == 0) || (pointFour[1] == 3))){

			strcat(buffer, termThree);
			strcat(buffer, compliment);

		}
  
	} else if (groupSize == 2){
		int *pointOne = myList->head->data;
		int *pointTwo = myList->head->next->data;

		/* check for term one */
		if (pointOne[0] && pointTwo[0]){

			strcat(buffer, termOne);

		} else if (!pointOne[0] && !pointTwo[0]){

			strcat(buffer, termOne);
			strcat(buffer, compliment);

		}

		/* check for term two */
		if ((pointOne[1] > 1) && (pointTwo[1] > 1)){

			strcat(buffer, termTwo);

		} else if (!(pointOne[1] > 1) && !(pointTwo[1] > 1)){
			
			strcat(buffer, termTwo);
			strcat(buffer, compliment);

		}

		/* check for term three */
		if ((pointOne[1] > 0 && pointOne[1] < 3) && 
				(pointTwo[1] > 0 && pointTwo[1] < 3)){

			strcat(buffer, termThree);

		} else if (((pointOne[1] == 0) || (pointOne[1] == 3) && 
				(pointTwo[1] == 0) || (pointTwo[1] == 3))){

			strcat(buffer, termThree);
			strcat(buffer, compliment);
		}

	} else { /* Group size is one */
		int *pointOne = myList->head->data;

		/* check for termOne */
		if (pointOne[0]){

			strcat(buffer, termOne);

		} else if (!pointOne[0]){

			strcat(buffer, termOne);
			strcat(buffer, compliment);

		}

		/* check for termTwo*/
		if (pointOne[1] > 1){

			strcat(buffer, termTwo);

		} else if (!(pointOne[1] > 1)){

			strcat(buffer, termTwo);
			strcat(buffer, compliment);

		}

		if (pointOne[1] > 0 && pointOne[1] < 3){
			
			strcat(buffer, termThree);

		} else if ((pointOne[1] == 0) || (pointOne[1] == 3)){

			strcat(buffer, termThree);
			strcat(buffer, compliment);

		}
	}
}

void generateProductOfFour(LinkedList *myList, char *buffer){

	/* Init Group Size */
	int groupSize = myList->size;

	/* Init Term Variables */
	char *termOne = "a";
	char *termTwo = "b";
	char *termThree = "c";
	char *termFour = "d";
	char *compliment = "'";

	
	if (groupSize == 8){
		
		/* Assign points */
		int *pointOne = myList->head->data;
		int *pointTwo = myList->head->next->data;
		int *pointThree = myList->head->next->next->data;
		int *pointFour = myList->head->next->next->next->data;
		int *pointFive = myList->head->next->next->next->next->data;
		int *pointSix = myList->head->next->next->next->next->next->data;
		int *pointSeven = myList->head->next->next->next->next->next->next->data;
		int *pointEight = myList->head->next->next->next->next->next->next->next->data;

		/* check for termOne */
		if (pointOne[0] > 1 && pointTwo[0] > 1 && pointThree[0] > 1 && pointFour[0] > 1 &&
				pointFive[0] > 1 && pointSix[0] > 1 && pointSeven[0] > 1 && pointEight[0] > 1){
			
			strcat(buffer, termOne);

		} else if (!(pointOne[0] > 1) && !(pointTwo[0] > 1) && !(pointThree[0] > 1) && !(pointFour[0] > 1) &&
				!(pointFive[0] > 1) && !(pointSix[0] > 1) && !(pointSeven[0] > 1) && !(pointEight[0] > 1)){

			strcat(buffer, termOne);
			strcat(buffer, compliment);

		}

		/* check for termTwo */
		if ((pointOne[0] > 0 && pointOne[0] < 3) && (pointTwo[0] > 0 && pointTwo[0] < 3) && 
				(pointThree[0] > 0 && pointThree[0] < 3) && (pointFour[0] > 0 && pointFour[0] < 3) &&
				(pointFive[0] > 0 && pointFive[0] < 3) && (pointSix[0] > 0 && pointSix[0] < 3) && 
				(pointSeven[0] > 0 && pointSeven[0] < 3) && (pointEight[0] > 0 && pointEight[0] < 3)){

			strcat(buffer, termTwo);

		} else if ((pointOne[0] == 0 || pointOne[0] == 3) && (pointTwo[0] == 0 || pointTwo[0] == 3) && 
				(pointThree[0] == 0 || pointThree[0] == 3) && (pointFour[0] == 0 || pointFour[0] == 3) &&
				(pointFive[0] == 0 || pointFive[0] == 3) && (pointSix[0] == 0 || pointSix[0] == 3) && 
				(pointSeven[0] == 0 || pointSeven[0] == 3) && (pointEight[0] == 0 || pointEight[0] == 3)){

			strcat(buffer, termTwo);
			strcat(buffer, compliment);

		}

		/* check for termThree */
		if (pointOne[1] > 1 && pointTwo[1] > 1 && pointThree[1] > 1 && pointFour[1] > 1 &&
				pointFive[1] > 1 && pointSix[1] > 1 && pointSeven[1] > 1 && pointEight[1] > 1){

			strcat(buffer, termThree);

		} else if (!(pointOne[1] > 1) && !(pointTwo[1] > 1) && !(pointThree[1] > 1) && !(pointFour[1] > 1) &&
				!(pointFive[1] > 1) && !(pointSix[1] > 1) && !(pointSeven[1] > 1) && !(pointEight[1] > 1)){

			strcat(buffer, termThree);
			strcat(buffer, compliment);

		}
		
		/* check for termFour */
		if (((pointOne[1] > 0 && pointOne[1] < 3) && (pointTwo[1] > 0 && pointTwo[1] < 3) && 
		(pointThree[1] > 0 && pointThree[1] < 3) && (pointFour[1] > 0 && pointFour[1] < 3) &&
		(pointFive[1] > 0 && pointFive[1] < 3) && (pointSix[1] > 0 && pointSix[1] < 3) && 
		(pointSeven[1] > 0 && pointSeven[1] < 3) && (pointEight[1] > 0 && pointEight[1] < 3))){

			strcat(buffer, termFour);

		} else if (((pointOne[1] == 0 || pointOne[1] == 3) && (pointTwo[1] == 0 || pointTwo[1] == 3) && 
		(pointThree[1] == 0 || pointThree[1] == 3) && (pointFour[1] == 0 && pointFour[1] == 3) &&
		(pointFive[1] == 0 || pointFive[1] == 3) && (pointSix[1] == 0 && pointSix[1] == 3) && 
		(pointSeven[1] == 0 || pointSeven[1] == 3) && (pointEight[1] == 0 && pointEight[1] == 3))){

			strcat(buffer, termFour);
			strcat(buffer, compliment);

		}

	} else if (groupSize == 4){

		int *pointOne = myList->head->data;
		int *pointTwo = myList->head->next->data;
		int *pointThree = myList->head->next->next->data;
		int *pointFour = myList->head->next->next->next->data;

		/* check for termOne */
		if ((pointOne[0] > 1) && (pointTwo[0] > 1) &&
				(pointThree[0] > 1) && (pointFour[0] > 1)){

			strcat(buffer, termOne);

		} else if (!(pointOne[0] > 1) && !(pointTwo[0] > 1) &&
				!(pointThree[0] > 1) && !(pointFour[0] > 1)){

			strcat(buffer, termOne);
			strcat(buffer, compliment);

		}

		/* check for termTwo */
		if (((pointOne[0] > 0) && (pointOne[0] < 3)) && 
				((pointTwo[0] > 0) && (pointTwo[0] < 3)) &&
				((pointThree[0] > 0) && (pointThree[0] < 3)) && 
				((pointFour[0] > 0) && (pointFour[0] < 3))){

			strcat(buffer, termTwo);

		} else if (((pointOne[0] == 0) || (pointOne[0] == 3)) && 
				((pointTwo[0] == 0) || (pointTwo[0] == 3)) &&
				((pointThree[0] == 0) || (pointThree[0] == 3)) && 
				((pointFour[0] == 0) || (pointFour[0] == 3))){

			strcat(buffer, termTwo);
			strcat(buffer, compliment);

		}
		
		/* check for termThree */
		if ((pointOne[1] > 1) && (pointTwo[1] > 1) &&
				(pointThree[1] > 1) && (pointFour[1] > 1)){

			strcat(buffer, termThree);

		} else if (!(pointOne[1] > 1) && !(pointTwo[1] > 1) &&
				!(pointThree[1] > 1) && !(pointFour[1] > 1)){

			strcat(buffer, termThree);
			strcat(buffer, compliment);
		}
		
		/* check for termFour */
		if ((((pointOne[1] > 0) && (pointOne[1] < 3)) && 
				((pointTwo[1] > 0) && (pointTwo[1] < 3)) &&
				((pointThree[1] > 0) && (pointThree[1] < 3)) && 
				((pointFour[1] > 0) && (pointFour[1] < 3)))){

			strcat(buffer, termFour);

		} else if ((((pointOne[1] == 0) || (pointOne[1] == 3)) && 
				((pointTwo[1] == 0) || (pointTwo[1] == 3)) &&
				((pointThree[1] == 0) || (pointThree[1] == 3)) && 
				((pointFour[1] == 0) || (pointFour[1] == 3)))){

			strcat(buffer, termFour);
			strcat(buffer, compliment);

		}

	} else if (groupSize == 2){

		int *pointOne = myList->head->data;
		int *pointTwo = myList->head->next->data;

		/* check for termOne */
		if (pointOne[0] > 1 && pointTwo[0] > 1){

			strcat(buffer, termOne);

		} else if (!(pointOne[0] > 1) && !(pointTwo[0] > 1)){
			
			strcat(buffer, termOne);
			strcat(buffer, compliment);

		}
		
		/* check for termTwo */
		if (((pointOne[0] > 0) && (pointOne[0] < 3)) && 
				((pointTwo[0] > 0) && (pointTwo[0] < 3))){

			strcat(buffer, termTwo);

		} else if (((pointOne[0] == 0) || (pointOne[0] == 3)) && 
				((pointTwo[0] == 0) || (pointTwo[0] == 3))){

			strcat(buffer, termTwo);
			strcat(buffer, compliment);

		}

		/* check for termThree */
		if ((pointOne[1] > 1) && (pointTwo[1] > 1)){

			strcat(buffer, termThree);

		} else if(!(pointOne[1] > 1) && !(pointTwo[1] > 1)) {

			strcat(buffer, termThree);
			strcat(buffer, compliment);
		}

		/* check for termFour */
		if (((pointOne[1] > 0) && (pointOne[1] < 3)) && 
				((pointTwo[1] > 0) && (pointTwo[1] < 3))){

			strcat(buffer, termFour);

		} else if (((pointOne[1] == 0) && (pointOne[1] == 3)) && 
				((pointTwo[1] == 0) && (pointTwo[1] == 3))){

			strcat(buffer, termFour);
			strcat(buffer, compliment);

		}

	} else { /* Group size is one */

		int *pointOne = myList->head->data;

		/* check for termOne */
		if (pointOne[0] > 1){

			strcat(buffer, termOne);

		} else if (!(pointOne[0] > 1)){

			strcat(buffer, termOne);
			strcat(buffer, compliment);

		}
		
		/* check for termTwo */
		if ((pointOne[0] > 0) && (pointOne[0] < 3)){

			strcat(buffer, termTwo);

		} else if ((pointOne[0] == 0) || (pointOne[0] == 3)){

			strcat(buffer, termTwo);
			strcat(buffer, compliment);

		}
		
		/* check for termThree */
		if ((pointOne[1] > 1)){

			strcat(buffer, termThree);

		} else if (!(pointOne[1] > 1)){

			strcat(buffer, termThree);
			strcat(buffer, compliment);

		}
		
		/* check for termFour */
		if ((pointOne[1] > 0) && (pointOne[1] < 3)){

			strcat(buffer, termFour);

		} else if ((pointOne[1] == 0) && (pointOne[1] == 3)){

			strcat(buffer, termFour);
			strcat(buffer, compliment);

		}
	}
}
