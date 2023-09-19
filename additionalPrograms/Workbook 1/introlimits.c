#include <stdio.h>
#include <limits.h>

/*Example 6 (introlimits.c)-introducing limits and headers*/

int main()
{
	short int myShort;
	long int myLong;
	printf("Minimum value of INT:%d\n",INT_MIN);
	printf("Maximum value of INT:%d\n",INT_MAX);
	printf("Minimum value of SHORT:%hd\n",SHRT_MIN);
	printf("Maximum value of SHORT:%hd\n",SHRT_MAX);
	printf("Minimum value of LONG:%ld\n",LONG_MIN);
	printf("Maximum value of LONG:%ld\n",LONG_MAX);
	return 0;
}
