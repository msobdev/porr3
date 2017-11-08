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
		recombinatePopulation(&offspringPopulation);
		mutatePopulation(&offspringPopulation, optFunction);	
		evaluatePopulation(&offspringPopulation, optFunction);
		createBasePopulation(&basePopulation, &offspringPopulation);
		gen++;
		if (gen % 100 == 0) {
			viewStatistics(gen, &offspringPopulation);
		}
	}while(!isStopCondition(&offspringPopulation) && (gen < 50000));
	viewStatistics(gen, &offspringPopulation);
}