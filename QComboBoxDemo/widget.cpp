#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->comboBox->addItem("Earth");
    ui->comboBox->addItem("Venus");
    ui->comboBox->addItem("Mars");
    ui->comboBox->addItem("Jupyter");

    ui->comboBox->setEditable(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_captureButton_clicked()
{
    qDebug() << "Selected: " << ui->comboBox->currentText() << " with index :" << ui->comboBox->currentIndex();

}

void Widget::on_setButton_clicked()
{
    ui->comboBox->setCurrentIndex(3);
}

void Widget::on_getButton_clicked()
{
    qDebug() << "Count of items: " << ui->comboBox->count();
    for(int i=0;i< ui->comboBox->count();i++){
        qDebug() << ui->comboBox->itemText(i);
    }
}
