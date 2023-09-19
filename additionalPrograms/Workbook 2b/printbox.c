
#include <stdio.h>

 /* Example 31 (printbox.c) − Printing a box with a loop(orig. B. Horton)*/

 int main()
 {
 char myChar='*';
 printf( "\n∗∗∗∗∗∗∗∗∗∗∗∗");

 for(int count = 1 ; count <= 8 ; ++count)
 {
 printf("\n*%12c",myChar); /* 12 spaces I used the indent method of %12c which will indent the varaible myChar which is placed here using the identifier and then indented using the %12*/ 
 }

 printf("\n∗∗∗∗∗∗∗∗∗∗∗∗∗\n");
 return 0;
 }
 
