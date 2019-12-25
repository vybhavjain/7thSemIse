//Search F(J) = C

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<mpi.h>

int f(int i) //Can be any fuction value
{
    int value = i * i;       
    return value;
}

int search(int a, int b, int c, int id, int p)
{
    int fi,i,j=-1;
    for(i=a+id;0<i&&i<=b;i+=p)
	{
        fi=f(i);
        if(fi==c){
            j=i;
            break;
        }
    }
    return j;
}


void main(int argc, char* argv[])
{
    int a,b,c,id,j,p;
    double wtime;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    
    a=1; b=10000000; c=49;  // C should be a perfect square to get a result 
    
    if(id==0)
        printf("A=%d,\tB=%d,\tC=%d\n",a,b,c);
    
    wtime=MPI_Wtime();
    j=search(a,b,c,id,p);
    wtime=MPI_Wtime()-wtime;
    
    if(j!=-1)
        printf("Process %d found. J=%d\nVerify F(j)=%d\nTime taken %lf\n",id,j,f(j),wtime);
    
    MPI_Finalize();
}
