#include <QApplication>
#include <QDir>
#include <QDebug>
#include <iostream>
#include "consoloutput.h"
#include "foldercalculationstrategy.h"
#include "extensioncalculationstrategy.h"
#include <PercentCalculator.h>
#include <memory>


//void execute(QString path, unsigned int flag) {
//    if (QFileInfo(path).isDir()) {
//        std::shared_ptr<CalculationStrategy> strat = nullptr;
//        if (flag == 0) {
//            strat = std::make_shared<FolderCalculationStrategy>();
//        }
//        else if (flag == 1) {
//            strat = std::make_shared<ExtensionCalculationStrategy>();
//        }
//        else {
//            throw std::runtime_error("Not supported");
//        }
//        strat->exec(path);
//    }
//    else {
//        throw std::runtime_error("Entered path is not a folder");
//    }
//}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::cout << "Test 0. General Usage" << std::endl;

    QString path = "C:/Users/User/Desktop/keks/FileObserver/testFiles";

    std::shared_ptr<PercentCalculator> calculator = std::make_shared<PercentCalculator>();
    std::shared_ptr<CalculationStrategy> extStrat = std::make_shared<ExtensionCalculationStrategy>();
    calculator->setStrategy(extStrat);

    auto consoleInst = ConsoleOutput();
    auto res = calculator->calculate(path);
    consoleInst.show(res, "Extension");

    std::cout << std::endl;

    std::shared_ptr<CalculationStrategy> folderStrat = std::make_shared<FolderCalculationStrategy>();
    calculator->setStrategy(folderStrat);

    res = calculator->calculate(path);

    consoleInst.show(res, "Folder");


    std::cout << std::endl << "Test 1. Empty Folder" << std::endl;
    path = "C:/Users/lekks/TSU/semester 6/TRPO/5-12/lab3/testFiles/empty folder/";

    calculator = std::make_shared<PercentCalculator>();
    extStrat = std::make_shared<ExtensionCalculationStrategy>();
    calculator->setStrategy(extStrat);

    res = calculator->calculate(path);
    consoleInst.show(res, "Extension");


    std::cout << std::endl << "Test 2. The Only One" << std::endl;
    path = "C:/Users/lekks/TSU/semester 6/TRPO/5-12/lab3/testFiles/folder2/";

    calculator = std::make_shared<PercentCalculator>();
    extStrat = std::make_shared<ExtensionCalculationStrategy>();
    calculator->setStrategy(extStrat);

    res = calculator->calculate(path);
    consoleInst.show(res, "Extension");


    return a.exec();
}
