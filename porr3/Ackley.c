#include "Ackley.h"
#include <math.h>

float evaluateAckley(float* individual, int size) {

	float sum1 = 0;
	float sum2 = 0;

	for (int i = 0; i < size; i++) {
		sum1 = sum1 + pow(individual[i], 2);
		sum2 = sum2 + cos(2 * PI * individual[i]);
	}

	float term1 = -20 * exp(-0.2 * sqrt(sum1/size));
	float term2 = -exp(sum2/size);

	return (term1 + term2 + 20 + exp(1));
}

void evaluateAckleyPopulation(Population* population, int problemSize) {
	int size = (*population).size;

	for (int i = 0; i < size; i++) {
		(*population).evaluations[i] = evaluateAckley((*population).individual[i], problemSize);
	}
}