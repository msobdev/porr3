#define _CRT_SECURE_NO_DEPRECATE
#include "ESmpi.h"

FILE* fptr;
int gen;
float averageEvaluation;
Population basePop;
Population offspringPop;

void cleanupES() {
	viewStatistics(gen, offspringPop, true);
	fclose(fptr);
	freeMemory(&basePop, &offspringPop);
}

void runES(OptimizingFunction optFunction) {
	gen++;
	createOffspringPopulation(&basePop, &offspringPop);
	saveToCsv(fptr, basePop, gen);
	mutatePopulation(&offspringPop, optFunction);
	recombinatePopulation(&offspringPop);
	evaluatePopulation(&offspringPop, optFunction);
	createBasePopulation(&basePop, &offspringPop);
	viewStatistics(gen, offspringPop, false);
}

void prepareES(init init, OptimizingFunction optFunction) {
	fptr = fopen(FILENAME, "w");
	gen = 0;
	averageEvaluation = -10.0;
	basePop = initBasePopulation(init, optFunction);
	evaluatePopulation(&basePop, optFunction);
	offspringPop = allocateMemory(init.lambda, init.problemSize);
}

void evolutionaryStrategyMuLambdaMPI(init init, OptimizingFunction optFunction) {
	prepareES(init, optFunction);
	do {
		runES(optFunction);
	} while (!isStopCondition(&offspringPop, gen, &averageEvaluation));
	cleanupES();
}