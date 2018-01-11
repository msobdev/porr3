#pragma once
#include <stdio.h>
#include "Utils.h"

#include <omp.h>

typedef struct Population {
	int size;
	float** individual;
	float** deviations;
	float* evaluations;
	int problemSize;
} Population;

void evaluatePopulation(Population* population, OptimizingFunction optimizingFunction);

Population allocateMemory(int popSize, int problemSize);

void freeMemory(Population* p1, Population* p2);

Population initBasePopulationMPI(init init, OptimizingFunction optimizingFunction, int divisionSize, int singleDivision);

Population initBasePopulation(init init, OptimizingFunction optimizingFunction);

void viewPopulation(Population p);

void viewStatistics(int gen, Population p, bool endStatistics);

void viewStatisticsMPI(int gen, Population p, bool endStatistics, int rank);


void saveToCsv(FILE* fptr, Population p, int gen);