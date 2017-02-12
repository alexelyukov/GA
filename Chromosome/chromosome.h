#ifndef CHROMOSOME_H
#define CHROMOSOME_H

struct Intervals {
    double a0;
    double a1;
};

class Chromosome {
public:
    virtual ~Chromosome();
    static int numGenes;
    static int mutProb;
    Intervals interval;
    int valueGen;
    double valuePhen;
    void gen2phen();
    virtual void generate() = 0;
    virtual void mutation() = 0;
    virtual Chromosome* operator+(const Chromosome& obj) const = 0;
protected:
    Chromosome();
};

#endif // CHROMOSOME_H
