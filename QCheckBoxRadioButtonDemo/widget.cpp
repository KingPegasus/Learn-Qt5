#include "widget.h"
#include "ui_widget.h"
#include <QButtonGroup>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QButtonGroup * buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(ui->checkBox);
    buttonGroup->addButton(ui->checkBox_2);
    buttonGroup->addButton(ui->checkBox_3);

    buttonGroup->setExclusive(true);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_checkBox_toggled(bool checked)
{
    if(checked){
        qDebug()<<"CHecked";
    }
    else{
        qDebug()<<"UnCHecked";
    }
}

void Widget::on_pushButton_2_clicked()
{
    if(ui->checkBox->isChecked()){
         qDebug()<<"Windows CHecked";
    }else{
         qDebug()<<"Windows UnCHecked";
    }
}

void Widget::on_pushButton_clicked()
{
    if(ui->checkBox_4->isChecked()){
        ui->checkBox_4->setChecked(false);
    }else{
        ui->checkBox_4->setChecked(true);
    }
}
