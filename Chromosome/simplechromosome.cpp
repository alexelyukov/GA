#include "simplechromosome.h"

SimpleChromosome::SimpleChromosome() {
    //std::cout << "SimpleChromosome::SimpleChromosome()" << std::endl;
}

SimpleChromosome::~SimpleChromosome() {
    //std::cout << "SimpleChromosome::~SimpleChromosome()" << std::endl;
}

void SimpleChromosome::generate() {
    valueGen = std::rand()%(1 << numGenes);
    gen2phen();
}

void SimpleChromosome::mutation() {
    if (std::rand()%100 < mutProb) {
        int r = std::rand()%numGenes + 1;
        if (valueGen & (1 << (r - 1))) {
            valueGen -= 1 << (r - 1);
        } else {
            valueGen += 1 << (r - 1);
        }
        gen2phen();
    }
}

Chromosome* SimpleChromosome::operator+(const Chromosome& obj) const {
    Chromosome* rez = new SimpleChromosome();
    rez->interval = interval;
    int r = std::rand()%(numGenes - 1) + 1;
    int a = valueGen;
    int b = obj.valueGen;
    a &= ((1 << r) - 1) << (numGenes - r);
    b &= (1 << (numGenes - r)) - 1;
    rez->valueGen = a + b;
    rez->gen2phen();
    return rez;
}
