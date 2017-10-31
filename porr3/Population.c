#include "Population.h"
#include "Ackley.h"
#include "Griewank.h"

void evaluatePopulation(Population* population, OptimizingFunction optimizingFunction) {

	switch(optimizingFunction) {
	case GRIEWANK:
		printf("GRIEWANK EVALUATION\n");
		evaluateGriewankPopulation(population);
		break;
	case ACKLEY:
		printf("ACKLEY EVALUATION\n");
		evaluateAckleyPopulation(population);
		break;
	default:
		printf("NO FUNCTION TO EVALUATE\n");
		break;
	}
}

Population initPopulation() {
	printf("Init Population\n");
	return;
}