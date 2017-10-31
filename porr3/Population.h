#pragma once
#include <stdio.h>
#include "Mutant.h"

typedef enum{
	GRIEWANK = 1,
	ACKLEY
} OptimizingFunction;

typedef struct Population {
	int size;
	Mutant* mutants;
} Population;

void evaluatePopulation(Population* population, OptimizingFunction optimizingFunction);

Population initPopulation();