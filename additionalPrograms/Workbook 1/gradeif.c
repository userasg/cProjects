 #include <stdio.h>
 /* Example 14 (gradeif.c) − using if else statements */
 int main()
 {
 int grade;
 printf("Enter your grade: ");
 scanf("%d", &grade);
 if (grade >= 70)
 printf("You got a FIRST! \n");
 else if (grade>=60)
 printf("You got a 2:1 \n");
 else if (grade>=50)
 printf("You got a 2:2 \n");
 else if (grade >= 40)
 printf("You turned up! \n");
 else printf("You failed \n");
 return 0;
 }
 /*Try removing the ’else’s
  int main()
 {
    int grade;
 printf("Enter your grade: ");
 scanf("%d", &grade);
 if (grade >= 70)
 printf("You got a FIRST! \n");
  if (grade>=60 && grade<70 )
 printf("You got a 2:1 \n");
  if (grade>=50 && grade<60)
 printf("You got a 2:2 \n");
  if (grade >= 40 && grade <50)
 printf("You turned up! \n");
 if (grade==0)
  printf("You failed \n");
 return 0;
 }
 */
 