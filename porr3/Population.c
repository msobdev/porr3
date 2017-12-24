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

void freeMemory(Population* p1, Population* p2) {
	
	for (int k = 0; k < p1->size; k++) {
		free(p1->individual[k]);
		free(p1->deviations[k]);
	}

	free(p1->individual);
	free(p2->individual);
	free(p1->deviations);
	free(p2->deviations);
	free(p1->evaluations);
	free(p2->evaluations);
}

Population initBasePopulation(init init, OptimizingFunction optimizingFunction) {

	Population p = allocateMemory(init.mu, init.problemSize);

	int* searchSpace = getSearchSpace(optimizingFunction);

	for (int k = 0; k < init.mu; k++) {
		p.individual[k] = generateRandomNumbers(searchSpace, init.problemSize);
		p.evaluations[k] = 100.0;

		for (int i = 0; i < init.problemSize; i++) {
			p.deviations[k][i] = 5.0;
		}
	}
	return p;
}

void viewPopulation(Population p) {
	printf("Population:\n");
	for (int i = 0; i < p.size; i++) {
		printf("\nIndividual %d\t   Evaluation: %f\n", i + 1, p.evaluations[i]);
		for (int j = 0; j < p.problemSize; j++) {
			printf("X [%d]: %.2f\t", j, p.individual[i][j]);
			printf("Deviation [%d]: %.2f\n", j, p.deviations[i][j]);
		}
	}
}

void viewStatistics(int gen, Population p, int endStatistics) {
	if (gen % 100 != 0 && endStatistics == 1) {
		return;
	}

	float average = getAverage(p.evaluations, p.size);

	if(endStatistics == 1){
		printf("Gen: %d\taverage best solution: %f\n", gen, average);
	} else {
		printf("\nGen: %d\taverage best solution: %.3e\n", gen, average);
	}
}

void saveToCsv(FILE* fptr, Population p, int gen) {

	if (p.problemSize != 2) {
		return;
	}

	if (gen == 1) {
		fprintf(fptr, "%s,", "Gen");
		for (int i = 0; i < p.size; i++) {
			for (int k = 0; k < p.problemSize; k++) {
				fprintf(fptr, "x%d_%d,", i, k);
			}
			fprintf(fptr, "value,");
		}
		fprintf(fptr, "\n");
	}

	fprintf(fptr, "%d,", gen);
	for (int i = 0; i < p.size; i++) {
		for (int k = 0; k < p.problemSize; k++) {
			fprintf(fptr, "%f,", p.individual[i][k]);
		}
		fprintf(fptr, "%f,", p.evaluations[i]);
	}
	fprintf(fptr, "\n");
}