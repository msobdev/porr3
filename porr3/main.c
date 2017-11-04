#include <stdio.h>
#include "ES.h"
#include <time.h>

#define MU 2
#define LAMBDA (MU * 7)
#define PROBLEMSIZE 3

int main(int args, char* argv[]) {

	srand((unsigned int)time(NULL));

	init initES = {MU, LAMBDA, PROBLEMSIZE};
	evolutionaryStrategyMuLambda(initES, GRIEWANK);

	return 0;
};


