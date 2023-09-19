#include <stdio.h>
 /* Example 23 (definitions.c) − Introducing defining(orig. Ivor Horton)*/

 #define PI 3.14159f /* Definition of the symbol PI when you define something it is defined outside the functions and then acts as a constant throughout*/

 int main()
 {
 float radius = 0.0f;
 float diameter = 0.0f;
 float circumference = 0.0f;
 float area = 0.0f;

 printf("Input the diameter: ");
 scanf("%f", &diameter);

 radius = diameter/2.0f;
 circumference = 2.0f*PI*radius;
 area = PI*radius*radius;

 printf("\nThe circumference is %.2f", circumference);
 printf("\nThe area is %.2f", area);
 return 0;
 }