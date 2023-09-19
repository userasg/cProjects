#include <stdio.h>
#include <stdlib.h>
int nCr (int a, int b){
 unsigned long i,n=1,r=1,y,numn, numr, z=1, sumtotal;

 numn=a;
 numr=b;
    for(i=1;i<=numn;i++){
        n=n*i;
};

    for(i=1;i<=numr;i++){
        r=r*i;
};

y=numn-numr;

for(i=1;i<=y;i++){
        z=z*i;
};

sumtotal= (n/(r*z));
printf("   %.0lu", sumtotal);
return sumtotal;
}

int main(int argc, char **argv){    
int i,j,x; 
x = strtol(argv[1], NULL, 10);
x=x-1;
for ( i = x; i >= 0; i --) {
    for ( j = 0; j <= i ; j ++) {
         nCr(i,j);
         }
 printf ("\n");
 }
return 0;
}
