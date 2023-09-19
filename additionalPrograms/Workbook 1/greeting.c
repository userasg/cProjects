#include<stdio.h>
#include<time.h> /*requires the use of a time library*/

int main()
{
int hour;
char name[100000]; /*to generate strings in c you have to declare a large array of characters*/
time_t my_time; /*gets the raw time of the system*/
struct tm * timeinfo; /*the value of the timer is broken up into the structure declared as ™ and then converted into the local time zone. Struct tm is used to hold the local date and time */
time (&my_time);  /*converts into time format*/
timeinfo = localtime (&my_time); /*converts my time to local time*/
hour= timeinfo->tm_hour; /*extracts the hour from the local time using the tm structure from earlier*/
hour=hour+1; /*since my local time being displayed was an hour early I had to add an hour on*/
printf("Enter name: \n");
scanf("%s", name); /*%s is for strings*/
printf("hour->%d\n",hour);
if (hour>=0 && hour<=12)
printf ("good morning %s\n",name);
else if (hour>=12 && hour<=18)
printf ("good afternoon %s\n",name);
else if (hour>=18 && hour<=24)
printf ("good evening %s\n",name);
else 
printf("sorry i have broken");
return 0;
}

/*https://stackoverflow.com/questions/5141960/get-the-current-time-in-c was used to understand how to get the current time*/