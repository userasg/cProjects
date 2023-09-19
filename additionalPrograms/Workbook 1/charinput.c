 #include <stdio.h>
 int main()
 {
 char myChar ;
 char otherChar;
 printf("please enter 2 characters\n");
 scanf("%c %c", &myChar, &otherChar);
 printf("myChar is %c\n", myChar);
 printf("otherChar is %c\n", otherChar);
 printf("But as an int is %d \n", myChar);
 printf("Adding one equals %c \n", myChar + 1);
 printf("But as an int equals %d \n", myChar + 1);
 printf("I can add it to otherChar and get %c \n", myChar + otherChar);
 printf("But as an int that equals %d \n", myChar + otherChar);
 return 0;
 }