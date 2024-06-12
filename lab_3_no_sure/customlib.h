#ifndef CUSTOMLIB_H
#define CUSTOMLIB_H

#include <QDir>
#include <QFileInfo>
#include <QString>
qint64 getSizeOfFilesIn(QString path) {
    QFileInfo fileInfo = QFileInfo(path);
    if (fileInfo.isDir()) {
        QDir dir = fileInfo.dir();
        if (dir.cd(fileInfo.fileName())) {
            qint64 currentDirectorySize = 0;
            foreach (QFileInfo file, dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Size)) {
                currentDirectorySize += file.size();
            }
            return currentDirectorySize;
        }
    }
    else {
        return fileInfo.size();
    }
}

void show(QList<QPair<quint64, QString>> size_item, QString second_item_name) {
    qDebug() << qPrintable(QString("%1 %2 %3")
                               .arg("Bytes", 15)
                               .arg(second_item_name, 30)
                               .arg("Percent", 21));
    qDebug() << " ";

    // Calculating size of the whole folder
    quint64 totalSize = 0;
    for (int i = 0; i < size_item.size(); ++i) {
        totalSize += size_item[i].first;
    };

    /* в цикле выводим сведения о файлах */
    for (int i = 0; i < size_item.size(); ++i) {
        qDebug() << qPrintable(QString("%1 %2 %3%")
                                   .arg(size_item[i].first, 15)
                                   .arg(size_item[i].second, 30)
                                   .arg(QString::number((static_cast<double>(size_item[i].first) / static_cast<double>(totalSize)), 'f', 2), 20));
    }
}


qint64 getSizeOf(QString path) {
    QFileInfo fileInfo = QFileInfo(path);
    if (fileInfo.isDir()) {
        QDir dir = fileInfo.dir();
        if (dir.cd(fileInfo.fileName())) {
            qint64 currentDirectorySize = 0;
            foreach (QFileInfo file, dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Size)) {
                currentDirectorySize += file.size();
            }
            foreach (QFileInfo folder, dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Size)) {
                currentDirectorySize += getSizeOf(folder.absoluteFilePath());
            }
            return currentDirectorySize;
        }
    }
    else {
        return fileInfo.size();
    }
}

#endif // CUSTOMLIB_H
