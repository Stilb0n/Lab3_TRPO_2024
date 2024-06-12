#ifndef CALCULATIONSTRATEGY_H
#define CALCULATIONSTRATEGY_H

class CalculationStrategy
{
public:
    CalculationStrategy() {};
    virtual void calculate(QString path) = 0;

    enum STRATEGY
    {
        FOLDER,
        EXTENSION,
    };
};



#endif // CALCULATIONSTRATEGY_H
