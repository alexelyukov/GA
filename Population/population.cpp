#include "population.h"

int Population::numIndividuals = 100;

Population::Population() {
    //std::cout << "Population::Population()" << std::endl;
}

Population::~Population() {
    //std::cout << "Population::~Population()" << std::endl;
}

std::vector<double>* Population::getBestIndividual() const {
    double bestValue = 0;
    int id = 0;
    for (int i = 0; i < individuals.size(); i++) {
        if (individuals[i]->ffValue > bestValue) {
            bestValue = individuals[i]->ffValue;
            id = i;
        }
    }
    return individuals[id]->getArguments();
}

void Population::averageFF() {
    double sum = 0;
    for (const Individual* individual : individuals) {
        sum += individual->ffValue;
    }
    for (Individual* individual : individuals) {
        individual->ffValue /= sum;
    }
}
