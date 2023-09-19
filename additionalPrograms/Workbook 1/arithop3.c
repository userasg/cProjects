#include <stdio.h>
/*Example 9 (arithop3.c) - more arithmetic operations (modulus)*/
int main()
{
	int a =25, b=5, c= 10, d=7 ;
	printf("a %% b = %d \n", a % b);
	printf("a %% c = %d \n", a % c);
 	printf("a %% d = %d \n", a % d);  
  printf("a / d * d + a %% d = %d \n", a / d * d + a % d);
	return 0;
}