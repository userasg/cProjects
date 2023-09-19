#include <stdio.h>
 /* Example 28 (whileloops.c) − Introducing While Loops*/

 int main()
 {
 int counter = 1;
 while (counter <= 10)
 {
 printf("%d\n", counter);
 counter++;
 }
 return 0;
 }

/*while loop - used for looping until a condition is satisfied and when it is unsure how many times the code should be in loop

for loop - used for looping until a condition is satisfied but it is used when you know how many times the code needs to be in loop

do while loop - executes the content of the loop once before checking the condition of the while.*/