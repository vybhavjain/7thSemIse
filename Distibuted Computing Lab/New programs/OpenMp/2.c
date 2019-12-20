#include <stdio.h>
#include <omp.h>

main()
{ 
int NoofRows, NoofCols, Vectorsize, i, j; 

printf("Read the matrix size noofrows and columns and vectorsize\n"); 
scanf("%d%d%d", &NoofRows, &NoofCols, &Vectorsize); 

int Matrix[NoofRows][NoofCols],Vector[Vectorsize], Result[Vectorsize] ;

if (NoofRows<= 0 || NoofCols<= 0 || Vectorsize<= 0) 
{ 
printf("The Matrix and Vectorsize should be of positive sign\n"); 
exit(1); 
} 

if (NoofCols != Vectorsize) 
{ 
printf("Matrix Vector computation cannot be possible \n"); 
exit(1); 
} 


for (i = 0; i<NoofRows; i++)
{ 
for (j = 0; j <NoofCols; j++) 
Matrix[i][j] = i + j; 
} 

/* Printing The Matrix */ 
printf("The Matrix is \n"); 
for (i = 0; i<NoofRows; i++)
{ 
for (j = 0; j <NoofCols; j++) 
printf("%d \t", Matrix[i][j]); 
printf("\n"); 
} 
printf("\n"); 

for (i = 0; i<Vectorsize; i++) 
Vector[i] = i; 
printf("\n"); 

/* Printing The Vector Elements */ 
printf("The Vector is \n"); 
for (i = 0; i<Vectorsize; i++) 
printf("%d \t", Vector[i]); 

for (i = 0; i<NoofRows; i = i + 1) 
{ 
Result[i]=0; 
} 

/* OpenMP Parallel Directive */ 
omp_set_num_threads(32); 
#pragma omp parallel for private(j) 
for (i = 0; i<NoofRows; i = i + 1) 
for (j = 0; j <NoofCols; j = j + 1) 
Result[i] = Result[i] + Matrix[i][j] * Vector[j]; 

printf("\nThe Matrix Computation result is \n"); 
for (i = 0; i<NoofRows; i++) 
printf("%d \n", Result[i]); 
} 

