#ifndef SIMPLEINDIVIDUAL_H
#define SIMPLEINDIVIDUAL_H

#include "Individual/individual.h"
#include "Chromosome/simplechromosome.h"

class SimpleIndividual : public Individual {
public:
    SimpleIndividual();
    ~SimpleIndividual();
    void generateChromosomes() override;
    Individual* operator+(const Individual& obj) const override;
};

#endif // SIMPLEINDIVIDUAL_H
