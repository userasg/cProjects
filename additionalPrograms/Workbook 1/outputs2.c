#include <stdio.h>

/*Example 5 (outputs2.c)-more output manipulation*/

int main()
{
	float myFloat=38.1579;
	printf("Printing myFloat using %%8.0f is %8.0f end\n",myFloat);
	printf("Printing myFloat using %%-8.0f is %-8.0f end\n",myFloat);
	printf("Printing myFloat using %%8.2f is %8.2f end\n",myFloat);
	printf("Printing myFloat using %%-8.4f is %-8.4f end\n",myFloat);
	printf("Printing neg myFloat using %%0.3f is %0.3f end\n",-myFloat);
	return 0;
}