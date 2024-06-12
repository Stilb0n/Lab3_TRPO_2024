#include <QApplication>
#include <QDebug>
#include <iostream>
#include<QFileInfo>
#include<QDir>
#include "foldercalculationstrategy.h"
int main(int argc, char *argv[])
{

    void execute(QString path, unsigned int flag) {
        std::unique_ptr<CalculationStrategy> strat = nullptr;
        if (flag == 0) {
            strat = std::make_unique<FolderCalculationStrategy>();
        }
        else if (flag == 1) {
            strat = std::make_unique<ExtensionCalculationStrategy>();
        }
        else {
            throw std::runtime_error( "Not supported" );
        }
        strat->calculate(path);
    }
    QApplication a(argc, argv);

    QDir myDir;
    myDir.setPath("C:/Users/lekks/TSU/semester 6/TRPO/5-12/lab3/testFiles");
    QFileInfo fileInfo = QFileInfo(myDir.path());
    /* Рассмотрим способы обхода содержимого папок на диске.
Предлагается вариант решения, который может быть применен для более сложных задач.
Итак, если требуется выполнить анализ содержимого папки, то необходимо организовать обход
содержимого.
Например:*/
    // Calculates size of the folder in argument
    qint64 getSizeOf(QString path) {
        QFileInfo fileInfo = QFileInfo(path);
        if (fileInfo.isDir()) {
            /*
Если fileInfo папка, то заходим в нее, чтобы просмотреть находящиеся в ней файлы.
Если нужно просмотреть все файлы, включая все вложенные папки, то нужно организовать
рекурсивный обход.
*/
            QDir dir = fileInfo.dir();
            if (dir.cd(fileInfo.fileName())) {
                /*
Если зашли в папку, то пройдемся по контейнеру QFileInfoList, полученного методом
entryInfoList,
*/
                foreach (QFileInfo inf, dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Type)) {
                    qDebug() << inf.fileName() << "---" << inf.size();
                    qint64 currentDirectorySize = 0;
                    foreach (QFileInfo file, dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Size)) {
                        currentDirectorySize += file.size();
                    }
                    foreach (QFileInfo folder, dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Size)) {
                        currentDirectorySize += getSizeOf(folder.absoluteFilePath());
                    }
                    dir.cdUp();//выходим из папки
                    return currentDirectorySize;
                }
            }
            else {
                return fileInfo.size();
            }
        }

    }
        int main(int argc, char *argv[])
        {
            QApplication a(argc, argv);

            QString path = "C:/Users/lekks/TSU/semester 6/TRPO/5-12/lab3/testFiles";
            qDebug() << "SIZE: " << getSizeOf(path);
            //    QDir myDir;
            //    myDir.setPath("C:/Users/lekks/TSU/semester 6/TRPO/5-12/lab3/testFiles");
            //    QFileInfo fileInfo = QFileInfo(myDir.path());
            //    /* Рассмотрим способы обхода содержимого папок на диске.
            //Предлагается вариант решения, который может быть применен для более сложных задач.
            //Итак, если требуется выполнить анализ содержимого папки, то необходимо организовать обход
            //содержимого.
            //Например:*/
            //    if (fileInfo.isDir()) {
            //        /*
            //Если fileInfo папка, то заходим в нее, чтобы просмотреть находящиеся в ней файлы.
            //Если нужно просмотреть все файлы, включая все вложенные папки, то нужно организовать
            //рекурсивный обход.
            //*/
            //        QDir dir = fileInfo.dir();
            //        if (dir.cd(fileInfo.fileName())) {
            //            /*
            //Если зашли в папку, то пройдемся по контейнеру QFileInfoList, полученного методом
            //entryInfoList,
            //*/
            //            foreach (QFileInfo inf, dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Type)) {
            //                qDebug() << inf.fileName() << "---" << inf.size();
            //            }
            //            dir.cdUp();//выходим из папки
            //        }
            //    }

            //-------------------------------------
            QDir dir = QDir("C:/Users/lekks/TSU/semester 6/TRPO/5-12/lab3/testFiles"); //объявляем объект работы с папками
            dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
            ///устанавливаем фильтр выводимых файлов
            dir.setSorting(QDir::Size | QDir::Reversed); //устанавливаем сортировку "от меньшего к большему"
            QFileInfoList list = dir.entryInfoList(); //получаем список файлов директории
            qDebug() << " Bytes Filename"; //выводим заголовок
            /* в цикле выводим сведения о файлах */
            for (int i = 0; i < list.size(); ++i) {
                QFileInfo fileInfo = list.at(i);
                qDebug() << qPrintable(QString("%1 %2").arg(fileInfo.size(), 10).arg(fileInfo.fileName())); //выводим в формате "размер имя", переносим строку
            }
            //    QDir dir = QDir("C:/Users/lekks/TSU/semester 6/TRPO/5-12/lab3/testFiles"); //объявляем объект работы с папками
            //    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
            //    ///устанавливаем фильтр выводимых файлов
            //    dir.setSorting(QDir::Size | QDir::Reversed); //устанавливаем сортировку "от меньшего к большему"
            //        QFileInfoList list = dir.entryInfoList(); //получаем список файлов директории
            //            qDebug() << " Bytes Filename"; //выводим заголовок
            //    /* в цикле выводим сведения о файлах */
            //    for (int i = 0; i < list.size(); ++i) {
            //        QFileInfo fileInfo = list.at(i);
            //        qDebug() << qPrintable(QString("%1 %2").arg(fileInfo.size(), 10).arg(fileInfo.fileName())); //выводим в формате "размер имя", переносим строку
            //    }

            return a.exec();
        }
    }
