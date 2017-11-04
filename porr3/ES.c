#include "ES.h"

void evolutionaryStrategyMuLambda(init init, OptimizingFunction optFunction) {
	int gen = 0;
	Population basePopulation = initBasePopulation(init, optFunction);
	evaluatePopulation(&basePopulation, optFunction);
	Population offspringPopulation = allocateMemory(init.lambda, init.problemSize);
	viewPopulation(basePopulation);
	while (gen < 3){
		createOffspringPopulation(&basePopulation, &offspringPopulation);
		//mutatePopulation(&offspringPopulation);
		//recombinatePopulation(&offspringPopulation);
		//evaluatePopulation(&offspringPopulation, optFunction);
		//createBasePopulation(&basePopulation, &offspringPopulation);
		gen++;
		printf("gen: %d\n", gen);
	}
	viewPopulation(offspringPopulation);
}