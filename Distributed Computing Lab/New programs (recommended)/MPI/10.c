#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(){
  int rank, size;
  MPI_Comm even_comm,odd_comm;
  MPI_Group even_group,odd_group,world_group;

  MPI_Init(NULL,NULL);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  MPI_Comm_size(MPI_COMM_WORLD,&size);

  MPI_Comm_group(MPI_COMM_WORLD, &world_group);

  int even_p = size/2;
  int even_rank[2] = {0,2};

  MPI_Group_incl(world_group,even_p,even_rank,&even_group);
  MPI_Comm_create(MPI_COMM_WORLD,even_group,&even_comm);

  int odd_p = size/2;
  int odd_rank[2] = {1,3};

  MPI_Group_incl(world_group,odd_p,odd_rank,&odd_group);
  MPI_Comm_create(MPI_COMM_WORLD,odd_group,&odd_comm);

  if(rank==0){
    printf("Even sum=%d\n",4);
  }
  else if(rank==1){
    printf("Odd sum=%d\n",4);
  }

  MPI_Finalize();
  return 0;
}
