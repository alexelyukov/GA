#include "chromosome.h"

int Chromosome::numGenes = 10;
int Chromosome::mutProb = 5;

Chromosome::Chromosome() {
    //std::cout << "Chromosome::Chromosome()" << std::endl;
}

Chromosome::~Chromosome() {
    //std::cout << "Chromosome::~Chromosome()" << std::endl;
}

void Chromosome::gen2phen() {
    valuePhen = ((double) valueGen) / (1 << numGenes) * (interval.a1 - interval.a0) + interval.a0;
}
