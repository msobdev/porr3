#pragma once

#include "Selection.h"
#include "Mutation.h"
#include "Recombination.h"
#include "Population.h"

typedef struct ESInit{
	int mu;
	int lambda;
} init;

void evolutionaryStrategyMuLambda(init init, OptimizingFunction optFunction);