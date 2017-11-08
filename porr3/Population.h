#pragma once
#include <stdio.h>
#include "Utils.h"

typedef struct Population {
	int size;
	float** individual;
	float** deviations;
	float* evaluations;
	int problemSize;
} Population;

void evaluatePopulation(Population* population, OptimizingFunction optimizingFunction);

Population allocateMemory(int popSize, int problemSize);

Population initBasePopulation(init init, OptimizingFunction optimizingFunction);

void viewPopulation(Population p);

void viewStatistics(int gen, Population p, int endStatistics);