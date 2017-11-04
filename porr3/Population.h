#pragma once
#include <stdio.h>
#include "Utils.h"

typedef struct Population {
	int size;
	float** individual;
	float** deviations;
	float* evaluations;
	int searchSpace[2];
} Population;

void evaluatePopulation(Population* population, OptimizingFunction optimizingFunction, int problemSize);

Population initPopulation(init init, OptimizingFunction optimizingFunction);

void viewPopulation(Population p, int problemSize);