#pragma once

#include "Selection.h"
#include "Mutation.h"
#include "Recombination.h"
#include "Population.h"
#include "Utils.h"

bool isStopCondition(Population* p, int gen, float averageEvaluation);

bool isNotChanging(Population* p, int gen, float averageEvaluation);

bool isBelowEPS(Population* p);

void evolutionaryStrategyMuLambda(init init, OptimizingFunction optFunction);