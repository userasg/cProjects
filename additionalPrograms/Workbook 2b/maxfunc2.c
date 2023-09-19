#include <stdio.h>
 /* Example 21 (maxfunc.c) − A function to find the maximum number */


 int max_value( int x, int y, int z ) /*the int max_value function requires 3 parameters every time it is called and will return the max value out of the 3 parameters as the maxValue*/
 {
 int maxValue = x; /*Where does this live and die*/

 if (y > maxValue)
 {
 maxValue = y;
 }
 if (z > maxValue)
 {
 maxValue = z;
 }
 return maxValue;
 }
 
 int min_value( int x, int y, int z ) 
 {
 int minValue = x; 

 if (y < minValue)
 {
 minValue = y;
 }
 if (z < minValue)
 {
 minValue = z;
 }
 return minValue;
 }

 int main() /*the main function will call the max_value function and feed the numbers the user enters as the parameters for that function*/
 {
 int number1, number2, number3;

 printf("Enter 3 numbers : \n");
 scanf("%d%d%d", &number1, &number2, &number3);

 printf("Maximum value is: %d\n", max_value(number1, number2, number3));
 printf("Minimum value is: %d\n", min_value(number1, number2, number3));

 return 0;
 }