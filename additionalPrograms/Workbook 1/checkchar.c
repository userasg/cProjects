 #include <stdio.h>
/* Example 16 (checkchar.c) − first look at sanitising input (orig. S Kochan)*/
 int main()
 {
 char myChar;
 printf("Enter a character: ");
 scanf("%c", &myChar);
 if ((myChar >= 'a' && myChar <= 'z') || (myChar >= 'A' && myChar <= 'Z'))
 printf("You entered a letter \n");
 else if (myChar >= '0' && myChar <= '9')
 printf("You entered a number \n");
 else
 printf("You entered a non−alphanumeric \n");
 return 0;
 }

 