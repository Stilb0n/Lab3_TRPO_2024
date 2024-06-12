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

        //        for (int i = 0; i < list.size(); ++i) {
        //            QFileInfo fileInfo = list.at(i);
        //            qDebug() << qPrintable(QString("%1 %2").arg(fileInfo.size(), 10).arg(fileInfo.fileName())); //выводим в формате "размер имя", переносим строку
        //        }
    }
};


#endif // EXTENSIONCALCULATIONSTRATEGY_H
