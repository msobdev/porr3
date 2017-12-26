#pragma once
#include "Utils.h"


void esOpenMP(init initES, OptimizingFunction fun);
void esMpi(int argc, char* argv[]);
void esSequential(init initES, OptimizingFunction fun);