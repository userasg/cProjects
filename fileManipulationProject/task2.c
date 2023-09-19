#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

#define SIZE 512
#define LENGTH_FILE 10

int countLines(FILE *);

int main (int argc, char **argv){


/*cant solve how to input names using strtok or fscanf but 
will print grades out in student order with student id*/
/*tried to print out name and store name using strtok and fscanf and store the token/value in a dynamic array
but didnt work*/


  FILE *fp1;
  FILE *fp2;
  int *grades;
  int *idsStudents;
  int total;
  int d, d2, i=0;
  char line[SIZE];
  int f;
  /*char *snames[SIZE];==========DIDNT WORK=========*/

  fp1 = fopen(argv[1], "r");
  fp2 = fopen(argv[2], "r");
  
  /*names = (char *) calloc(SIZE, sizeof(char *));*/

  idsStudents = (int *) calloc(SIZE, sizeof(int));
  /*idsActivities = (int *) calloc(SIZE, sizeof(int));*/
  grades = (int *) calloc(SIZE, sizeof(int));

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


  total=countLines(fp1);
/*
 printf("===THIS IS THE STUDENTS ID AND NAME===\n"); 
*/

  rewind(fp1);

  while (fgets(line, SIZE , fp1)){
        /*snames[i]=malloc(128);=======DIDNT WORK======*/
  fscanf(fp1, "%d",&d); 
       idsStudents[i]=d;
      i++;

  }

  i=0;



/*
 printf("===THIS IS THE ACTIVITIES - ID AND GRADE===\n");
 */
  while (fgets(line, SIZE , fp2)){
  fscanf(fp2, "%d,%d", &d2,&f);  
 /* printf("id[%d] = %d\n",i, d2);
  printf("grade[%d] = %d\n",i, f);*/

    for(i=0;i<total;i++){
    if(idsStudents[i]==d2){
       grades[i]=f;
    }
  }
  i++;
}


 for(i=0;i<total;i++){

      printf("%d, %d\n",idsStudents[i], grades[i]);

  }


fclose(fp1);
fclose(fp2);
free(idsStudents);

free (grades);


return 0;
}

/*===============Count lines to see number of the file -1===================*/
int countLines(FILE *filePointer){
  char line2[SIZE];
  int totalLines = -1; 

  /*debug statements to see if fp1 pointer was passed properly*/
  
  /*printf("%p \n", filePointer);*/
  /*while (fgets(line, MAX_LINE, filePointer)){
    printf("%s", line);
  }
  */

  while (fgets(line2, SIZE, filePointer)){
    totalLines++;
  }

  /*dedug here to see if calculating the total students properly*/
  /*printf("%d \n", totalLines);*/

 return totalLines;
}
