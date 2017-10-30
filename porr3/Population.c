#include "Population.h"
#include "Griewank.h"
#include "Ackley.h"

#define GRIEWANK 1
#define ACKLEY 2

void evaluatePopulation(Population* population, int functionToEvaluate) {

	switch(functionToEvaluate) {
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