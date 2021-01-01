# DC-Lab

Executing steps:

A) For openmp programs 

```
gcc <filename>.c -fopenmp
./a.out
```

You may additionally need to reconfigure your GCC installation to include openmp binaries.

B) For mpi programs

```
mpicc <filename>.c -o <filename>
mpirun -np 4 ./<filename>
```
