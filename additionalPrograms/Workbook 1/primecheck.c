#include <stdio.h>
#include <math.h>

int main()
{
int inputNum,counter,halfNum=0;
int check0=0;
printf("Enter a number: ");
scanf("%d", &inputNum);
halfNum=inputNum/2;
counter=2;
while (counter <= halfNum)
{
if(inputNum%counter==0)
printf("Not PRIME");
counter++;
}
if (inputNum%counter!=0)
printf ("PRIME");
return 0;
}
