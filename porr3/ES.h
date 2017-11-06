#pragma once

#include "Selection.h"
#include "Mutation.h"
#include "Recombination.h"
#include "Population.h"
#include "Utils.h"
#include <stdbool.h> 

bool isStopCondition(Population* p);

void evolutionaryStrategyMuLambda(init init, OptimizingFunction optFunction);