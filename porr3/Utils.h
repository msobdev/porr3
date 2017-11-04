#pragma once
#include <stdlib.h>

#define AXMIN -30
#define AXMAX 30
#define GXMIN -40
#define GXMAX 40

typedef struct ESInit {
	int mu; // Parent population size
	int lambda; // Offspring population size
	int problemSize;
} init;

typedef enum {
	GRIEWANK = 1,
	ACKLEY
} OptimizingFunction;

int* getSearchSpace(OptimizingFunction optFunction);

float generateRandomNumber2(int min, int max);

float generateRandomNumber1(int* minmax);

float* generateRandomNumbers(int* minmax, int arraySize);

