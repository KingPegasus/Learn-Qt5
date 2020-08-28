#include "widget.h"
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton * button = new QPushButton(this);
    button->setText("Click ME");
    button->move(200,200);
    connect(button,&QPushButton::clicked,[=](){
        /* //The HArd Way
        QMessageBox message;
        message.setMinimumSize(300,100);
        message.setWindowTitle("Message Title");
        message.setText("Somthing Happendd");
        message.setInformativeText("Do you want to do something about it??");
        message.setIcon(QMessageBox::Critical);
        message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        message.setDefaultButton(QMessageBox::Cancel);

        int ret = message.exec();
        */
        //The Easy Way

        //Critical Message
        //int ret = QMessageBox::critical(this,"Message Title", "Something happened Do you want to do something about it??", QMessageBox::Ok | QMessageBox::Cancel);

        //Information message
        //int ret = QMessageBox::information(this,"Message Title", "Something happened Do you want to do something about it??", QMessageBox::Ok | QMessageBox::Cancel);

        //Question message
        //int ret = QMessageBox::question(this,"Message Title", "Something happened Do you want to do something about it??", QMessageBox::Ok | QMessageBox::Cancel);

        //Warning message
        int ret = QMessageBox::warning(this,"Message Title", "Something happened Do you want to do something about it??", QMessageBox::Ok | QMessageBox::Cancel);

        if ( ret == QMessageBox::Ok)
        {
            qDebug() << "User Clicked on OK";

        }
        if ( ret == QMessageBox::Cancel)
        {
            qDebug() << "User Clicked on Cancel";

        }
    });
}

Widget::~Widget()
{
}

