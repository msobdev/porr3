#pragma once
#include <stdlib.h>

#define PI 3.14159265359
#define EPS 10e-6

#define AXMIN -30
#define AXMAX 30
#define GXMIN -40
#define GXMAX 40

#define MU 30
#define LAMBDA (MU * 7)

typedef struct ESInit {
	int mu;
	int lambda;
	int problemSize;
} init;

typedef enum {
	GRIEWANK = 1,
	ACKLEY
} OptimizingFunction;

int* getSearchSpace(OptimizingFunction optFunction);

float gauss01();

float uniform01();

float generateRandomNumber2(int min, int max);

float generateRandomNumber1(int* minmax);

float* generateRandomNumbers(int* minmax, int arraySize);