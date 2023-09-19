#include <stdio.h>
#include <math.h>
int main()
{
  int a, b, c, undersqroot; /*declaring the variables for the quadratic formula (if a b and c are ints then due to the fact that b^2-4ac is under the square root it has to be an int data type as well)*/
  double x1, x2; 

  printf("Enter a, b and c for ax^2 + bx + c = 0\n");
  scanf("%d%d%d", &a, &b, &c); /*scanning the users inputs all at once*/

  undersqroot = b*b - 4*a*c; /*this bit is the b^2-4ac*/

  if (undersqroot < 0)  
  {
    printf("error the variables you have entered produce imaginary roots")
   /*printf("First root = %f + i%f\n", -b/(double)(2*a), sqrt(-undersqroot)/(2*a));
    printf("Second root = %f - i%f\n", -b/(double)(2*a), sqrt(-undersqroot)/(2*a)); this was the original code but I didn't include it, I understand the algorithm used to determine the imaginary roots but I am unsure as to why 
there is a (double) included so I didn't want to use something I didn't understand. Personally, I would have used the formuale xy=c/a and x+y=-b/a where abc are the variables for the quadratic equation, and x and y are the roots x1 and x2
 xy= (c/a);
 x+y=(-b/a);
 a=(-b/x+y)
 a=c/xy
 I am unsure as to how to finsih this*/
  }
  else 
  { 
    x1 = (-b + sqrt(undersqroot))/(2*a);/*these produce real/repeated roots*/
    x2 = (-b - sqrt(undersqroot))/(2*a);

    printf("x = %f or\n", x1);
    printf("x = %f\n", x2);
  }

  return 0;
}

/*https://www.programmingsimplified.com/c/source-code/c-program-find-roots-of-quadratic-equation, used and then modified*/