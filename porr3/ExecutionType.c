#pragma once
#include <time.h>
#include "mpi.h"
#include "Utils.h"

/**
SETUP:
https://blogs.technet.microsoft.com/windowshpc/2015/02/02/how-to-compile-and-run-a-simple-ms-mpi-program/

RUN:
1. change EXECUTION in main.c to 2
2. Build solution
3. open console: Alt+Space from visual studio
4. cd Debug (for x86) or cd x64/Debug (for x64)
5. mpiexec -n <number_of_threads> porr3.exe
*/
void esMpi(int argc, char* argv[]) {
	MPI_Init(&argc, &argv);

	int rank, num_procs;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
	printf("rank: %d", rank);

	MPI_Finalize();
}
/**
SETUP for sequential:
change in windows TASK MANAGER/Details/Set affinity to 1 core
in project properties: C/C++/Multi-processor Compilation : 

SETUP for openmp:
in project properties: C/C++/Multi-processor Compilation : YES(/MP)

RUN:
Ctrl + F5
*/
void esSequentialOrOpenMP(init initES, OptimizingFunction fun) {
	clock_t start = clock(), diff;
	evolutionaryStrategyMuLambda(initES, fun);
	diff = clock() - start;
	convertTimeFromMiliseconds((int)(diff * 1000 / CLOCKS_PER_SEC));
}