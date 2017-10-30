#pragma once

typedef struct Mutant {
	int size;
	double* independentVariables;
	double* standardDeviations;
	double evaluatedValue;
} Mutant;