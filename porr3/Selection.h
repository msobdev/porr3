#pragma once
#include "Population.h"

void swapPop(Population* p, int indexA, int indexB);

int partitionPop(Population* p, int low, int high);

void quicksortPop(Population* p, int low, int high);

void createBasePopulation(Population* basePop, Population* offspringPop);

void createOffspringPopulation(Population* basePop, Population* offspringPop);