#pragma once
#include "Population.h"
#include <math.h>

void mutatePopulation(Population* p, OptimizingFunction optFunction);

void mutateDeviation(Population* p, int popIndex, int xIndex, float xiGlobal);

void mutateX(Population* p, int popIndex, int xIndex, int* searchSpace);

void mutateIndividual(Population* p, int popIndex, float xiGlobal, int* searchSpace);

