#pragma once
#include "Utils.h"

void esMpi(init initES, OptimizingFunction fun);
void esSequentialOrOpenMP(init initES, OptimizingFunction fun);