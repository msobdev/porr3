#pragma once
#include <stdlib.h>
#include <stdbool.h> 
#include <stdio.h>

#define PI 3.14159265359
#define EPS 10e-6

#define AXMIN -30
#define AXMAX 30
#define GXMIN -40
#define GXMAX 40

#define MU 30
#define LAMBDA (MU * 7)

#define DYNALLOC(x, y) (malloc(x * (sizeof(y))))

typedef struct ESInit {
	int mu;
	int lambda;
	int problemSize;
} init;

typedef enum {
	GRIEWANK = 1,
	ACKLEY
} OptimizingFunction;

int* getSearchSpaceMPI(OptimizingFunction optFunction, int divisionSize, int singleDivision);

int* getSearchSpaceMinMax(int min, int max);

int* getSearchSpace(OptimizingFunction optFunction);

float gauss01();

float uniform01();

float generateRandomNumber2(int min, int max);

float generateRandomNumber1(int* minmax);

float* generateRandomNumbers(int* minmax, int arraySize);

float getAverage(float* numbers, int size);

void convertTimeFromMiliseconds(int msec);

bool isFloatsEquals(float* a, float* b);