#include "Population/simplepopulation.h"
#include "simplefitnessfunction.h"

int main() {
    std::srand(time(NULL));
    const int N = 100;
    FitnessFunction* fitnessFunction = new SimpleFitnessFunction();
    std::vector<Population*> populationPool;
    Population* firstPopulation = new SimplePopulation();
    Population::numIndividuals = 100;
    Individual::intervals = std::vector<Intervals>({ {0,10}, {0,10} });
    Individual::fitnessFunction = fitnessFunction;
    Individual::numChromosomes = Individual::intervals.size();
    Chromosome::numGenes = 10;
    Chromosome::mutProb = 5;

    firstPopulation->generate();
    populationPool.push_back(firstPopulation);
    for (int i = 1; i < N; i++) {
        populationPool.push_back(populationPool.back()->evolve());
    }

    std::vector<double>* arguments = populationPool.back()->getBestIndividual();
    int i = 0;
    for (double elem : *arguments) {
        std::cout << "arg[" << i << "] = " << elem << std::endl;
        i++;
    }
    fitnessFunction->setInternalData(arguments);
    std::cout << "fitnessFunction = " << fitnessFunction->function() << std::endl;

    for (Population* elem : populationPool) {
        delete elem;
    }
    delete fitnessFunction;
    return 0;
}
