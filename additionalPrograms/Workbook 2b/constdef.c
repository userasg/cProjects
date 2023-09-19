 #include <stdio.h>
 /* Example 24 (constdef.c) − An example of using constants (orig. Ivor Horton)*/

 int main(void)
 {
 float diameter = 0.0f;
 float radius = 0.0f;
 const float Pi = 3.14159f; /* Defines the value of Pi as fixed float but unlike a definition a constant has to be assigned from within a function*/

 printf("Input the diameter: ");
 scanf("%f", &diameter);

 radius = diameter/2.0f;
 printf("\nThe circumference is %.2f", 2.0f*Pi*radius);
 printf("\nThe area is %.2f", Pi*radius*radius);
 return 0;
 }