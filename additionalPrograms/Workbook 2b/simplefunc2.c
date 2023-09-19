#include <stdio.h>
 /* Example 20 (simplefunc.c) − A very simple function (adapted orig. S Kocham)*/


 void my_message ()
 {
 printf("This is my message \n");
 return;
 }

 int main()
 {
 int counter =0;
 printf("I have a message \n");
 for (counter=0;counter<=4;counter++)
 {
 my_message();
 }
 return 0;
 }