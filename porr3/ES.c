#include "ES.h"

void evolutionaryStrategyMuLambda(init init, OptimizingFunction optFunction) {
	int gen = 0;
	Population basePopulation = initBasePopulation(init, optFunction);
	evaluatePopulation(&basePopulation, optFunction);
	Population offspringPopulation = allocateMemory(init.lambda, init.problemSize);
	while (gen < 50){
		createOffspringPopulation(&basePopulation, &offspringPopulation);
		mutatePopulation(&offspringPopulation, optFunction);
		recombinatePopulation(&offspringPopulation);
		evaluatePopulation(&offspringPopulation, optFunction);
		createBasePopulation(&basePopulation, &offspringPopulation);
		gen++;
	}
	viewPopulation(offspringPopulation);
}