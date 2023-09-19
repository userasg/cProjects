#include <stdio.h>
/*Example 29 (doloops.c) − Introducing Do Loops*/
 int main()
 {
 int counter = 1;
 do
 {
 printf("%d\n", counter);
 counter++;
 }
 while (counter <= 10);
 return 0;
 }