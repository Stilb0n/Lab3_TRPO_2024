#ifndef CUSTOMLIB_H
#define CUSTOMLIB_H

#include <QDir>
#include <QFileInfo>
#include <QString>


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
