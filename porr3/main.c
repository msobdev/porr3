#include "ES.h"
#include <time.h>

// MPI
// DEFINE PROBLEM SIZE: 1 - 100
#define PROBLEMSIZE 100
// DEFINE OPTIMIZATION FUNCTION: GRIEWANK or ACKLEY
#define FUNCTION GRIEWANK

int main(int args, char* argv[]) {

	srand((unsigned int)time(NULL));

	init initES = {MU, LAMBDA, PROBLEMSIZE};

	printf("EVOLUTIONARY STRATEGY:\n\n");
	clock_t start = clock(), diff;
	evolutionaryStrategyMuLambda(initES, FUNCTION);
	diff = clock() - start;
	convertTimeFromMiliseconds((int)(diff * 1000 / CLOCKS_PER_SEC));
	
	return 0;
};


