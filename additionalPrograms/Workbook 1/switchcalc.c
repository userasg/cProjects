#include <stdio.h>
 /* Example 19 (switchcalc.c) − Calculator as a SWITCH. . .CASE (orig. S Kocham)*/
 int main()
 {
 float firstNum, secNum;
 char operator;
 printf("Enter your sum: \n");
scanf("%f %c %f", &firstNum, &operator, &secNum);
switch (operator)
 {
 case '+':
 printf("%.2f \n", firstNum + secNum);
 break;
 case '-':
 printf("%.2f \n", firstNum - secNum);
 break;
 case '*':
 printf("%.2f \n", firstNum * secNum);
 break;
 case '/':
 if (secNum == 0)
 printf("Cant divide by zero \n");
 else
 printf("%.2f \n", firstNum / secNum);
 break;
 default:
 printf("Error, unknown operator \n");
 break;

 return 0;
 }
 }