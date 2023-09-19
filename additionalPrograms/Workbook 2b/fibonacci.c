#include <stdio.h>

 /*Example 32 (fibonacci.c) − Calculating Fibonacci sequence (orig. S. Kochan)*/

 int main()
 {
 int fibNum[15];

 fibNum[0] = 0;
 fibNum[1] = 1;
 
 int i;
 
 for (i = 2; i < 15; ++i)
 {
 fibNum[i] = fibNum[i-2] + fibNum[i-1];
 }
 for (i = 0; i < 15; ++i)
 {
 printf("%i\n", fibNum[i]);
 }
 return 0;
 }
