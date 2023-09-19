 #include <stdio.h>
 /* Example 11 (chararith.c) − char arithmetic and ASCII*/
 /*this conversion is different to the previous example there we are converting two seperate data types which is why when a float becomes an int it looses its decimal component.Due to this we have to explicitly convert an int to a float and vice versa eg i1=f1. Here we are not converting anything. All chars in c are ascii, and since all ascii characters have a int value assocaited with them we are simply telling program to treat them as an int when we specify the format %d. This also is why we can 'add' them together */
 int main()
 {
 char myChar = 'm', otherChar = 'b';
 printf("myChar is %c \n", myChar);
 printf("But as an int is %d \n", myChar);
 printf("Adding one equals %c \n", myChar + 1);
 printf("But as an int equals %d \n", myChar + 1);
 printf("I can add it to otherChar and get %c \n", myChar + otherChar);
 printf("But as an int that equals %d \n", myChar + otherChar);
 return 0;
 }
