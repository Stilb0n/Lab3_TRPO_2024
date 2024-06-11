#include <QApplication>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDir myDir;
    myDir.setPath("C:/Users/lekks/TSU/semester 6/TRPO/5-12/lab3/testFiles");
    QFileInfo fileInfo = QFileInfo(myDir.path());
    /* Рассмотрим способы обхода содержимого папок на диске.
Предлагается вариант решения, который может быть применен для более сложных задач.
Итак, если требуется выполнить анализ содержимого папки, то необходимо организовать обход
содержимого.
Например:*/
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
            }
            dir.cdUp();//выходим из папки
        }}

    //-------------------------------------


    return a.exec();
}
