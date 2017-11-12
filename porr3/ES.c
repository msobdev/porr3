#include "ES.h"

bool isStopCondition(Population* p) {

	for (int i = 0; i < p->size; i++) {
		if (p->evaluations[i] > EPS) {
			return false;
		}
	}
	return true;
}

void evolutionaryStrategyMuLambda(init init, OptimizingFunction optFunction) {
	int gen = 0;
	Population basePopulation = initBasePopulation(init, optFunction);
	evaluatePopulation(&basePopulation, optFunction);
	Population offspringPopulation = allocateMemory(init.lambda, init.problemSize);
	for(gen = 1; gen < 5000; gen++){
		createOffspringPopulation(&basePopulation, &offspringPopulation);
		mutatePopulation(&offspringPopulation, optFunction);
		recombinatePopulation(&offspringPopulation);
		evaluatePopulation(&offspringPopulation, optFunction);
		createBasePopulation(&basePopulation, &offspringPopulation);
		viewStatistics(gen, offspringPopulation, 1);
		if (isStopCondition(&offspringPopulation)) {
			break;
		}
	}
	viewStatistics(gen, offspringPopulation, 0);
	freeMemory(&basePopulation, &offspringPopulation);
}