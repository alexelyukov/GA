#ifndef SIMPLECHROMOSOME_H
#define SIMPLECHROMOSOME_H

#include <iostream>
#include "Chromosome/chromosome.h"

class SimpleChromosome : public Chromosome {
public:
    SimpleChromosome();
    ~SimpleChromosome();
    void generate() override;
    void mutation() override;
    Chromosome* operator+(const Chromosome& obj) const override;
};

#endif // SIMPLECHROMOSOME_H
