#include <stdio.h>
#include "convert_integer.h"



/*calculates what day a particular date is*/
int calcWeekDay (int year, int ordinalDay){
   int x = year-1; 
   int weekDay;
   /*gauss is the weekday of 1st jan based on year*/
   int gauss = (1+5*(x%4)+4*(x%100)+6*(x%400))%7;
   if (gauss==1){
    weekDay = (ordinalDay%7);
   }
   if (gauss==0){
    weekDay = ((ordinalDay-1)%7);
   }
   if (gauss==2){
    weekDay = ((ordinalDay+1)%7);
   }
   if (gauss==3){
    weekDay = ((ordinalDay+2)%7);
   }
   if (gauss==4){
    weekDay = ((ordinalDay+3)%7);
   }
   if (gauss==5){
    weekDay = ((ordinalDay+4)%7);
   }
   if (gauss==6){
    weekDay = ((ordinalDay+5)%7);
   }
   if (weekDay==0){
    weekDay=7;
   }
    return weekDay;
}


/*calculates the week in the year of the specific date*/
int calcWeekWeek (int weekDay, int ordinalDay, int year){
int weeksinYearInitial;
weeksinYearInitial = (ordinalDay-weekDay+10)/7;
return weeksinYearInitial;
}

/*p + how many total weeks function*/
int totalWeeksInYear(int year){
int a;
int b;
int totalWeeksInYear;
int x;
x = year-1;
a = (year+year/4-year/100+year/400)%7;
b = (x+x/4-x/100+x/400)%7;
if (a==4 || b==3){
totalWeeksInYear = 53;
}
else{
    totalWeeksInYear = 52;
}
return totalWeeksInYear;
}

/*applies adjustment logic*/
unsigned long checkWeek (int weeksinYear, int totalWeeksInYear, int weekDay){
    if (weeksinYear == 0 ){
        weeksinYear = totalWeeksInYear;
    }
    if ((weeksinYear > totalWeeksInYear) && weekDay<4){
        weeksinYear = 1;
    }
return weeksinYear;
}

int checkYear(int month, int weeksinYear, int year){
    if(month==12 && weeksinYear==1){
        year = year+1;
    }
     if(month==1 && (weeksinYear==52 || weeksinYear==53)){
        year = year-1;
    }
return year;
}

/*calculates ordinal date*/
unsigned long calculateOrdinalDate(int day,int month,int year){
int div_4 = year % 4;
int div_100 = year % 100;
int div_400 = year % 400;
unsigned long ordinalDay ;
    if (month == 1){
        ordinalDay = day;
    }

	if (month == 2){
        ordinalDay = day +31;
    }

    if ((month == 3 || month == 4 || month == 5 || month == 6 || month == 7 || month == 8 || month == 9 || month == 10 || month == 11 || month == 12) && ((div_4 == 0 && div_100 !=0) || div_400 == 0)){
        ordinalDay=(30.6*month-91.4)+day+60;

    }
    else if ((month == 3 || month == 4 || month == 5 || month == 6 || month == 7 || month == 8 || month == 9 || month == 10 || month == 11 || month == 12)) {
        ordinalDay=(30.6*month-91.4)+day+59;

    }

    return ordinalDay;
}

int main(int argc, char **argv){
unsigned long day, month, year;

  day = get_integer();
  month = get_integer();
  year = get_integer();
/*commit test*/
    printf("%02lu-%02lu-%02lu\n", year,month,day);
    printf("%02lu-%03lu\n", year, calculateOrdinalDate(day,month,year));
    printf("%d-W%02lu-%d\n", checkYear(month,checkWeek(calcWeekWeek(calcWeekDay(year,calculateOrdinalDate(day,month,year)),calculateOrdinalDate(day,month,year),year), totalWeeksInYear(year),calcWeekDay(year,calculateOrdinalDate(day,month,year))),year),     checkWeek(calcWeekWeek(calcWeekDay(year,calculateOrdinalDate(day,month,year)),calculateOrdinalDate(day,month,year),year), totalWeeksInYear(year-1),calcWeekDay(year,calculateOrdinalDate(day,month,year)) ),      calcWeekDay(year,calculateOrdinalDate(day,month,year)));
    return 0;
}

