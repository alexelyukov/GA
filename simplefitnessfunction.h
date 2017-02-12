#ifndef SIMPLEFITNESSFUNCTION_H
#define SIMPLEFITNESSFUNCTION_H

#include <vector>
#include <math.h>
#include "fitnessfunction.h"

class SimpleFitnessFunction : public FitnessFunction {
public:
    SimpleFitnessFunction();
    ~SimpleFitnessFunction();
    double function() override;
};

#endif // SIMPLEFITNESSFUNCTION_H
