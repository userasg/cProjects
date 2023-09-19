 #include <stdio.h>
 /* Example 20 (simplefunc.c) − A very simple function (adapted orig. S Kocham)*/


 void my_message ()
 {
 printf("This is my message \n");
 return;
 }

 int main()
 {
 printf("I have a message \n");
 my_message();
 my_message();
 return 0;
 }