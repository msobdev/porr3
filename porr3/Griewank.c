#include "Griewank.h"
#include <math.h>

float evaluateGriewank(float* individual, int size) {

	float sum = 0;
	float prod = 1;

	for (int i = 1; i <= size; i++) {
		sum = sum + pow(individual[i - 1], 2) / 40;
		prod = prod * cos((individual[i - 1])/i);
	}
	return (sum - prod + 1);
}

void evaluateGriewankPopulation(Population* population) {
	int size = (*population).size;

	for (int i = 0; i < size; i++) {
		(*population).evaluations[i] = evaluateGriewank((*population).individual[i], (*population).problemSize);
	}
}