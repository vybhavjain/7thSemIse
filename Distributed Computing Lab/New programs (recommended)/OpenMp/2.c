#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{ 
	int NoofRows, NoofCols, Vectorsize, i, j; 

	printf("Read the matrix size no ofrows and columns and vectorsize\n"); 
	scanf("%d%d%d", &NoofRows, &NoofCols, &Vectorsize); 

	int Matrix[NoofRows][NoofCols],Vector[Vectorsize], Result[Vectorsize];

	if (NoofRows<= 0 || NoofCols<= 0 || Vectorsize<= 0 || NoofCols != Vectorsize) 
	{ 
		printf("The Matrix and Vectorsize should be of positive sign\n"); 
		exit(0); 
	}

	for (i = 0; i<NoofRows; i++)
		for (j = 0; j <NoofCols; j++) 
			Matrix[i][j] = i + j;

	printf("The Matrix is \n"); 
	for (i = 0; i<NoofRows; i++)
	{ 
		for (j = 0; j <NoofCols; j++) 
			printf("%d \t", Matrix[i][j]); 
		printf("\n"); 
	}
	for (i = 0; i<Vectorsize; i++) 
		Vector[i] = i; 

	printf("\n"); 
	printf("The Vector is \n"); 
	for (i = 0; i<Vectorsize; i++) 
		printf("%d \t", Vector[i]); 

	for (i = 0; i<NoofRows; i = i + 1) 
		Result[i]=0; 
	
	#pragma omp parallel for private(j)
		for (i = 0; i<NoofRows; i++)
			for (j = 0; j <NoofCols; j++)
				Result[i] = Result[i] + Matrix[i][j] * Vector[j];

	printf("\nThe Matrix Computation result is \n"); 
	for (i = 0; i<NoofRows; i++) 
		printf("%d \t", Result[i]); 

	return 0;
} 
