 #include <stdio.h>
 /* Example 13 (oddeven.c) − using if statements (orig. S Kochan)*/
 int main()
 {
 int inputNum, remainder;
 printf("Enter a number: ");
 scanf("%d", &inputNum);
 remainder = inputNum % 2;
 if (remainder == 0)
 printf("You entered an EVEN number \n");
 else if (remainder != 0) /* In class we replaced this with an ’else’ statement */
 printf("You entered an ODD number \n");
 return 0;
 }