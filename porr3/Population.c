#include "Population.h"
#include "Ackley.h"
#include "Griewank.h"

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

Population initBasePopulationMPI(init init, OptimizingFunction optimizingFunction, int divisionSize, int singleDivision) {

	Population p = allocateMemory(init.mu, init.problemSize);

	int* searchSpace = getSearchSpaceMPI(optimizingFunction, divisionSize, singleDivision);

	for (int k = 0; k < init.mu; k++) {
		p.individual[k] = generateRandomNumbers(searchSpace, init.problemSize);
		p.evaluations[k] = 100.0;

		for (int i = 0; i < init.problemSize; i++) {
			p.deviations[k][i] = 5.0;
		}
	}
	return p;
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

void viewStatistics(int gen, Population p, bool endStatistics) {
	if (!endStatistics && gen % 100 != 0) {
		return;
	}
	//float average = getAverage(p.evaluations, p.size);

	if(!endStatistics){
		printf("Gen: %d\tBest solution: %f\n", gen, p.evaluations[0]);
	} else {
		printf("\nGen: %d\tBest solution: %.3e\n", gen, p.evaluations[0]);
	}
}

void viewStatisticsMPI(int gen, Population p, bool endStatistics, int rank) {
	if (!endStatistics && gen % 100 != 0) {
		return;
	}
	//float average = getAverage(p.evaluations, p.size);

	if (!endStatistics) {
		printf("ProcNum: %d\tGen: %d\tBest solution: %f\n", rank, gen, p.evaluations[0]);
	} else {
		printf("\nProcNum: %d\tGen: %d\tBest solution: %.3e\n", rank, gen, p.evaluations[0]);
	}
	fflush(stdout);
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