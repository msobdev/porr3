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
	do{
		createOffspringPopulation(&basePopulation, &offspringPopulation);
		mutatePopulation(&offspringPopulation, optFunction);
		recombinatePopulation(&offspringPopulation);
		evaluatePopulation(&offspringPopulation, optFunction);
		createBasePopulation(&basePopulation, &offspringPopulation);
		gen++;
	}while(!isStopCondition(&offspringPopulation) || (gen < 1500));
	viewPopulation(offspringPopulation);
}