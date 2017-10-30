#include "Griewank.h"
#include <math.h>

void evaluateGriewank(Mutant* mutant) {
	int size = (*mutant).size;

	double sum = 0;
	double prod = 1;
	double xi;

	for (int i = 1; i <= size; i++) {
		xi = (*mutant).independentVariables[i-1];
		sum = sum + pow(xi, 2) / 40;
		prod = prod * cos((xi)/i);
	}
	(*mutant).evaluatedValue = sum - prod + 1;
}

void evaluateGriewankPopulation(Population* population) {
	int size = (*population).size;

	for (int i = 0; i < size; i++) {
		evaluateGriewank(&(*population).mutants[i]);
	}
}