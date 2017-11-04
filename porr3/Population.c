#include "Population.h"
#include "Ackley.h"
#include "Griewank.h"

#define DYNALLOC(x, y) (malloc(x * (sizeof(y))))

void evaluatePopulation(Population* population, OptimizingFunction optimizingFunction, int problemSize) {

	switch(optimizingFunction) {
	case GRIEWANK:
		evaluateGriewankPopulation(population, problemSize);
		break;
	case ACKLEY:
		evaluateAckleyPopulation(population, problemSize);
		break;
	default:
		printf("NO FUNCTION TO EVALUATE\n");
		break;
	}
}

Population initPopulation(init init, OptimizingFunction optimizingFunction) {
	printf("Init Population\n");

	int* searchSpace = getSearchSpace(optimizingFunction);
	
	Population p = { init.mu,
					DYNALLOC(init.mu, float*),
					DYNALLOC(init.mu, float*),
					DYNALLOC(init.mu, float*),
					searchSpace
	};
	for (int k = 0; k < init.mu; k++) {
		p.individual[k] = DYNALLOC(init.problemSize, int);
		p.deviations[k] = DYNALLOC(init.problemSize, int);

		p.individual[k] = generateRandomNumbers(searchSpace, init.problemSize);
		p.evaluations[k] = 1.0;

		for (int i = 0; i < init.problemSize; i++) {
			p.deviations[k][i] = 1.0;
		}
	}
	return p;
}

void viewPopulation(Population p, int problemSize) {

	for (int i = 0; i < p.size; i++) {
		printf("\nIndividual %d\t   Evaluation: %.2f\n", i + 1, p.evaluations[i]);
		for (int j = 0; j < problemSize; j++) {
			printf("X [%d]: %.2f\t", j, p.individual[i][j]);
			printf("Deviation [%d]: %.2f\n", j, p.deviations[i][j]);
		}
	}
}
