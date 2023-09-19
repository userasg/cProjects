#include <stdio.h>
 /* Example 22 (scopingvars.c) − A set of functions to consider scoping */

 int x = 1; /* Global variable declared outside any function or subroutine, whenever x is addressed without declaring another x variable */

/*here scoping refers to the visibility of varaibles and where they can be used int x=1 is a global variable because it is declared outside any function but it can be used and refered to inside any function unless another variable named x is declared*/
 void local_variable()
 {
 int x = 25; /*we can name a local variable x, which is the same name as the global varaible and it won't clash with the global one since its scope is just part of the local_varaible function*/
 printf("\n Local x is %d \n", x);
 x++; /*when we refer to x now we are refering to the local varaible x here*/
 printf("Local x is now %d \n", x);
 }

 void static_variable()
 /*Static variables have a lifetime that lasts until the end of the program. If they are local variables, then their value persists when execution leaves their scope, the default values of the static variables are 0. This static variable will change each time it is refered to unlike a normal local variable that keeps the value it was assigned*/
 {
 static int x = 50;
 printf("\n Static x is %d \n", x);
 x++;
 printf("Static x is now %d \n", x);
 }

 void global_variable()
 {
 printf("\n Global x is %d \n", x);
 x*= 10; /*because there is no local variable x delcared here when referencing x here we are refering to the global x variable declared outside any functions*/
 printf("Global x is now %d \n", x);
 }

 int main()
 {
 int x = 4;
 printf("\n Value of x in main is %d \n", x);
 local_variable(); /*here we are calling the local varaible function the local x variable has values 25 and 26, but has value 25 (its original value) whenever it is referenced */
 static_variable();/*the static variable function is called here the static local variable x has values 50 and 51 the static varaible has changed everywhere and has value 51 whenever referenced */
 global_variable();/*calling the global variable x that has a value of 1 and is declared outside all other functions but used inside the global variable function so its value has now been changed everywhere*/
 local_variable(); /*the local variable x is called again but because it is not a static variable whenever it is referenced or called the value of x does not change from 25 */
 static_variable();/*the static variable will change every time it is referenced/called which is why it is incremented from what it was assigned to last*/
 global_variable();
 return 0;
 }