#pragma once
#include <stdio.h>
#include "Mutant.h"

typedef struct Population {
	int size;
	Mutant* mutants;
} Population;

void evaluatePopulation(Population* population, int functionToEvaluate);