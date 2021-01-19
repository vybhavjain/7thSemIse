# 7th Semester ISE

Repository of codes for labs: 

1. Data Mining Laboratory
2. Distributed Computing Laboratory

## Commands to execute OpenMP programs:

Get necessary packages (one time step):

```bash
sudo apt-get update
audo apt-get upgrade
sudo apt-get install libopenmpi-dev libgd-dev
```

To compile and run codes:

```bash
gcc <filename>.c -fopenmp -lgd -lm
./a.out
```

## Commands to execute MPI programs:

Get necessary packages and setup (one time step):

```bash
sudo apt-get install mpich mpich-doc
sudo update-alternatives --config mpi #you may need to select a certain MPI installation
```

To compile and run codes:

```bash
mpicc <filename>.c
mpirun -np 4 ./a.out 
#try mpiexec if mpirun does not work
#try with -np 2 if 4 does not work 
```

## Commands to execute R codes:

Get necessary packages and setup (one time step):

```R
$ install.packages("<package-name>") #you may need to run this using root access in the R prompt, as the installation usually requires a file write
```

To compile and run codes:

```bash
$ R -f <file>.R
```
Alternatively, you may choose to run the R codes in R Studio.
