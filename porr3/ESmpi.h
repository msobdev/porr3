#pragma once

#include "ES.h"

void evolutionaryStrategyMuLambdaMPI(init init, OptimizingFunction optFunction);

void prepareES(init init, OptimizingFunction optFunction);

void cleanupES();

void runES(OptimizingFunction optFunction);