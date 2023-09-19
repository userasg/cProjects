#include <stdio.h>

/*Example 4 (outputs.c)-introducting output manipulation*/

int main()
{
	int myNum=42;
	printf("Printing myNum using %%d is %d\n",myNum);
	printf("Printing myNum using %%1d is %1d\n",myNum);
	printf("Printing myNum using %%2d is %2d\n",myNum);
	printf("Printing myNum using %%3d is %3d\n",myNum);
	printf("Printing myNum using %%4d is %4d\n",myNum);
	printf("Printing myNum using %%05d is %05d\n",myNum);
	printf("Printing myNum using %%06d is %06d\n",myNum);
	printf("Printing myNum using %%4d is %4d\n",-myNum);	

	return 0;
}