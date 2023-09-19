#include "rpn.h"
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "queue.h"
#include <ctype.h>

int isLeftAssociative(char exprVal);
int isOperator(char exprVal);
int precedence(char exprVal);
int comparePrecedence(char exprVal1, char exprVal2);
int isNumber(char exprVal);

/*task3*/
/* convert an infix expression to postfix (rpn) using the */
/* shunting yard algorithm. */
/* return a queue containing the postfix expression. */
/* if an error occurs during evaluation, return silently with NULL. */
Queue *infix_to_postfix(char *expr)
{
	int i=0;
	int size, TF;
	char *array;


	size=strlen(expr);

	array = (char *) calloc(size, sizeof(char *));



	printf("this is size of expression %d\n", size);

	while(i<size){
		array[i]=expr[i];
		TF=isNumber(array[i]);
		printf("val->%c isdigit->%d\n", array[i], TF);
		i++;
	}
	/*
	tests
	*/

	free(array);
	return NULL;
}


int isLeftAssociative(char exprVal){
	int isLeftAssociative;
	if(exprVal=='+' || exprVal=='-' || exprVal=='*' || exprVal=='/')
	{
     isLeftAssociative=1;
	}
	if(exprVal=='^')
	{
	 isLeftAssociative=0;
	}

return isLeftAssociative; 
}

int isOperator(char exprVal){
	int isOperator;
	if(exprVal=='+' || exprVal=='-' || exprVal=='*' || exprVal=='/' || exprVal=='^')
	{
     isOperator=1;
	}
	else
	{
	 isOperator=0;
	}

return isOperator;
}

int precedence(char exprVal){
	int precedenceVal;

	if(exprVal=='+' || exprVal=='-')
	{
	 precedenceVal=1;	
	}

	if(exprVal=='*' || exprVal=='/')
	{
	 precedenceVal=2;	
	}

	if(exprVal=='^')
	{
	 precedenceVal=3;	
	}
return precedenceVal;
}

int comparePrecedence(char exprVal1, char exprVal2){
	int compVal;

	if(precedence(exprVal1)==precedence(exprVal2))
	{
		compVal=0;
	}	

	if(precedence(exprVal1)>precedence(exprVal2))
	{
		compVal=1;
	}	

	if(precedence(exprVal1)<precedence(exprVal2))
	{
		compVal=-1;
	}	

return compVal;
}

int isNumber(char exprVal){
	int TF;

	TF=isdigit(exprVal);
	if(TF!=0){
		TF=1;
	}

return TF;
}



/*testing */

/*#include "rpn.h"
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "queue.h"
#include <ctype.h>*/

/*int isLeftAssociative(char exprVal);
int isOperator(char exprVal);
int precedence(char exprVal);
int comparePrecedence(char exprVal1, char exprVal2);
int isNumber(char exprVal);*/

/*task3*/
/* convert an infix expression to postfix (rpn) using the */
/* shunting yard algorithm. */
/* return a queue containing the postfix expression. */
/* if an error occurs during evaluation, return silently with NULL. */
/*Queue *infix_to_postfix(char *expr)
{
	int i=0;
	int size, TF;
	Node *node;
	LinkedList *list; */

	
	/*list=initialise_linked_list();*/

	/*size=strlen(expr);*/

	/*array=(char *)calloc(size, sizeof(char )*/

	/*printf("this is size of expression %d\n", size);*/

	/*
	while(i<size){
		array[i]=expr[i];
		i++;
	}
	*/

	/*for(i=0;i<size;i++){
	append_linked_list(list, (void *)expr[i]);
	}*/
	
	/*i=0;
	node=list->head;
	for(i=0;i<size;i++){*/
		/*TF=isNumber(node->data);*/
		/*printf("val->%c\n",node->data);*/
		/*node=node->next;
	}*/

	

	/*free_linked_list(list);
	return NULL;
}*/


/*int isLeftAssociative(char exprVal){

return 0; 
}

int isOperator(char exprVal){


return 0;
}*/

/*int precedence(char exprVal){

return 0;
}
 
int comparePrecedence(char exprVal1, char exprVal2){
return 0;
}
int isNumber(char exprVal){
	int TF;

	TF=isdigit(exprVal);
	if(TF!=0){
		TF=1;
	}

return TF;
}*/