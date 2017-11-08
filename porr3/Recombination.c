#include "Recombination.h"

void recombinatePopulation(Population* p) {

	float a;
	float* x1Prim;
	float* x2Prim;

	int randNumber1;
	int randNumber2;
	float* sigma1;

	a = uniform01();
	
		randNumber1 = rand() % p->size;
		randNumber2 = rand() % p->size;

		x1Prim = p->individual[randNumber1];
		x2Prim = p->individual[randNumber2];

		for (int i = 0; i < p->problemSize; i++) {
			p->individual[randNumber1][i] = a * x1Prim[i] + ((1 - a) * x2Prim[i]);
			p->individual[randNumber2][i] = a * x2Prim[i] + ((1 - a) * x1Prim[i]);
		}

		if (uniform01() < a) {
			sigma1 = p->deviations[randNumber1];
			memcpy(p->deviations[randNumber1], p->deviations[randNumber2], p->problemSize * sizeof(float));
			memcpy(p->deviations[randNumber2], sigma1, p->problemSize * sizeof(float));
		}
	
}