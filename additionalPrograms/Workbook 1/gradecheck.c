 #include <stdio.h>
 int main()
 {
 int grade;
 printf("Enter your grade: ");
 scanf("%d", &grade);
 if (grade>100)
 printf("don't lie to yourself");
 else if (grade==100)
 printf("FULL MARKS");
 else if (grade >= 70)
 printf("You got a FIRST! \n");
 else if (grade>=60)
 printf("You got a 2:1 \n");
 else if (grade>=50)
 printf("You got a 2:2 \n");
 else if (grade >= 40)
 printf("You turned up! \n");
 else if (grade<0)
 printf("Stop trying");
 else printf("You failed \n");
 return 0;
 }