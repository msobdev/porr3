#pragma once
#include "Population.h"

float evaluateGriewank(float* individual, int size);

void evaluateGriewankPopulation(Population* population, int problemSize);