#include <stdio.h>
#include "Population.h"

int main(int args, char* argv[]) {
	
	printf("Evolutionary Strategy\n\n");

	Mutant mutant = {
		3,
		(double[3]){1.0, 2.0, -4.0},
		(double[3]){0.1, 0.2, 0.3},
		1.0
	};

	Mutant mutant2 = {
		3,
		(double[3]) {-1.0, -2.0, -3.0},
		(double[3]) {0.1, 0.2, 0.3},
		1.0
	};

	Population population = {
			2,
			(Mutant[2]){mutant, mutant2}
	};

	Population* p = &population;

	evaluatePopulation(p, 1);

	printf("This is evaluation: %f\n", population.mutants[0].evaluatedValue);

	return 0;
};
