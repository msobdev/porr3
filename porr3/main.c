#include <stdio.h>
#include "ES.h"
#include <time.h>

#define MU 30
#define LAMBDA (MU * 7)
#define PROBLEMSIZE 20

int main(int args, char* argv[]) {

	srand((unsigned int)time(NULL));

	init initES = {MU, LAMBDA, PROBLEMSIZE};

	clock_t start = clock(), diff;
	evolutionaryStrategyMuLambda(initES, ACKLEY);
	diff = clock() - start;
	int msec = diff * 1000 / CLOCKS_PER_SEC;
	printf("Time taken %d seconds %d milliseconds\n", msec / 1000, msec % 1000);

	return 0;
};


