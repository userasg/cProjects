#include <stdio.h>
 /* Example 10 (firstconvert.c) − first look at conversions (orig. S Kochan)*/
 int main()
 {
 float f1 = 123.125, f2;
 int i1, i2 = -150;
 i1 = f1; /*turning the i1 int value of -150 into a float value of -150.000000*/  
 printf("%f assigned to an INT produces %d \n", f1, i1);
 f1 = i2;
 printf("%d assigned to a FLOAT produces %f \n", i2, f1);
 f1 = i2 / 100;
 printf("%d divided by 100 produces %f \n", i2, f1);
 f2 = i2 / 100.0;
 printf("%d divided by 100.0 produces %f \n", i2, f2);
 return 0;
 }