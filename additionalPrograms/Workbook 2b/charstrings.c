 #include <stdio.h>
 #include <string.h>
 /* Example 26 (charstrings.c) − Considering strings (orig. reg Perry)*/
/*these are thre 3 different ways of initializing and using strings using the string.h library and the strcpy function which copies a string value into a variable array*/
 int main()
 {
 char person_1[20] = "Gareth Dai Jones";/*you can either fill the char array directly by inserting the string into the array*/
 char person_2[20];
 char person_3[20];

 strcpy (person_2, "Stephen J. Davies");
/*you can copy the string into the person_2 array using the strcpy library function*/
 person_3[0] = 'A';
 person_3[1] = 'd';
 person_3[2] = 'a';
 person_3[3] = 'm';
 person_3[4] = ' '; /*space*/
 person_3[5] = 'R';
 person_3[6] = '.';
 person_3[7] = ' '; /*space*/
 person_3[8] = 'S';
 person_3[9] = 'm';
 person_3[10] = 'i';
 person_3[11] = 't';
 person_3[12] = 'h';
 person_3[13] = '\0'; /*null*/
/*or you can either assign each space in the char array to a character*/
 printf("%s\n", person_1);
 printf("%s\n", person_2);
 printf("%s\n", person_3);
 return 0;
 }