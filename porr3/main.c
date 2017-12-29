#include "ES.h"
#include <time.h>
#include "ExecutionType.h"

// DEFINE PROBLEM SIZE: 1 - 100
#define PROBLEMSIZE 100
// DEFINE OPTIMIZATION FUNCTION: GRIEWANK or ACKLEY
#define FUNCTION GRIEWANK
// DEFINE EXECUTION TYPE: PARALLEL_OPENMP(1) or PARALLEL_MPI(2) or SEQUENTIAL(3)
#define EXECUTION 2

int main(int argc, char* argv[]) {

	srand((unsigned int)time(NULL));
	init initES = { MU, LAMBDA, PROBLEMSIZE };

	switch (EXECUTION) {
	case(1):
		printf("EVOLUTIONARY STRATEGY OPENMP:\n\n");
		esSequentialOrOpenMP(initES, FUNCTION);
		break;
	case(2):
		printf("EVOLUTIONARY STRATEGY MPI:\n\n");
		esMpi(argc, argv);
		break;
	case(3):
		printf("EVOLUTIONARY STRATEGY SEQUENTIAL:\n\n");
		esSequentialOrOpenMP(initES, FUNCTION);
		break;
	default:
		break;
	}
	
	return 0;
};


