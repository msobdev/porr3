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
	for (int i = 0; i < p->size; i++) {
		if (p->evaluations[i] > EPS) {
			return false;
		}
	}
	return true;
}

bool isStopCondition(Population* p, int gen, float* averageEvaluation) {

	if (isNotChanging(p, gen, averageEvaluation) || isBelowEPS(p)) {
		return true;
	}
	return false;
}

void evolutionaryStrategyMuLambda(init init, OptimizingFunction optFunction) {
	FILE* fptr = fopen("hi.csv", "w");
	int gen = 0;
	float averageEvaluation = -10.0;
	Population basePopulation = initBasePopulation(init, optFunction);
	evaluatePopulation(&basePopulation, optFunction);
	Population offspringPopulation = allocateMemory(init.lambda, init.problemSize);
	for(gen = 1; gen < 50000; gen++){
		createOffspringPopulation(&basePopulation, &offspringPopulation);
		mutatePopulation(&offspringPopulation, optFunction);
		recombinatePopulation(&offspringPopulation);
		evaluatePopulation(&offspringPopulation, optFunction);
		saveToCsv(fptr, basePopulation, gen);
		createBasePopulation(&basePopulation, &offspringPopulation);
		viewStatistics(gen, offspringPopulation, 1);
		if (isStopCondition(&offspringPopulation, gen, &averageEvaluation)) {
			break;
		}
	}
	viewStatistics(gen, offspringPopulation, 0);
	fclose(fptr);
	freeMemory(&basePopulation, &offspringPopulation);	
}