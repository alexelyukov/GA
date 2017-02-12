#include "simplepopulation.h"

SimplePopulation::SimplePopulation() {
    //std::cout << "SimplePopulation::SimplePopulation()" << std::endl;
}

SimplePopulation::~SimplePopulation() {
    for (Individual* elem : individuals) {
        delete elem;
    }
    //std::cout << "SimplePopulation::~SimplePopulation()" << std::endl;
}

void SimplePopulation::generate() {
    individuals.reserve(numIndividuals);
    Individual* individual;
    for (int i = 0; i < numIndividuals; i++) {
        individual = new SimpleIndividual();
        individual->generateChromosomes();
        individuals.push_back(individual);
    }
}

Population* SimplePopulation::evolve() {
    Population* rez = new SimplePopulation();
    averageFF();
    rez->individuals.reserve(numIndividuals);
    Individual* individual1 = nullptr;
    Individual* individual2 = nullptr;
    for (int i = 0; i < numIndividuals; i++) {
        selection(individual1, individual2);
        rez->individuals.push_back(*individual1 + *individual2);
    }
    return rez;
}

void SimplePopulation::selection(Individual*& individual1, Individual*& individual2) {
    double r, sum;
    int count, prev;
    for (int i = 0; i < 2; i++) {
        r = double(std::rand()%(1 << 15)) / (1 << 15);
        count = 0;
        sum = 0;
        for (Individual* elem : individuals) {
            sum += elem->ffValue;
            if (r < sum)
                break;
            count++;
        }
        if (i == 0) {
            individual1 = individuals.at(count);
            prev = count;
        } else {
            if (prev == count) {
                i--;
            } else {
                individual2 = individuals.at(count);
            }
        }
    }
}
