#include "individual.h"

FitnessFunction* Individual::fitnessFunction = nullptr;
int Individual::numChromosomes = 2;
std::vector<Intervals> Individual::intervals = std::vector<Intervals>({ {0,10}, {0,10} });

Individual::Individual() {
    //std::cout << "Individual::Individual()" << std::endl;
}

Individual::~Individual() {
    //std::cout << "Individual::~Individual()" << std::endl;
}

std::vector<double>* Individual::getArguments() const {
    std::vector<double>* arguments = new std::vector<double>();
    for (const Chromosome* chromosome : chromosomes) {
        arguments->push_back(chromosome->valuePhen);
    }
    return arguments;
}
