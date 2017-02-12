#ifndef FITNESSFUNCTION_H
#define FITNESSFUNCTION_H


class FitnessFunction {
public:
    virtual ~FitnessFunction();
    void setInternalData(void* _internalData);
    void setExternalData(void* _externalData);
    virtual double function() = 0;
protected:
    FitnessFunction();
    void* internalData;
    void* externalData;
};

#endif // FITNESSFUNCTION_H
