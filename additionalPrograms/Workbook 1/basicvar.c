#include <stdio.h>
/*Example 2 (basicvar.c) - basic variables*/
int main()
{
	int firstnum=12; /*here declaring the firstnum variable as an int and assigning it a value at the same time*/
	char myLetter; /*declaring the myLetter variable as a char but doesn't assign the value*/
	float floater1; /*declares the float as floater1*/
	myLetter='S'; /*now assigning the variables that were declared*/
	floater1=3.14;	
	printf("Value of firstnum is %d \n", firstnum); /* all the % signs act as placeholders for the variables that take its place so %d represents a decimal variable that replaces it*/
	printf("Value of myLetter is %c \n", myLetter);
	printf("Value of floater1 is %f \n", floater1);
	return 0;
}
