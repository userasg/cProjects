#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#define MAX_LINE 512

int countLines(FILE *);
double calcSum(int, FILE *);
double calcSd(double, int, int, FILE *);

int main (int argc, char **argv){

	FILE *fp1, *fp2; 
	int totalStudents, totalActivities, totalAbsents;
	double mean,sd;


/*sanity checks*/
/*number of arguements*/
	if(argc != 3){
		fprintf(stderr, "ERROR: incorrect number of arguements\n");
		return 1; 
	}

/*uses access to check the type of arguement*/
	if(access(argv[1], R_OK) == -1){
		fprintf(stderr, "ERROR: incorrect file type 1\n");
		return 1;
	}

	if(access(argv[2], R_OK) == -1){
		fprintf(stderr, "ERROR: incorrect file type 2\n");
		return 1;
	}

/*checks file entered in right way*/
	if(strlen(argv[1])>strlen(argv[2])){
		fprintf(stderr, "ERROR: incorrect file positions\n");
		return 1;
	}

	



	/*open the files and set pointers to them*/
	fp1 = fopen(argv[1], "r");
	fp2 = fopen(argv[2], "r");


	/*further error checks on the pointers*/
	if(!fp1){
		fprintf(stderr, "file not found %s \n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if(!fp2){
		fprintf(stderr, "file not found %s \n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/*passing the file pointer for argv[1] fp1 to the countlines function to count number of students*/
	totalStudents = countLines(fp1);
	/*
	printf("total students are %d \n", totalStudents);
	*/
	totalActivities = countLines(fp2);
	/*
	printf("total activities are %d \n", totalActivities);
	*/
	totalAbsents = totalStudents-totalActivities;

	rewind(fp2);
	/*passing the number of lines and file pointer for the second file for the grade array and then set a local pointer to the new array*/
	mean = calcSum(totalActivities, fp2)/totalStudents;
	/*printing to check the pointertoGradesArray*/
    /*printf("%p ------here is the grades pointer \n", pointertoGradesArray);*/

	rewind(fp2);
	sd=calcSd(mean,totalActivities, totalStudents, fp2);

printf("total students = %d\n", totalStudents);
printf("absent students = %d\n",totalAbsents);
printf("grade mean = %.2f\n", mean);
printf("grade sd = %.2f\n", sd);
	

fclose(fp1);
fclose(fp2);

return 0;
}




/*===============Count lines to see number of the file -1===================*/
int countLines(FILE *filePointer){
	char line[MAX_LINE];
	int totalLines = -1; 

	/*debug statements to see if fp1 pointer was passed properly*/
	
	/*printf("%p \n", filePointer);*/
	/*while (fgets(line, MAX_LINE, filePointer)){
		printf("%s", line);
	}
	*/

	while (fgets(line, MAX_LINE, filePointer)){
		totalLines++;
	}

	/*dedug here to see if calculating the total students properly*/
	/*printf("%d \n", totalLines);*/

 return totalLines;
}




/*=========Store the grades in an integer array and return the pointer to the integer array we made=========*/
double calcSum(int totalLines, FILE *filePointer){
  int *grades;
  char line[MAX_LINE];
  int i=0;
  double sum=0, f;
  unsigned int l;

  /*dynamically creating an integer array based on the number of lines*/
  grades = (int *) calloc(MAX_LINE, sizeof(int));

  /*debug to check the grades pointer*/
  /*printf("%p------ here is grades pointer \n", grades);*/
  /*checks to see if the pointers are pointing to the right places the second pointer should be the same as above*/
  /*printf("%p------ here is grades pointer \n%p ------ here is the file pointer\n", grades, filePointer);*/

  /*this while loop is standard looping through the csv file*/
  while (fgets(line, MAX_LINE , filePointer)){
  	/*fscanf will take 2 of the input values recognised as the data types and assign them to the variables l and d*/
  fscanf(filePointer, "%u,%le", &l,&f);  
  /*then put in grades array*/
  grades[i]=f;
  i++;
}

/* debugging to test out if fscanf worked properly
printf("---trying to prints grade array---\n");
*/
for(i=0; i<totalLines; i++){
 /*printf("----grades alone---- %d \n", grades[i]);  */
 sum+=grades[i];
}
/*
 printf("----THIS IS THE FIRST GRADE---- %d \n", grades[0]); 
*/
/*
printf("---trying to a total sum %f---\n",sum);
*/

  free(grades);
  return sum;
} 


double calcSd(double mean,int totalActivities, int totalStudents, FILE *filePointer){
  int *grades;
  char line[MAX_LINE];
  int i=0;
  double sd=0, f=0;
  double sumX=0, sumX2=0;
  double a=0;
  unsigned int l;
  grades = (int *) calloc(MAX_LINE, sizeof(int));

  while (fgets(line, MAX_LINE , filePointer)){
  fscanf(filePointer, "%u,%le", &l,&f);
  grades[i]=f;
  i++;
  sumX+=f;
  /*printf("LOOK HERE %f \n", f);*/
	sumX2+=(f)*(f);
}

 sumX=sumX-f;
 sumX2=sumX2-(f*f);


	
	
	a=((sumX)*(sumX))/totalStudents;
	sd=sqrt(((sumX2-a)/totalStudents));
	
	/*printf("this is sumX %f \n", sumX);
	printf("this is sumX2 %f \n", sumX2);
		 printf("this is a %f\n",a); 
		  printf("this is sd %f\n",sd);*/
  free(grades);
  return sd;
} 