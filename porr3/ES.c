#include "ES.h"

void evolutionaryStrategyMuLambda(init init, OptimizingFunction optFunction) {
	int gen = 0;
	Population basePopulation = initPopulation(init, optFunction);
	evaluatePopulation(&basePopulation, optFunction, init.problemSize);
	viewPopulation(basePopulation, init.problemSize);
	Population offspringPopulation;
	while (gen < 5){
		//createOffspringPopulation(&offspringPopulation);
		//mutatePopulation(&offspringPopulation);
		//recombinatePopulation(&offspringPopulation);
		//evaluatePopulation(&offspringPopulation, optFunction);
		//createBasePopulation(&basePopulation, &offspringPopulation);
		gen++;
		printf("gen: %d\n", gen);
	}
}