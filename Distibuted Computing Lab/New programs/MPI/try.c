#include <stdio.h>
#include "mpi.h"
#include <string.h>

int main(int argc, char *argv[])
{
    int my_rank;
    int size;
    MPI_Init(0,0); /*START MPI */
    /*DETERMINE RANK OF THIS PROCESSOR*/
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    /*DETERMINE TOTAL NUMBER OF PROCESSORS*/
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    printf("Hello world! I'm rank (processor number) %d of %d processor \n", my_rank, size);
    MPI_Finalize(); /* EXIT MPI */
    return 0;
}
