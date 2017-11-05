#include "Population.h"
#include "Ackley.h"
#include "Griewank.h"

#define DYNALLOC(x, y) (malloc(x * (sizeof(y))))

void evaluatePopulation(Population* population, OptimizingFunction optimizingFunction) {

	switch(optimizingFunction) {
	case GRIEWANK:
		evaluateGriewankPopulation(population);
		break;
	case ACKLEY:
		evaluateAckleyPopulation(population);
		break;
	default:
		printf("NO FUNCTION TO EVALUATE\n");
		break;
	}
}

Population allocateMemory(int popSize, int problemSize) {
	Population p = { popSize,
		DYNALLOC(popSize, float*),
		DYNALLOC(popSize, float*),
		DYNALLOC(popSize, float*),
		problemSize
	};
	for (int k = 0; k < popSize; k++) {
		p.individual[k] = DYNALLOC(problemSize, float);
		p.deviations[k] = DYNALLOC(problemSize, float);
	}
	return p;
}

Population initBasePopulation(init init, OptimizingFunction optimizingFunction) {

	Population p = allocateMemory(init.mu, init.problemSize);

	int* searchSpace = getSearchSpace(optimizingFunction);

	for (int k = 0; k < init.mu; k++) {
		p.individual[k] = generateRandomNumbers(searchSpace, init.problemSize);
		p.evaluations[k] = 1.0;

		for (int i = 0; i < init.problemSize; i++) {
			p.deviations[k][i] = 1.0;
		}
	}
	return p;
}

void viewPopulation(Population p) {
	printf("Population:\n");
	for (int i = 0; i < p.size; i++) {
		printf("\nIndividual %d\t   Evaluation: %.2f\n", i + 1, p.evaluations[i]);
		for (int j = 0; j < p.problemSize; j++) {
			printf("X [%d]: %.2f\t", j, p.individual[i][j]);
			printf("Deviation [%d]: %.2f\n", j, p.deviations[i][j]);
		}
	}
}
