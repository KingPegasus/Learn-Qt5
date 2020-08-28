#include "widget.h"
#include "ui_widget.h"
#include <stdlib.h>
#include <time.h>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    srand(time(NULL));

    secretNumber = rand()%10 +1;

    qDebug() << "Secret No. : " << QString::number(secretNumber);
    ui->messageLabel->setText("");
    ui->startOverButton->setDisabled(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_guessButton_clicked()
{
    guessNumber = ui->spinBox->value();
    qDebug() << "Guess N0. : " << QString::number(guessNumber);
    if(guessNumber == secretNumber){
        ui->messageLabel->setText("You are right!!!");
        ui->guessButton->setDisabled(true);
        ui->startOverButton->setDisabled(false);
    }
    else if (secretNumber< guessNumber){
        ui->messageLabel->setText("Number is lower than that");
    }else{
        ui->messageLabel->setText("Number is higher than that");
    }
}

void Widget::on_startOverButton_clicked()
{
    ui->guessButton->setDisabled(false);
    ui->startOverButton->setDisabled(true);
    ui->spinBox->setValue(1);
    secretNumber = rand()%10 +1;
    ui->messageLabel->setText("");
}
