#ifndef POPULATION_H
#define POPULATION_H

#include "Individual/individual.h"

class Population {
public:
    virtual ~Population();
    static int numIndividuals;
    std::vector<Individual*> individuals;
    std::vector<double>* getBestIndividual() const;
    virtual void generate() = 0;
    virtual Population* evolve() = 0;
protected:
    Population();
    void averageFF();
    virtual void selection(Individual*& individual1, Individual*& individual2) = 0;
};

#endif // POPULATION_H
