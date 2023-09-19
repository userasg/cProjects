#include <stdio.h>
/*Example 7 (arithop.c) - arithmetic operations*/
int main()
{
	int a =100, b=2, c=25, d=4;
	int result;
	result=a-b;
	printf("a-b=%d\n",result);
	result=b*c;
	printf("b*c=%d\n",result);
	result=a/c;
	printf("a/c=%d\n",result);
	result=a+b*c;
	printf("a+b*c=%d\n",result);
	printf("a*b+c*d=%d\n",a*b+c*d);
	return 0;
}
	
