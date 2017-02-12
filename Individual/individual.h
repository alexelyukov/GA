#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <vector>
#include "Chromosome/chromosome.h"
#include "fitnessfunction.h"

class Individual {
public:
    virtual ~Individual();
    static FitnessFunction* fitnessFunction;
    static int numChromosomes;
    static std::vector<Intervals> intervals;
    double ffValue;
    std::vector<Chromosome*> chromosomes;
    std::vector<double>* getArguments() const;
    virtual void generateChromosomes() = 0;
    virtual Individual* operator+(const Individual& obj) const = 0;
protected:
    Individual();
};

#endif // INDIVIDUAL_H
