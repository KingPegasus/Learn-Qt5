#include "widget.h"
#include "ui_widget.h"
#include <QGridLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QGridLayout * layout = new QGridLayout(this);

    layout->addWidget(ui->pushButton1,0,0);
    layout->addWidget(ui->pushButton2,0,1);
    layout->addWidget(ui->pushButton3,0,2,2,1);

    layout->addWidget(ui->pushButton4,1,0);
    layout->addWidget(ui->pushButton5,1,1);
    //layout->addWidget(ui->pushButton6,1,2);

    layout->addWidget(ui->pushButton7,2,0);
    layout->addWidget(ui->pushButton8,2,1);
    layout->addWidget(ui->pushButton9,2,2);

    setLayout(layout);

}

Widget::~Widget()
{
    delete ui;
}

