#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //String Notation
    /*
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),
            ui->progressBar,SLOT(setValue(int)));

    connect(ui->pushButton,SIGNAL(clicked()),
            this,SLOT(changeText()));
    */

    // Functor Notation : Regular Slots

    connect(ui->pushButton,&QPushButton::clicked,
            this,&Widget::changeText);
    //connect(ui->horizontalSlider,&QSlider::valueChanged,
     //       ui->progressBar,&QProgressBar::setValue);

    // Functor Notation : Lambdas
    /*
    connect(ui->pushButton,&QPushButton::clicked,
            [=](){
    ui->label->setText("Lambdas");
    });
    */

    connect(ui->horizontalSlider,&QSlider::valueChanged,
            [=](){
    ui->progressBar->setValue(ui->horizontalSlider->value());
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeText()
{
    qDebug() << "Changetext() func";
    ui->label->setText("Helloo");
}

