#include <stdio.h>
 /* Example 15 (leapyear.c) − combining logic (orig. S Kochan)*/
 int main()
 {
 int inputYear, div_4, div_100, div_400;
 printf("Enter a year: ");
 scanf("%d", &inputYear);
 if (inputYear>0)
 {
 div_4 = inputYear % 4;
 div_100 = inputYear % 100;
 div_400 = inputYear % 400;
 if ((div_4 == 0 && div_100 !=0) || div_400 == 0)
 printf("Is a leap year \n");
 else
 printf("Not a leap year \n"); 
 }
 else 
 printf("enter a valid year");
 return 0;
 }