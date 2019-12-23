# DC-Lab
These are the programs for Distributed computing lab.

Executing steps:
A) For openmp programs (with ```#include<omp.h>``` in headers)

```
gcc <filename>.c -fopenmp
./a.out
```

B) For mpi programs (with ```#include<mpi.h>``` in headers)
```
mpicc <filename>.c -o <filename>
mpirun -np 4 ./<filename>
```
