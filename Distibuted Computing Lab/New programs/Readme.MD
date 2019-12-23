# DC-Lab
These are the programs for Distributed computing lab.

Executing steps:
A) For openmp programs (with ```#include<omp.h>``` in headers)
1) General
```
gcc <filename>.c -fopenmp
./a.out
```
2) If it has additional ```#include<math.h>``` in header
```
gcc <filename>.c -fopenmp -lm
./a.out
```

B) For mpi programs (with ```#include<mpi.h>``` in headers)
1) General
```
mpicc <filename>.c -o <filename>
mpirun -np 4 ./<filename>
```
2) If it has additional ```#include<math.h>``` in headers
```
mpicc <filename>.c -o <filename> -lm
mpirun -np 4 ./<filename>
```

C) Special Cases
1) For program5.c to execute after compiling
```
./a.out <number_of_points> <number_of_threads>
```
[Advised to use discrete number of threads to prevent Segmentation Fault]

2) For program6.c 
```
gcc program6.c -fopenmp -lgd
./a.out <inputfile>.png <ouputfile>.png <number_of_threads>
```
