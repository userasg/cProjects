#include <stdio.h>
 /* Example 12 (increment.c) − plus one minus one, just messing around with this one to see what happens*/
 int main()
 {
 int yearNow = 2018, holderYear;
 printf("This year is %d \n", yearNow);
 holderYear=yearNow;
 printf("Next year is %d \n", ++yearNow);
 printf("Value of yearNow %d \n", yearNow);
 yearNow=holderYear;
 printf("Previous year is %d \n", --yearNow);
 printf("The current value of yearNow is %d \n", yearNow);
 printf("But printing yearNow++ gives %d \n", ++yearNow);
 printf("And printing yearNow− gives %d \n", --yearNow);
 printf("Why? Its because the variable year now gets reassigned to the current value every time its incremented or decremented");
 return 0;
 }
