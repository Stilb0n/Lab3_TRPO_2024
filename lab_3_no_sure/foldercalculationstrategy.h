#ifndef FOLDERCALCULATIONSTRATEGY_H
#define FOLDERCALCULATIONSTRATEGY_H

class FolderCalculationStrategy : public CalculationStrategy {
            public:
                 FolderCalculationStrategy() {};
    void calculate(QString path) override {
        QDir dir = QDir("C:/Users/lekks/TSU/semester 6/TRPO/5-12/lab3/testFiles"); //объявляем объект работы с папками
        //        dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        //        ///устанавливаем фильтр выводимых файлов
        //        dir.setSorting(QDir::Size | QDir::Reversed); //устанавливаем сортировку "от меньшего к большему"
        //        QFileInfoList list = dir.entryInfoList(); //получаем список файлов директории
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
        }

        //        for (int i = 0; i < list.size(); ++i) {
        //            QFileInfo fileInfo = list.at(i);
        //            qDebug() << qPrintable(QString("%1 %2").arg(fileInfo.size(), 10).arg(fileInfo.fileName())); //выводим в формате "размер имя", переносим строку
        //        }
    };
};


#endif // FOLDERCALCULATIONSTRATEGY_H
