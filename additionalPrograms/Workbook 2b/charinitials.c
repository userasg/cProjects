#include <stdio.h>
 /* Example 25 (charinitials.c) − Introducing char arrays by getting initials (orig. Greg Perry)*/

 int main()
 {
 char firstname[20];/*in c there are no strings per se you have to initialize an array of characters and fill it with chars becoming a string. The string identifer is s*/
 char lastname[20];

 printf("What is your first name? ");
 scanf(" %s", firstname);
 printf("What is your last name? ");
 scanf(" %s", lastname);

 printf("Your initials are %c . %c . \n", firstname[0], 
 lastname[0]);
 /*we can only call a single item in the array each time*/
 return 0;
 
 }