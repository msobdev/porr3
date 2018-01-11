#define _CRT_SECURE_NO_DEPRECATE
#include "ESmpi.h"
#include "mpi.h"

int gen, rank, num_procs;
float averageEvaluation;
Population basePop;
Population offspringPop;

void cleanupES() {
	viewStatisticsMPI(gen, offspringPop, true, rank);
	freeMemory(&basePop, &offspringPop);
}

void runES(OptimizingFunction optFunction) {
	gen++;
	createOffspringPopulation(&basePop, &offspringPop);
	mutatePopulationMPI(&offspringPop, optFunction, num_procs, rank);
	recombinatePopulation(&offspringPop);
	evaluatePopulation(&offspringPop, optFunction);
	createBasePopulation(&basePop, &offspringPop);
	viewStatisticsMPI(gen, offspringPop, false, rank);
}

void prepareES(init init, OptimizingFunction optFunction) {
	gen = 0;
	averageEvaluation = -10.0;
	basePop = initBasePopulationMPI(init, optFunction, num_procs, rank);
	evaluatePopulation(&basePop, optFunction);
	offspringPop = allocateMemory(init.lambda, init.problemSize);
}

void evolutionaryStrategyMuLambdaMPI(init init, OptimizingFunction optFunction) {

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
	
	prepareES(init, optFunction);
	do {
		runES(optFunction);
	} while (!isStopCondition(&offspringPop, gen, &averageEvaluation));
	cleanupES();
}