#ifndef FOLDERCALCULATIONSTRATEGY_H
#define FOLDERCALCULATIONSTRATEGY_H
#include "calculationstrategy.h"
#include "customlib.h"
#include <QDebug>




class FolderCalculationStrategy : public CalculationStrategy {
public:
    FolderCalculationStrategy() {};
    QMap<QString, quint64> exec(QString path)  {
        QDir dir = QDir(path);
        QMap<QString, quint64> folder_size;

        folder_size.insert("(Current Directory)", getSizeOfFilesIn(path));
        foreach (QFileInfo folder, dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Size)) {
            folder_size.insert(folder.fileName(), getSizeOf(folder.absoluteFilePath()));
        }

        return folder_size;

        //        QList<QPair<quint64, QString>> listOfExstensonSize;
        //        for(auto it = folder_size.begin(); it != folder_size.end(); ++it) {
        //            listOfExstensonSize.append(qMakePair(it.value(), it.key()));
        //        }
        //        std::sort(listOfExstensonSize.begin(), listOfExstensonSize.end());

        //        show(listOfExstensonSize, "Folder");
    };
};


#endif // FOLDERCALCULATIONSTRATEGY_H
