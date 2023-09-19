 #include <stdio.h>

 #define HEIGHT 17

 /* Example 30 (printlarge.c) − Printing a large letter (orig. Pohl Kelley)*/

 int main()
 {
 int i = 0;

 printf("\n\nIIIIIII\n");
 while (i < HEIGHT)
 {
 printf(" III\n"); /*2 spaces*/
 i = i + 1;
 }
 printf("IIIIIII\n\n\n");
 return 0;
 }