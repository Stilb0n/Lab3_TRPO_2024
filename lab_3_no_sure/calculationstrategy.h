#ifndef CALCULATIONSTRATEGY_H
#define CALCULATIONSTRATEGY_H

#include <QString>
#include <QPair>



class CalculationStrategy
{
public:
    enum STRATEGY
    {
        FOLDER,
        EXTENSION,
    };
    CalculationStrategy() {};
    virtual QMap<QString, quint64> exec(QString path) = 0;
};

#endif // CALCULATIONSTRATEGY_H
