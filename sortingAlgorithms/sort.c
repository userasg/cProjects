#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void recursion(char *array[], int , int );
void putArraysTogether(char *array[], int , int , int );


void insertion_sort(LinkedList *list, int (*compare)(void *, void *))
{

	/*declare variables*/
	Node *node;
	Node *nodeToHold;
	LinkedList	*sortedA1ist;
	int ret;

	/*====step 1 make a empty list and a node pointer====*/
	/*initialise an empty list where sorting will be placed*/
	/*the node will point at this empty list that we initialise below*/
	sortedA1ist=initialise_linked_list();
	
	/*====step 2 take the first thing in the old list and set as head in sorted list outside a loop====*/
	/*append to take the list head data of og list and add to sorted list head*/
	append_linked_list(sortedA1ist, list->head->data);
	/*remove head of og list will then set list->head->next to be the head*/
	remove_head_linked_list(list);

	
	/*====step3 begin traversing the lists simultaniously using the list->head of og and node of new=====*/
	/*while list->head says to loop whilst there is still something in og loop because it checks if list->head is valid*/
	while(list->head){
		/*setting the node to point to the head of the new list which only has harmonious inside it*/
		/*node=sortedA1ist->head and node=node->next will work with the while loop to traverse through the new loop*/
		node=sortedA1ist->head;
		/*while node points to something valid*/
		while(node){

			/*does the comparison between the og list heads data and whatever node points to in the new list*/
			ret = (*compare)(list->head->data, node->data);
			

			/*CONDITION 1 AND 2*/
			/*condition 1 and 2 assumes theres something that node is pointing to in the new list*/
			/*this is for moving a word before another in two different ways*/
			if(ret <0){

			/*CONDITION 1*/
			/*this is if the word in the og list is smaller than the head of the new list*/
			/*the if statement checks if the node is currently at the head if so it node->prev should be null*/
			if(node==sortedA1ist->head || !node->prev)
			{
				/*if the word from the og list is less than the head of new list*/
				/*it should prepend the list and remove the head of the old list so it moves onto the next one*/
				/*if this condition is met and this happens then we break out of the overall if and while loop
				back to node=sortedA1ist->head this will now set node to point to the new head of sorted list which
				we have just changed to a new word here*/
				prepend_linked_list(sortedA1ist, list->head->data);
				remove_head_linked_list(list);
			}
			
			/*CONDITION 2*/
			/*this is if the node has moved onto a word thats not the head*/
			/*if the word that the node is is is bigger than the list head the word in the og list needs to go before this node*/
			/*it also means in a linked list if it goes before something it has to go after the thing it came before*/
			/*we can make another node to hold the data while we move it inbetween node and node->prev*/
			else
			{
			
			nodeToHold=initialise_node();
			/*setting the holding node data value (nodeToHold) to the data value*/
			nodeToHold->data=list->head->data;
			/*nodeToHold's next should be the current node*/
			nodeToHold->next=node;
			/*node 2's previous element should be the whatever the original's previous one*/
			nodeToHold->prev=node->prev;
			/*node's (original) previous value (originals previous)'s next value should be the newly node 2
			esstentially back forward's next*/
			node->prev->next=nodeToHold;
			/*then nodes prev is just the new node*/
			node->prev=nodeToHold;
			remove_head_linked_list(list);
			}
			break;
		}
		/*moves node on*/
		node=node->next;
		}

		/*CONDITION 3*/
		/*this is if there's still stuff in the old list but node isnt pointing to anything it means the conditions have
		decided theres nothing to put before the head so we can put it after*/
		if(!node){
				/*append to add to the end of the list rather than before anything*/
				append_linked_list(sortedA1ist, list->head->data);
				remove_head_linked_list(list);
			}

	}

	/*moves everything back to og list in order*/
	while(sortedA1ist->head){
		append_linked_list(list, sortedA1ist->head->data);
		remove_head_linked_list(sortedA1ist);
	}

	free_linked_list(sortedA1ist);




}



void merge_sort(LinkedList *list, int (*compare)(void *, void *))
{
	char **array;
	int i=0;
	int size;
	Node *nodeForSize;

	nodeForSize=list->head;
	size=0;
	/*count list size using node*/
	while(nodeForSize){
		size++;
		nodeForSize=nodeForSize->next;
	}

	/*printf("size is %d \n", size);*/
	array=(char **)calloc(size, sizeof(char *));
	
	/*loop array and fill up whilst removing the head which will move list head onto next item in list*/
	for(i=0;i<size;i++){
		array[i]=list->head->data;
		/*printf("moved across %s\n",array[i]);*/
		remove_head_linked_list(list);
	}

	
	/*calling the recursion function with array*/
	recursion(array, 0, size-1);

	/*refill list with new array data*/
	for(i=0;i<size;i++){
	append_linked_list(list, array[i]);
	}
	
	free(array);
}

/*recursion function that keeps calling itself and generating the correctly sorted array*/
void recursion(char *array[], int leftHalfStart, int rightHalfStart) {
    int middle;
    if (leftHalfStart-rightHalfStart!=0) 

    {
        middle=leftHalfStart+(rightHalfStart-leftHalfStart)/2;  
        recursion(array, leftHalfStart, middle);
        recursion(array, middle+1, rightHalfStart);
        putArraysTogether(array, leftHalfStart, middle, rightHalfStart);
    }
}

/*this function will take the halfs made in the recursion and put them together based on which is larger*/
void putArraysTogether(char *array[], int leftVal, int middle, int rightVal) {
    int i,j;
    int z;
    int sizeLeft;
    int sizeRight;
    /* create temp arrays */
    char **A1, **A2;

    sizeLeft = middle - leftVal + 1;
    sizeRight  = rightVal - middle;
    /*making dynamic arrays each time we need a half*/
    A1 = (char **) calloc(sizeLeft, sizeof(char *));
    A2 = (char **) calloc(sizeRight, sizeof(char *));

    i=0;
    /*filling up the left half of the array
    based on the position and size of each half*/
    while(i<sizeLeft){
        A1[i] = array[leftVal + i];
        i++;
    }
    i=0;
    /*filling up the right half of the array*/
    while (i< sizeRight){
        A2[i] = array[middle + 1 + i];
        i++;
    }

    i = 0;
    j = 0;
    z = leftVal;
     /*this is where we compare each left and right value*/
    while (i < sizeLeft && j < sizeRight) 
    {
        if (strcmp(A1[i],A2[j])<0) 
        {
        	/*setting the new array if the left value should go first*/
            array[z] = A1[i];
            i++;
        } 
        else/* otherwise setting the new array if the right value should go first*/

        {
            array[z] = A2[j];
            j++;
        }
        z++;

    }

     /*fill rest*/
    while (i < sizeLeft) 
    {
        array[z] = A1[i];
        i++;
        z++;
    }
    while (j < sizeRight) 
    {
        array[z] = A2[j];
        j++;
        z++;
    }

    free(A1);
    free(A2);
}

