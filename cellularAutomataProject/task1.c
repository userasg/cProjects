#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIZEBINARY 8 

char *transformArray(char *, int, int);
int newVal(int, int);
int main (int argc, char **argv){

int sizeInMemory = 0;
	char *p;
	int i,j;
	int generations;
	int rule;
/*command line checks*/
	/*number of arguements*/
	if(argc != 4){
		printf("ERROR: incorrect number of arguements\n");
		exit (EXIT_FAILURE); 
	};

	/*if correct type of arguements*/
	if(atoi(argv[1]) < 0){
		printf("ERROR: row number cannot be negative\n");
		exit (EXIT_FAILURE); 
	};

	if(atoi(argv[2]) < 0){
		printf("ERROR: generation number cannot be negative\n");
		exit (EXIT_FAILURE); 
	};

	if(atoi(argv[3]) < 0 || atoi(argv[3]) > 256){
		printf("ERROR: invalid rule number\n");
		exit (EXIT_FAILURE); 
	};


	/*allocating size in memory for initial array and assign variables*/
	sizeInMemory = atoi(argv[1]);
	generations = atoi(argv[2]);
	rule = atoi(argv[3]);

	p = (char *) calloc(sizeInMemory, sizeof(char));

	/*fill in intial array*/
	for (i=0; i < generations; i++){
	for(j=0; j < sizeInMemory; j++){
		p[j]=' ';
	}
}
	p[sizeInMemory/2]='*';
	
	transformArray(p, rule, generations);

	/*test some functions*/
	/*test print out*/
	for (i=0; i < generations; i++){
	for(j=0; j < sizeInMemory; j++){
		printf("%c", p[j]);
	}
	printf("\n");
}


   free(p);

 return 0;
}


char *transformArray(char *p, int rule, int generations){

/*test array got passed properly and can be changed from here*/
 int i =0;
 int shift =0;

	if(p[0]==' ' && p[i]=='*' && p[i+1]== ' '){
		shift = 2;
	}

	if(p[0]=='*' && p[i]=='*' && p[i+1]== ' '){
		shift = 3;
	}

	if(p[0]==' ' && p[i]==' ' && p[i+1]== '*'){
		shift = 4;
	}

	if(newVal(rule, shift)==1){
		p[i]='*';
	}

	if(newVal(rule, shift)==0){
		p[i]=' ';
	}
	
return p;

}


int newVal(int rule, int shift)
{
	int i = 0;
	int binaryRule[SIZEBINARY]={0,0,0,0,0,0,0,0};
	int shiftsBy = shift;
	for(i=0; i<8; i++)
	{
		binaryRule[i]=rule%2;
		rule=rule/2;
	}	

	return binaryRule[shiftsBy];
}