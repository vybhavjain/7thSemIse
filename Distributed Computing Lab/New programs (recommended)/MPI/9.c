#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include <math.h>

#define SEED 12345678
#define N 100000

int main(){
  int rank, size;
  double x,y,z,val=0,count=0;

  MPI_Init(NULL,NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  srand(SEED+rank);
  for(int i=0;i<N;i++){
    x=(double)rand()/RAND_MAX;
    y=(double)rand()/RAND_MAX;
    z=x*x+y*y;
    if(z<=1){
      count++;
    }
  }
  MPI_Reduce(&count, &val,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
  if(rank==0){
    printf("PI:%lf\t",val/N);
  }
  MPI_Finalize();
  return 0;
}
