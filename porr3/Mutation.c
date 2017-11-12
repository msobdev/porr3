#include "Mutation.h"

void mutateDeviation(Population* p, int popIndex, int xIndex, float xiGlobal) {
	float xi = gauss01();
	float k = 0.08;
	float tau = k / sqrt(2.0 * p->problemSize);
	float tauPrim = k / sqrt(2.0 * sqrt(p->problemSize));
	
	p->deviations[popIndex][xIndex] = p->deviations[popIndex][xIndex] * exp(tauPrim * xiGlobal + tau * xi);

	if (p->deviations[popIndex][xIndex] < 10e-10) {
		p->deviations[popIndex][xIndex] = 10e-10;
	}
}

void mutateX(Population* p, int popIndex, int xIndex, int* searchSpace) {
	float xi = gauss01();
	float xValue = p->individual[popIndex][xIndex];

	p->individual[popIndex][xIndex] = xValue + p->deviations[popIndex][xIndex] * xi;

	if (xValue < searchSpace[0]) {
		p->individual[popIndex][xIndex] = searchSpace[0];
	}
	if (xValue > searchSpace[1]) {
		p->individual[popIndex][xIndex] = searchSpace[1];
	}
}

void mutateIndividual(Population* p, int popIndex, float xiGlobal, int* searchSpace) {
	int k;

	#pragma omp parallel for
	for (k = 0; k < p->problemSize; k++) {
		mutateDeviation(p, popIndex, k, xiGlobal);
		mutateX(p, popIndex, k, searchSpace);
	}
}

void mutatePopulation(Population* p, OptimizingFunction optFunction) {
	float xiGlobal;
	int* searchSpace = getSearchSpace(optFunction);
	int i;

	#pragma omp parallel for
	for (i = 0; i < p->size; i++) {
		xiGlobal = gauss01();
		mutateIndividual(p, i, xiGlobal, searchSpace);
	}
}