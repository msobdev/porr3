#pragma once
#include "Utils.h"

void esMpi(int argc, char* argv[]);
void esSequentialOrOpenMP(init initES, OptimizingFunction fun);