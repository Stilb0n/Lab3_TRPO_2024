#ifndef CONSOLEOUTPUT_H
#define CONSOLEOUTPUT_H
#include <QDebug>
#include <QString>
#include <cmath>



class ConsoleOutput
{
private:
    QString getPercent(quint64 item_size, quint64 total_size) {
        // Calculating size of the whole folder
        double percent = static_cast<double>(item_size) / static_cast<double>(total_size);
        QString res = "";
        if (percent < 0.01) {
            res = "<0.01";
        }
        else {
            percent = percent * 100;
            res = QString::number(percent, 'f', 2);
        }
        return res;
    }

    // calculates number of digits in the argument
    int numOfDigits(quint64 num) {
        if (num == 0) {
            return 1;
        }
        return std::floor(std::log10(num) + 1);
    }

    int calculateMaxStringLengthInPair(QList<QPair<quint64, QString>> size_item, unsigned int index_in_pair, unsigned int header_length) {
        int maximum_length = header_length;
        if (index_in_pair > 2) {
            throw std::runtime_error("Not Supported");
        }
        else if (index_in_pair == 0) {
            for (int i = 0; i < size_item.size(); i++) {
                if (maximum_length < numOfDigits(size_item[i].first)) {
                    maximum_length = numOfDigits(size_item[i].first);
                }
            }
        }
        else if (index_in_pair == 1) {
            for (int i = 0; i < size_item.size(); i++) {
                if (maximum_length < size_item[i].second.length()) {
                    maximum_length = size_item[i].second.length();
                }
            }
        }
        return maximum_length;
    }

public:
    ConsoleOutput() { };
    void show(QMap<QString, quint64> size_item, QString second_item_name) {
        if (size_item.isEmpty()) {
            qDebug() << "Folder in input is empty";
        }
        else {
            // turn into different struct
            QList<QPair<quint64, QString>> listOfItemSize;
            for(auto it = size_item.begin(); it != size_item.end(); ++it){
                listOfItemSize.append(qMakePair(it.value(), it.key()));
            }



            QString bytes = "Bytes";
            QString percent = "Percent";
            int maxStringLengthInColumn1 = calculateMaxStringLengthInPair(listOfItemSize, 0, bytes.length());
            int maxStringLengthInColumn2 = calculateMaxStringLengthInPair(listOfItemSize, 1, second_item_name.length());

            qDebug() << qPrintable(QString("%1 %2 %3")
                                       .arg(bytes, maxStringLengthInColumn1)
                                       .arg(second_item_name, maxStringLengthInColumn2)
                                       .arg(percent, percent.length()+1));  // +1 comes for percent display in strings
            qDebug() << " ";    // go to the next line

            // Calculating size of the whole folder
            quint64 totalSize = 0;
            for (int i = 0; i < listOfItemSize.size(); i++) {
                totalSize += listOfItemSize[i].first;
            };

            // Showing details to console
            for (int i = 0; i < listOfItemSize.size(); i++) {
                qDebug() << qPrintable(QString("%1 %2 %3%")
                                           .arg(listOfItemSize[i].first, maxStringLengthInColumn1)
                                           .arg(listOfItemSize[i].second, maxStringLengthInColumn2)
                                           .arg(getPercent(listOfItemSize[i].first, totalSize), percent.length()));
                // percent.length() - has the biggest length if 2 dighits after dot are required
            }
        }
    }
};

#endif // CONSOLEOUTPUT_H
