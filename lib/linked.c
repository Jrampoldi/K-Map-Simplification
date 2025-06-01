#include "linked.h"

void addPointToList(LinkedList *myList, int x, int y){
	if (myList->size == 0){
		Node *n = malloc(sizeof(Node));

		n->data[0] = x;
		n->data[1] = y;
		n->next = NULL;

		myList->head = n;
		
		myList->size = 1;
		
	} else if (myList->size == 1){

		Node *n = malloc(sizeof(Node));

		n->data[0] = x;
		n->data[1] = y;
		n->next = NULL;

		myList->head->next = n;

		myList->size++;

	} else {
		Node *n = malloc(sizeof(Node));

		n->data[0] = x;
		n->data[1] = y;
		n->next = NULL;

		Node *previous = myList->head;
		Node *current = myList->head->next;

		while (current != NULL){
			previous = current;
			current = current->next;
		}

		previous->next = n;
		

		myList->size++;
	}
}

void printListData(LinkedList *myList){
	if (myList->size == 0){
		printf("ERROR: SIZE IS ZERO\n");
	} else {
		printf("%s","\t");
		Node *current = myList->head;
		while (current != NULL){
			printf("(%d,%d) ", current->data[0], current->data[1]);
			current = current->next;
		}
	}
}

char isInList(LinkedList *myList, int x, int y){
	Node *current = myList->head;
	while (current != NULL){
		if (x == current->data[0] && 
				y == current->data[1]){
			return 1;
		}
		current = current->next;
	}
	return 0;
}

void emptyList(LinkedList *myList){
	Node *previous = myList->head;
	Node *current = previous;
	while(current != NULL){
		current = current->next;
		free(previous);
		previous = current;
	}
	myList->size = 0;
}

void copyList(LinkedList *original, LinkedList *copy){
	Node *current = original->head;
	while (current != NULL){
		addPointToList(copy, current->data[0], current->data[1]);
		current=current->next;
	}
}

void addListToGroup(GroupList *myGroup, LinkedList *myList){

	LinkedNode *lnode = malloc(sizeof(LinkedNode));
	LinkedList *nlist = malloc(sizeof(LinkedList));

	nlist->size = 0;
	nlist->head = NULL;

	copyList(myList, nlist);

	lnode->list = nlist;
	lnode->nextList = NULL;

	if (myGroup->size == 0){

		myGroup->head = lnode;
		myGroup->size = 1;

	} else if (myGroup->size == 1) {

		myGroup->head->nextList = lnode;
		myGroup->size++;

	} else {

		LinkedNode* previous = myGroup->head;
		LinkedNode* current = myGroup->head->nextList;

		while (current != NULL){
			previous = current;
			current = current->nextList;
		}

		previous->nextList = lnode;
		

		myGroup->size++;
	}
}

void printGroup(GroupList *myGroup, int groupSize){

	if (myGroup->size == 0){
		printf("No Groups of %d found.\n\n", groupSize);
	} else {
		LinkedNode *current = myGroup->head;
		printf("Groups of %d found: \n\n", groupSize);
		while (current != NULL){
			printListData(current->list);
			puts("");
			current = current->nextList;
		}		
		puts("");
	}

}

void deleteListFromGroup(GroupList *myGroup, LinkedNode *myListNode){

	if (myGroup->size == 0){
		puts("ERROR: NOTHING TO DELETE");
	} else if (myGroup->size == 1){
		emptyList(myListNode->list);
		free(myListNode);
		myGroup->head = NULL;
		myGroup->size = 0;
	} else {
		LinkedNode *previous = myGroup->head;
		LinkedNode *current = previous->nextList;

		if (previous == myListNode){

			myGroup->head = previous->nextList;
			emptyList(myListNode->list);
			free(myListNode);

		} else {
			while (current != myListNode && current != NULL){
				previous = current;
				current = current->nextList;
			}
			
			if (current != NULL){
				previous->nextList = current->nextList;
				free(myListNode);
			} else {
				previous->nextList = NULL;
			}

		}

		myGroup->size--;
	}
}

void emptyGroup(GroupList *myGroup){
	
	if (myGroup->size == 0){

		puts("ERROR: NOTHING TO DELETE FROM GROUP.");

	} else if (myGroup->size == 1){

		deleteListFromGroup(myGroup, myGroup->head);	

	} else {
		
		LinkedNode *previous = myGroup->head;
		LinkedNode *current = previous;
		while(current != NULL){
			current=current->nextList;
			deleteListFromGroup(myGroup, previous);
			previous = current;
		}
	}
}

void addPointToGroup(GroupList *singleBits, int x1, int y1){
	LinkedList *newList = malloc(sizeof(LinkedList));
	
	/* Init List */
	newList->size = 0;
	newList->head = NULL;

	addPointToList(newList, x1, y1);

	addListToGroup(singleBits, newList);
}

void addGroupOfTwo(GroupList *groupsOfTwo, int x1, int y1, int x2, int y2){
	LinkedList* newList = malloc(sizeof(LinkedList));

	/* Init List */
	newList->size = 0;
	newList->head = NULL;


	addPointToList(newList, x1, y1);
	addPointToList(newList, x2, y2);

	addListToGroup(groupsOfTwo, newList);

} 

void addGroupOfFour(GroupList *groupsOfFour, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	LinkedList* newList = malloc(sizeof(LinkedList));

	/* Init List */
	newList->size = 0;
	newList->head = NULL;


	addPointToList(newList, x1, y1);
	addPointToList(newList, x2, y2);
	addPointToList(newList, x3, y3);
	addPointToList(newList, x4, y4);

	addListToGroup(groupsOfFour, newList);

}

void addGroupOfEight(GroupList *groupsOfEight, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, 
												int x5, int y5, int x6, int y6, int x7, int y7, int x8, int y8){
	LinkedList* newList = malloc(sizeof(LinkedList));

	/* Init List */
	newList->size = 0;
	newList->head = NULL;


	addPointToList(newList, x1, y1);
	addPointToList(newList, x2, y2);
	addPointToList(newList, x3, y3);
	addPointToList(newList, x4, y4);
	addPointToList(newList, x5, y5);
	addPointToList(newList, x6, y6); 
	addPointToList(newList, x7, y7);
	addPointToList(newList, x8, y8);

	addListToGroup(groupsOfEight, newList);

}


