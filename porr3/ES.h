#pragma once

#include "Selection.h"
#include "Mutation.h"
#include "Recombination.h"
#include "Population.h"
#include "Utils.h"

#define LOOPLIMIT 50000
#define FILENAME "es.csv"

bool isStopCondition(Population* p, int gen, float* averageEvaluation);

bool isNotChanging(Population* p, int gen, float* averageEvaluation);

bool isBelowEPS(Population* p);

bool isBeyondLoopLimit(int gen);

void evolutionaryStrategyMuLambda(init init, OptimizingFunction optFunction);