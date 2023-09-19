#include <stdio.h>

 /* Example 31 (printbox.c) − Printing a box with a loop(orig. B. Horton)*/
 int height;
 char myChar='*';
 
 void heightdraw (height)
{
 printf( "\n∗∗∗∗∗∗∗∗∗∗∗∗");

 for(int count = 1 ; count <= height ; ++count)
 {
 printf("\n*%12c",myChar); /* 12 spaces I used the indent method of %12c which will indent the varaible myChar which is placed here using the identifier and then indented using the %12*/ 
 }

 printf("\n∗∗∗∗∗∗∗∗∗∗∗∗∗\n");
}

 int main()
 {
 printf("Input the height: ");
 scanf("%d", &height);
 heightdraw(height);
 return 0;
 }
 