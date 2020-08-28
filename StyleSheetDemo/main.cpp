#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //set style shett application wise
    a.setStyleSheet("QPushButton{color:red; background-color: white;}");
    Widget w;
    w.show();
    return a.exec();
}
