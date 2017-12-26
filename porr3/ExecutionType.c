#pragma once
#include <time.h>
#include "mpi.h"
#include "Utils.h"

/**
SETUP:
in project properties: C/C++/Multi-processor Compilation : YES(/MP)
RUN:
Ctrl + F5
*/
void esOpenMP(init initES, OptimizingFunction fun) {
	printf("EVOLUTIONARY STRATEGY OPENMP:\n\n");
	clock_t start = clock(), diff;
	evolutionaryStrategyMuLambda(initES, fun);
	diff = clock() - start;
	convertTimeFromMiliseconds((int)(diff * 1000 / CLOCKS_PER_SEC));
}
/**
SETUP:
https://blogs.technet.microsoft.com/windowshpc/2015/02/02/how-to-compile-and-run-a-simple-ms-mpi-program/
RUN:
from CMD
*/
void esMpi(int argc, char* argv[]) {
	MPI_Init(&argc, &argv);

	int rank, num_procs;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
	

	MPI_Finalize();
}
/**
SETUP:
change in windows TASK MANAGER/Details/Set affinity to 1 core
RUN:
Ctrl + F5
*/
void esSequential(init initES, OptimizingFunction fun) {
	printf("EVOLUTIONARY STRATEGY SEQUENTIAL:\n\n");
	clock_t start = clock(), diff;
	evolutionaryStrategyMuLambda(initES, fun);
	diff = clock() - start;
	convertTimeFromMiliseconds((int)(diff * 1000 / CLOCKS_PER_SEC));
}