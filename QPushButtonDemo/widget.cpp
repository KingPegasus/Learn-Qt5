#include "widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // Clicked Signal
    QFont buttonFont("Times", 20, QFont:: Bold);
    QPushButton * button = new QPushButton("Button1",this);
    button->setMinimumSize(200,100);
    button->setFont(buttonFont);
    connect(button, &QPushButton::clicked, [=](){
        qDebug() << "button clicked";
    });


    QPushButton * button2 = new QPushButton("Button2",this);
    button2->setMinimumSize(200,100);
    button2->move(205,0);
    button2->setFont(buttonFont);
    connect(button2, &QPushButton::pressed, [=](){
        qDebug() << "button pressed";
    });
    connect(button2, &QPushButton::released, [=](){
        qDebug() << "button released";
    });

}

Widget::~Widget()
{
}

