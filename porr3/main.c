#include <stdio.h>
#include "ES.h"
#include <time.h>

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
	int msec = diff * 1000 / CLOCKS_PER_SEC;
	int minutes = (int)((msec / (1000 * 60)) % 60);
	int seconds = (int)(msec / 1000) % 60;
	printf("Time taken %d minutes %d seconds.\n\n", minutes, seconds);

	return 0;
};


