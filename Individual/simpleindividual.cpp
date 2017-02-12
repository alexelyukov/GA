#include "simpleindividual.h"

SimpleIndividual::SimpleIndividual() {
    //std::cout << "SimpleIndividual::SimpleIndividual()" << std::endl;
}

SimpleIndividual::~SimpleIndividual() {
    for (Chromosome* elem : chromosomes) {
        delete elem;
    }
    //std::cout << "SimpleIndividual::~SimpleIndividual()" << std::endl;
}

void SimpleIndividual::generateChromosomes() {
    chromosomes.reserve(numChromosomes);
    Chromosome* chromosome;
    for (int i = 0; i < numChromosomes; i++) {
        chromosome = new SimpleChromosome();
        chromosome->interval = intervals.at(i);
        chromosome->generate();
        chromosomes.push_back(chromosome);
    }
    fitnessFunction->setInternalData(getArguments());
    ffValue = fitnessFunction->function();
}

Individual* SimpleIndividual::operator+(const Individual& obj) const {
    Individual* rez = new SimpleIndividual();
    rez->chromosomes.reserve(numChromosomes);
    Chromosome* chromosome;
    for (int i = 0; i < numChromosomes; i++) {
        chromosome = *chromosomes.at(i) + *obj.chromosomes.at(i);
        chromosome->mutation();
        rez->chromosomes.push_back(chromosome);
    }
    rez->fitnessFunction->setInternalData(getArguments());
    rez->ffValue = fitnessFunction->function();
    return rez;
}
