# include <stdio.h>
/*capitalize.c*/
int main()
{
char myChar, otherChar;
printf("Enter a character: ");
scanf("%c", &myChar);
if (myChar >= 'a' && myChar <= 'z')
printf("here it is capitizied %c", myChar-32);
else
printf("follow instructions");
return 0;
}
