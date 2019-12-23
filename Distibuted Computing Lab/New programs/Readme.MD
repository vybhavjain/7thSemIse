# DC-Lab
These are the programs for Distributed computing lab.

Executing steps:

A) For openmp programs 

```
gcc <filename>.c -fopenmp
./a.out
```

B) For mpi programs

```
mpicc <filename>.c -o <filename>
mpirun -np 4 ./<filename>
```
