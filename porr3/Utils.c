#include "Utils.h"
#include <math.h>

int* getSearchSpaceMinMax(int min, int max) {
	static int searchSpace[2];

	searchSpace[0] = min;
	searchSpace[1] = max;

	return searchSpace;
}

int* getSearchSpaceMPI(OptimizingFunction optFunction, int divisionSize, int singleDivision) {
	int* searchSpace = getSearchSpace(optFunction);
	int fullSpace = searchSpace[1] - searchSpace[0];
	int divisionSpace = (fullSpace / divisionSize);
	searchSpace[0] = searchSpace[0] + divisionSpace * singleDivision;
	searchSpace[1] = searchSpace[0] + divisionSpace;
	//printf("Processors size: %d, processor number: %d, min: %d, max: %d\n", divisionSize, singleDivision, searchSpace[0], searchSpace[1]);
	return searchSpace;
}

int* getSearchSpace(OptimizingFunction optFunction) {
	if (optFunction == GRIEWANK) {
		return getSearchSpaceMinMax(GXMIN, GXMAX);
	} else if (optFunction == ACKLEY) {
		return getSearchSpaceMinMax(AXMIN, AXMAX);
	} else {
		return NULL;
	}
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

float getAverage(float* numbers, int size) {
	float average = 0;
	for (int i = 0; i < size; i++) {
		average += numbers[i];
	}
	average /= size;
	return average;
}

void convertTimeFromMiliseconds(int msec) {
	int miliseconds = (int)(msec % 1000);
	int minutes = (int)((msec / (1000 * 60)) % 60);
	int seconds = (int)(msec / 1000) % 60;
	printf("Time taken %d minutes %d seconds %d miliseconds.\n\n", minutes, seconds, miliseconds);
	fflush(stdout);
}

bool isFloatsEquals(float* a, float* b) {
	return (fabs(*a - *b) < EPS/10);
}