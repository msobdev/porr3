#pragma once
#include "Population.h"

#define PI 3.14159265359

float evaluateAckley(float* individual, int size);

void evaluateAckleyPopulation(Population* population, int problemSize);
