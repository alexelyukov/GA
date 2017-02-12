#ifndef SIMPLEPOPULATION_H
#define SIMPLEPOPULATION_H

#include "Population/population.h"
#include "Individual/simpleindividual.h"


class SimplePopulation : public Population {
public:
    SimplePopulation();
    virtual ~SimplePopulation();
    void generate() override;
    Population* evolve() override;
protected:
    void selection(Individual*& individual1, Individual*& individual2) override;
};

#endif // SIMPLEPOPULATION_H
