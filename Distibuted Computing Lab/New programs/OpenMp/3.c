// Multitasking

#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int *prime_table ( int prime_num )
{
  int i,j,p,prime;
  int primes[1000];
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
  return primes;
}
double *sine_table ( int sine_num )
{
  double a;
  int i,j;
  double sines[10000];
  double pi = 3.141592653589793;
  for ( i = 0; i<sine_num; i++ )
  {
    sines[i] = 0.0;
    for ( j = 0; j <= i; j++ )
    {
      a = ( double ) ( j ) * pi / ( double ) ( sine_num - 1 );
      sines[i] = sines[i] + sin ( a );
    }
  }
  return sines;
}
int main(){
	int size,z,x,y;
	scanf("%d",&size);
	#pragma omp parallel sections
	{
		#pragma omp section
		{
			int *a =(int*)malloc(size*sizeof(int));
			a=prime_table(size);
			for( y=0;y<size;y++){
				printf("%d\n",a[y]);
			}
		}
		#pragma omp section
		{
			double *b=(double*)malloc(size*sizeof(double));
			b=sine_table(size);
			for( z=0;z<size;z++){
				printf("%lf \n",b[z]);
			}
		}
	}
	return 0;
}
