#include "Ackley.h"
#include <math.h>

void evaluateAckley(Mutant* mutant) {
	int size = (*mutant).size;

	double sum1 = 0;
	double sum2 = 0;
	double xi;

	for (int i = 0; i < size; i++) {
		xi = (*mutant).independentVariables[i];
		sum1 = sum1 + pow(xi, 2);
		sum2 = sum2 + cos(2 * PI * xi);
	}

	double term1 = -20 * exp(-0.2 * sqrt(sum1/size));
	double term2 = -exp(sum2/size);

	(*mutant).evaluatedValue = term1 + term2 + 20 + exp(1);
}

void evaluateAckleyPopulation(Population* population) {
	int size = (*population).size;

	for (int i = 0; i < size; i++) {
		evaluateAckley(&(*population).mutants[i]);
	}
}