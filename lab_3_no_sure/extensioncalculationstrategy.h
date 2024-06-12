#ifndef EXTENSIONCALCULATIONSTRATEGY_H
#define EXTENSIONCALCULATIONSTRATEGY_H
QMap<QString, quint64> extensionCalculate(QString path, QMap<QString, quint64>& map) {
    QFileInfo fileInfo = QFileInfo(path);
    if (fileInfo.isDir()) {
        QDir dir = fileInfo.dir();
        if (dir.cd(fileInfo.fileName())) {
            foreach (QFileInfo file, dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Size)) {
if (map.contains(file.completeSuffix())) {
    map[file.completeSuffix()] += file.size();
}
else {
    map[file.completeSuffix()] = file.size();
}
}
foreach (QFileInfo folder, dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Size)) {
    extensionCalculate(folder.absoluteFilePath(), map);
}
}
}
return map;
}

std::sort(listOfFolders.begin(), listOfFolders.end());

qDebug() << qPrintable(QString("%1 %2 %3")
                           .arg("Bytes", 15)
                           .arg("Extension", 30)
                           .arg("Percent", 21));
qDebug() << " ";

// Calculating size of the whole folder
quint64 dotFolderSize = 0;
for (int i = 0; i < listOfFolders.size(); ++i) {
dotFolderSize += listOfFolders[i].first;
};

/* в цикле выводим сведения о файлах */
for (int i = 0; i < listOfFolders.size(); ++i) {
qDebug() << qPrintable(QString("%1 %2 %3%")
                           .arg(listOfFolders[i].first, 15)
                           .arg(listOfFolders[i].second, 30)
                           .arg(QString::number((static_cast<double>(listOfFolders[i].first) / static_cast<double>(dotFolderSize)), 'f', 2), 20));
}
};
class ExtensionCalculationStrategy : public CalculationStrategy {
public:
    void calculate(QString path) {
        QDir dir = QDir("C:/Users/lekks/TSU/semester 6/TRPO/5-12/lab3/testFiles"); //объявляем объект работы с папками
        //        dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        //        ///устанавливаем фильтр выводимых файлов
        //        dir.setSorting(QDir::Size | QDir::Reversed); //устанавливаем сортировку "от меньшего к большему"
        //        QFileInfoList list = dir.entryInfoList(); //получаем список файлов директории
        QMap<QString, quint64> extensions_size;
        extensions_size = extensionCalculate(path, extensions_size);
        qDebug() << " Bytes Extension"; //выводим заголовок
        /* в цикле выводим сведения о файлах */

        QMap<QString, quint64>::iterator i;
        for (i = extensions_size.begin(); i != extensions_size.end(); ++i) {
            qDebug() << qPrintable(QString("%1 %2").arg(i.value(), 10).arg(i.key()));
        }

    }
};


#endif // EXTENSIONCALCULATIONSTRATEGY_H
