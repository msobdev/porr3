#include "Utils.h"
#include <math.h>

int* getSearchSpace(OptimizingFunction optFunction) {
	static int searchSpace[2];

	if (optFunction == GRIEWANK) {
		searchSpace[0] = GXMIN;
		searchSpace[1] = GXMAX;
	} else if(optFunction == ACKLEY){
		searchSpace[0] = AXMIN;
		searchSpace[1] = AXMAX;
	} else {
		searchSpace[0] = -1;
		searchSpace[1] = 1;
	}
	return searchSpace;
}

float gauss01() {
	float mean = 0.0, stdev = 1.0;
	float u1, u2, r;

	do {
		u1 = 2.0 * rand() / RAND_MAX - 1;
		u2 = 2.0 * rand() / RAND_MAX - 1;
		r = u1 * u1 + u2 * u2;
	} while (r >= 1.0);

	r = sqrt((-2.0 * log(r)) / r);

	return (mean + u2 * r * stdev);
}

float uniform01() {
	return ((float)(rand() % 1) + (float)(rand() % 1000) / 1000.0);
}

float generateRandomNumber2(int min, int max) {
	float scaled = (float)(rand() % (max - min - 1)) + (float)(rand() % 1000) / 1000.0;
	return (scaled + min);
}

float generateRandomNumber1(int* minmax) {
	int searchSpace = minmax[1] - minmax[0];
	float scaled = (float)(rand() % (searchSpace - 1)) + (float)(rand() % 1000) / 1000.0;
	return (scaled + minmax[0]);
}

float* generateRandomNumbers(int* minmax, int arraySize) {
	float* array;
	
	array = malloc(arraySize*(sizeof(float*)));

	for (int i = 0; i < arraySize; i++) {
		array[i] = generateRandomNumber1(minmax);
	}
	return array;
}