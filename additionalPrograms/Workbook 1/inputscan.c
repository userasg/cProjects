#include <stdio.h>

/*Example 3 (inputscan.c)-introducing scanf()*/

int main()
{
	int myNum=42;
	char myLetter;
	float myFloat;
	printf("Enter a character:");
	scanf("%c",& myLetter);
	printf("Enter a floating number:");
	scanf("%f", & myFloat);
	printf("\nNumber is %d\n",myNum);
	printf("\nCharacter is %c\n",myLetter);
	printf("\nNumber is %f\n",myFloat);
	return 0;
}
