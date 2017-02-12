#include "simplefitnessfunction.h"

SimpleFitnessFunction::SimpleFitnessFunction() {

}

SimpleFitnessFunction::~SimpleFitnessFunction() {

}

double SimpleFitnessFunction::function() {
    std::vector<double> args =  *(std::vector<double>*) internalData;
    if (args.size() == 2) {
        return 1 / ( 1 + pow(args[0] - 6, 2) + pow(args[1] - 3, 2) );
    } else {
        return -1;
    }
}
