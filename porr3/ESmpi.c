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

void runES(OptimizingFunction optFunction, init init) {
	gen++;
	createOffspringPopulation(&basePop, &offspringPop);
	mutatePopulationMPI(&offspringPop, optFunction, num_procs, rank);
	recombinatePopulation(&offspringPop);
	evaluatePopulation(&offspringPop, optFunction);
	createBasePopulation(&basePop, &offspringPop);
	sendIndividual(&basePop, init);
	viewStatisticsMPI(gen, basePop, false, rank);
}

void sendIndividual(Population* population, init init) {
	MPI_Request	send_request, recv_request;
	MPI_Status status;
	float* individual = DYNALLOC(init.problemSize, float);
	int randNumber = gen % num_procs;
	//if (gen % 10 == 0) {
		if (rank != randNumber) {
			MPI_Irecv(individual, init.problemSize, MPI_FLOAT, randNumber, 0, MPI_COMM_WORLD, &recv_request);
			MPI_Wait(&recv_request, &status);
			memcpy(population->individual[init.mu - 1], individual, init.problemSize * sizeof(float));
		} else {
			memcpy(individual, population->individual[0], init.problemSize * sizeof(float));
			for (int i = 0; i < num_procs; i++) {
				if (randNumber != i) {
					MPI_Isend(individual, init.problemSize, MPI_FLOAT, i, 0, MPI_COMM_WORLD, &send_request);
				}
			}
		}
	//}
}

void prepareES(init init, OptimizingFunction optFunction) {
	gen = 0;
	averageEvaluation = 1.0;
	basePop = initBasePopulationMPI(init, optFunction, num_procs, rank);
	evaluatePopulation(&basePop, optFunction);
	offspringPop = allocateMemory(init.lambda, init.problemSize);
}

void evolutionaryStrategyMuLambdaMPI(init init, OptimizingFunction optFunction) {

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
	
	prepareES(init, optFunction);
	do {
		runES(optFunction, init);
	} while (!isStopCondition(&basePop, gen, &averageEvaluation));
	cleanupES();
}