#include "Selection.h"
#include <string.h>

void swapPop(Population* p, int indexA, int indexB) {

	float xEvaluation = p->evaluations[indexA];
	float* xIndividual = p->individual[indexA];
	float* xDevations = p->deviations[indexA];

	p->evaluations[indexA] = p->evaluations[indexB];
	p->individual[indexA] = p->individual[indexB];
	p->deviations[indexA] = p->deviations[indexB];

	p->evaluations[indexB] = xEvaluation;
	p->individual[indexB] = xIndividual;
	p->deviations[indexB] = xDevations;	
}

int partitionPop(Population* p, int low, int high) {

	float pivot = p->evaluations[high];

	int i = low - 1;

	for (int j = low; j <= high - 1; j++) {
		if (p->evaluations[j] <= pivot) {
			i++;
			swapPop(p, i, j);
		}
	}
	swapPop(p, i + 1, high);
	return (i + 1);
}

void quicksortPop(Population* p, int low, int high) {

	if (low < high) {
		int partitionIndex = partitionPop(p, low, high);
		
		quicksortPop(p, low, partitionIndex -  1);
		quicksortPop(p, partitionIndex + 1, high);
	}
}

void createBasePopulation(Population* basePop, Population* offspringPop) {

	quicksortPop(offspringPop, 0, offspringPop->size - 1);
	
	int i = 0;

	//#pragma omp for
	for (i = 0; i < basePop->size; i++) {
		basePop->individual[i] = offspringPop->individual[i];
		basePop->deviations[i] = offspringPop->deviations[i];
		basePop->evaluations[i] = offspringPop->evaluations[i];
	}
}

void createOffspringPopulation(Population* basePop, Population* offspringPop) {
	int randNumber;
	
	int i = 0;

	//#pragma omp for
	for (i = 0; i < offspringPop->size; i++) {
		randNumber = rand() % basePop->size;
		
		offspringPop->evaluations[i] = basePop->evaluations[randNumber];
		memcpy(offspringPop->individual[i], basePop->individual[randNumber], offspringPop->problemSize * sizeof(float));
		memcpy(offspringPop->deviations[i], basePop->deviations[randNumber], offspringPop->problemSize * sizeof(float));

	}
}