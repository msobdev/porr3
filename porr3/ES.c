#include "ES.h"

void evolutionaryStrategyMuLambda(init init, OptimizingFunction optFunction) {
	int gen = 0;
	Population basePopulation = initPopulation();
	evaluatePopulation(&basePopulation, optFunction);
	Population offspringPopulation;
	while (gen < 10){
		createOffspringPopulation(&offspringPopulation);
		mutatePopulation(&offspringPopulation);
		recombinatePopulation(&offspringPopulation);
		evaluatePopulation(&offspringPopulation, optFunction);
		createBasePopulation(&basePopulation, &offspringPopulation);
		gen++;
	}
}