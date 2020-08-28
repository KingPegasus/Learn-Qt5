#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<QString> stringList;

    stringList << "I am" << "lovin" << "Qt";
    stringList.append("4th");

    qDebug() << stringList[0];
    qDebug() << stringList.count();
    return a.exec();
}
