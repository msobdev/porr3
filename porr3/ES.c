#define _CRT_SECURE_NO_DEPRECATE
#include "ES.h"

bool isNotChanging(Population* p, int gen, float* averageEvaluation) {

	float currentAverageEvaluation = getAverage(p->evaluations, p->size);
	if (gen % 1000 == 0) {
		if (isFloatsEquals(averageEvaluation, &currentAverageEvaluation)) {
			return true;
		}
		*averageEvaluation = currentAverageEvaluation;
	}
	return false;
}

bool isBelowEPS(Population* p) {
//	for (int i = 0; i < p->size; i++) {
		if (p->evaluations[0] > EPS) {
			return false;
		}
//	}
	return true;
}

bool isBeyondLoopLimit(int gen) {
	return (gen >= LOOPLIMIT);
}

bool isStopCondition(Population* p, int gen, float* averageEvaluation) {

	if (isNotChanging(p, gen, averageEvaluation) || isBelowEPS(p) || isBeyondLoopLimit(gen)) {
		return true;
	}
	return false;
}

void evolutionaryStrategyMuLambda(init init, OptimizingFunction optFunction) {
	FILE* fptr = fopen(FILENAME, "w");
	int gen = 0;
	float averageEvaluation = 1.0;
	Population basePop = initBasePopulation(init, optFunction);
	evaluatePopulation(&basePop, optFunction);
	Population offspringPop = allocateMemory(init.lambda, init.problemSize);
	do{
		gen++;
		createOffspringPopulation(&basePop, &offspringPop);
		mutatePopulation(&offspringPop, optFunction);
		recombinatePopulation(&offspringPop);
		evaluatePopulation(&offspringPop, optFunction);
		saveToCsv(fptr, basePop, gen);
		createBasePopulation(&basePop, &offspringPop);
		viewStatistics(gen, basePop, false);
	} while (!isStopCondition(&basePop, gen, &averageEvaluation));
	viewStatistics(gen, basePop, true);
	fclose(fptr);
	freeMemory(&basePop, &offspringPop);	
}