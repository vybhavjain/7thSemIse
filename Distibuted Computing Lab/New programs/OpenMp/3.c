// Multitasking

#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double sines[1000];
int primes[1000];

 void prime_table ( int prime_num )
{
  int i,j,p,prime;
  i = 2;
  p = 0;
  while ( p <prime_num )
  {
    prime = 1;
    for ( j = 2; j <i; j++ )
    {
      if ( ( i % j ) == 0 )
      {
        prime = 0;
        break;
      }
    }      
    if ( prime )
    {
      primes[p] = i;
      p = p + 1;
    }
    i = i + 1;
  }
}

void sine_table ( int sine_num )
{
  int i,j;
  double a,pi = 3.141592653589793;
  for ( i = 0; i<sine_num; i++ )
  {
    sines[i] = 0.0;
    for ( j = 0; j <= i; j++ )
    {
      a = ( double ) ( j ) * pi / ( double ) ( sine_num - 1 );
      sines[i] = sines[i] + sin ( a );
    }
  }
}

void main(){
	int size,z,y;
	printf("Enter the the number of primes and sine table values required : \n");
	scanf("%d",&size);
	#pragma omp parallel sections
	{
		#pragma omp section
		{
			prime_table(size);
			for( y=0;y<size;y++){
				printf("%d \n",primes[y]);
			}
		}
		#pragma omp section
		{
			sine_table(size);
			for( z=0;z<size;z++){
				printf("%lf \n",sines[z]);
			}
		}
	}
}
