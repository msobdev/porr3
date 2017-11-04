#include "Selection.h"

void createBasePopulation(Population* population) {
	printf("createBasePopulation\n");
}

void createOffspringPopulation(Population* basePop, Population* offspringPop) {

	int randNumber;
	for (int i = 0; i < offspringPop->size; i++) {
		randNumber = rand() % basePop->size;
		offspringPop->individual[i] = basePop->individual[randNumber];
		offspringPop->deviations[i] = basePop->deviations[randNumber];
		offspringPop->evaluations[i] = basePop->evaluations[randNumber];
	}

}