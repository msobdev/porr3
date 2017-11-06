#include "Recombination.h"

void recombinatePopulation(Population* p) {
	
	float a;
	float x1Prim;
	float x2Prim;

	int randNumber1;
	int randNumber2;
	float sigma1;

	for (int i = 0; i < p->size; i++) {
		a = uniform01();
		
		randNumber1 = rand() % p->problemSize;
		randNumber2 = rand() % p->problemSize;
		printf("%d\t%d\n", randNumber1, randNumber2);
		x1Prim = p->individual[i][randNumber1];
		x2Prim = p->individual[i][randNumber2];

		p->individual[i][randNumber1] = a * x1Prim + (1 - a) * x2Prim;
		p->individual[i][randNumber2] = a * x2Prim + (1 - a) * x1Prim;

		if (uniform01() < a) {
			sigma1 = p->deviations[i][randNumber1];
			p->deviations[i][randNumber1] = p->deviations[i][randNumber2];
			p->deviations[i][randNumber2] = sigma1;
		}
	}
}