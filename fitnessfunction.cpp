#include "fitnessfunction.h"

FitnessFunction::FitnessFunction() {
}

FitnessFunction::~FitnessFunction() {
}

void FitnessFunction::setInternalData(void* _internalData) {
    internalData = _internalData;
}

void FitnessFunction::setExternalData(void* _externalData) {
    externalData = _externalData;
}
