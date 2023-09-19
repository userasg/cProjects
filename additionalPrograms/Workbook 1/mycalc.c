 #include <stdio.h>
 /* Example 17 (mycalc.c) − creating your first calculator (orig. S Kochan)*/
 int main()
 {
 float firstNum, secNum;
 char operator;
 printf("Enter your sum: \n");
 scanf("%f %c %f", &firstNum, &operator, &secNum);
 if (operator == '+')
 printf("%0.2f \n", firstNum + secNum);
 else if (operator == '-')
 printf("%0.2f \n", firstNum - secNum);
 else if (operator == '*')
 printf("%0.2f \n", firstNum * secNum);
 else if (operator == '/')
 if (secNum == 0)
 printf("Cant divide by zero\n");
 else
 printf("%0.2f \n", firstNum / secNum);
 else
 printf("Error, unknown operator \n");
 return 0;
 }