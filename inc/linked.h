#ifndef LINKED_H_
#define LINKED_H_
/* c header files */
#include <stdio.h>
#include <stdlib.h>

/* Description:
 * 			Structure for base node building
 *		block of linked lists. Will hold bit
 *		positions in kMap as data.
 *
 * */
typedef struct node{

	struct node *next;
	int data[2];

} Node;

/* Description:
 * 			Structure of linked list for
 * 		containing groups found. Will point 
 * 		to nodes containing bit positions
 * 		and have a size.
 *
 * */
typedef struct linkedList{
	
	Node* head;
	int size;

} LinkedList;

/* Description:
 * 			Stucture for base linkedNode 
 * 		building block of grouped linked list. 
 * 		will contain a pointer to a linked list 
 * 		as its data.
 *
 * */
typedef struct linkedNode{

	struct linkedNode* nextList;
	LinkedList* list;

} LinkedNode;

/* Description:
 * 			Structure resposible for containing all
 * 		found groups in a kMap. Will pointx to LinkedNodes
 * 		that will point to located groups in a kmap.
 *
 * */
typedef struct groupList{
	
	LinkedNode* head;
	int size;

} GroupList;

/* Functions for linked lists */
void addPointToList(LinkedList *myList, int x, int y);
void printListData(LinkedList *myList);
char isInList(LinkedList *myList, int x, int y);
void emptyList(LinkedList *myList);
void copyList(LinkedList *original, LinkedList *copy);

/* Functions for groups of linked lists */
void addListToGroup(GroupList *myGroup, LinkedList *myList);
void printGroup(GroupList *myGroup, int groupSize);
void deleteListFromGroup(GroupList *myGroup, LinkedNode *myListNode);
void emptyGroup(GroupList *myGroup);

/* Functions kMap specific */
void addPointToGroup(GroupList *singleBits, int x1, int y1);
void addGroupOfTwo(GroupList *groupsOfTwo, int x1, int y1, int x2, int y2);
void addGroupOfFour(GroupList *groupsOfFour, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void addGroupOfEight(GroupList *groupsOfEight, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4,
						int x5, int y5, int x6, int y6, int x7, int y7, int x8, int y8);


#endif
