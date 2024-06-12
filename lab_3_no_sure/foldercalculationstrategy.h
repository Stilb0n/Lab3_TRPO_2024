#ifndef FOLDERCALCULATIONSTRATEGY_H
#define FOLDERCALCULATIONSTRATEGY_H

class FolderCalculationStrategy : public CalculationStrategy {
            public:
                 FolderCalculationStrategy() {};
    void calculate(QString path) override {
        QDir dir = QDir("C:/Users/lekks/TSU/semester 6/TRPO/5-12/lab3/testFiles"); //объявляем объект работы с папками

        QMap<QString, quint64> folder_size;

        folder_size.insert("(Current Directory)", getSizeOfFilesIn(path));
        foreach (QFileInfo folder, dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Size)) {
            folder_size.insert(folder.fileName(), getSizeOfFilesIn(folder.absoluteFilePath()));
        }
        // TODO: отсортировать map

        qDebug() << " Bytes Filename"; //выводим заголовок
        /* в цикле выводим сведения о файлах */

        QMap<QString, quint64>::iterator i;
        for (i = folder_size.begin(); i != folder_size.end(); ++i) {
            qDebug() << qPrintable(QString("%1 %2").arg(i.value(), 10).arg(i.key()));
            qDebug() << qPrintable(QString("%1 %2 %3")
                                       .arg("Bytes", 15)
                                       .arg("Folder", 30)
                                       .arg("Percent", 21));
            qDebug() << " ";


            // Calculating size of the whole folder
            quint64 dotFolderSize = 0;
            for (int i = 0; i < listOfExt.size(); ++i) {
                dotFolderSize += listOfExt[i].first;
            };

            /* в цикле выводим сведения о файлах */
            for (int i = 0; i < listOfExt.size(); ++i) {
                qDebug() << qPrintable(QString("%1 %2 %3%")
                                           .arg(listOfExt[i].first, 15)
                                           .arg(listOfExt[i].second, 30)
                                           .arg(QString::number((static_cast<double>(listOfExt[i].first) / static_cast<double>(dotFolderSize)), 'f', 2), 20));
            };
    };
};


#endif // FOLDERCALCULATIONSTRATEGY_H
