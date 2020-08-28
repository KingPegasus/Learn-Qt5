#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPixmap imagePixmap("://images/sourcererio.PNG");
    ui->imageLabel->move(10,70);
    ui->imageLabel->setPixmap(imagePixmap.scaled(400,400));
}

Widget::~Widget()
{
    delete ui;
}

