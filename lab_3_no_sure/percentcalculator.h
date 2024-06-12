#ifndef PERCENTCALCULATOR_H
#define PERCENTCALCULATOR_H
#include "calculationstrategy.h"
#include <memory>
#include <QPair>
#include <QList>
#include <QString>
#include <QMap>


class PercentCalculator
{
private:
    std::shared_ptr<CalculationStrategy> m_strategy = nullptr;
public:
    PercentCalculator(std::shared_ptr<CalculationStrategy> strategy = nullptr) {
        if (strategy != nullptr) {
            setStrategy(strategy);
        }
    }

    void setStrategy(std::shared_ptr<CalculationStrategy>& strategy) {
        m_strategy = strategy;
    };

    QMap<QString, quint64> calculate(QString path) {
        return m_strategy->exec(path);
    }
};

#endif // PERCENTCALCULATOR_H
