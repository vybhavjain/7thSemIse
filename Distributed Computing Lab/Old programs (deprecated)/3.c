//Add 2 arrays

#include<omp.h>
#include<stdio.h>

void main() 
{
	int a[100],b[100],c[100],sum,i;
	for(i=0;i<100;i++)
	    a[i] = b[i] = i;
    #pragma omp parallel for reduction(+:sum)
    for(i=0;i<100;i++) {
        sum = sum + a[i] + b[i];
        c[i] = sum;
    }
    for(i=0;i<10;i++)
        printf("%d\n",c[i]);
	
}
