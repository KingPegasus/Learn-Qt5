#include "widget.h"
#include "ui_widget.h"
#include <QColorDialog>
#include <QSettings>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    for(int i=0; i<9; i++){
        colorList.append(Qt::black);

    }
}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_pushButton1_clicked()
{
    QColor color = QColorDialog::getColor(colorList[0],this,"Choose Background Color");
    if( color.isValid()){
        colorList[0]=color;

        QString css = QString("background-color: %1").arg(color.name());
        ui->pushButton1->setStyleSheet(css);
    }
}

void Widget::on_pushButton2_clicked()
{
    QColor color = QColorDialog::getColor(colorList[1],this,"Choose Background Color");
    if( color.isValid()){
        colorList[1]=color;

        QString css = QString("background-color: %1").arg(color.name());
        ui->pushButton2->setStyleSheet(css);
    }

}

void Widget::on_pushButton3_clicked()
{
    QColor color = QColorDialog::getColor(colorList[2],this,"Choose Background Color");
    if( color.isValid()){
        colorList[2]=color;

        QString css = QString("background-color: %1").arg(color.name());
        ui->pushButton3->setStyleSheet(css);
    }
}



void Widget::on_pushButton4_clicked()
{
    QColor color = QColorDialog::getColor(colorList[3],this,"Choose Background Color");
    if( color.isValid()){
        colorList[3]=color;

        QString css = QString("background-color: %1").arg(color.name());
        ui->pushButton4->setStyleSheet(css);
    }
}

void Widget::on_pushButton5_clicked()
{
    QColor color = QColorDialog::getColor(colorList[4],this,"Choose Background Color");
    if( color.isValid()){
        colorList[4]=color;

        QString css = QString("background-color: %1").arg(color.name());
        ui->pushButton5->setStyleSheet(css);
    }
}

void Widget::on_pushButton6_clicked()
{
    QColor color = QColorDialog::getColor(colorList[5],this,"Choose Background Color");
    if( color.isValid()){
        colorList[5]=color;

        QString css = QString("background-color: %1").arg(color.name());
        ui->pushButton6->setStyleSheet(css);
    }
}

void Widget::on_pushButton7_clicked()
{
    QColor color = QColorDialog::getColor(colorList[6],this,"Choose Background Color");
    if( color.isValid()){
        colorList[6]=color;

        QString css = QString("background-color: %1").arg(color.name());
        ui->pushButton7->setStyleSheet(css);
    }
}

void Widget::on_pushButton8_clicked()
{
    QColor color = QColorDialog::getColor(colorList[7],this,"Choose Background Color");
    if( color.isValid()){
        colorList[7]=color;

        QString css = QString("background-color: %1").arg(color.name());
        ui->pushButton8->setStyleSheet(css);
    }
}

void Widget::on_pushButton9_clicked()
{
    QColor color = QColorDialog::getColor(colorList[8],this,"Choose Background Color");
    if( color.isValid()){
        colorList[8]=color;
        qDebug() << color;
        QString css = QString("background-color: %1").arg(color.name());
        ui->pushButton9->setStyleSheet(css);
    }
}

void Widget::on_pushButton_11_clicked()
{
    setLoadedColor("pushButton1",0,ui->pushButton1);
    setLoadedColor("pushButton2",1,ui->pushButton2);
    setLoadedColor("pushButton3",2,ui->pushButton3);
    setLoadedColor("pushButton4",3,ui->pushButton4);
    setLoadedColor("pushButton5",4,ui->pushButton5);
    setLoadedColor("pushButton6",5,ui->pushButton6);
    setLoadedColor("pushButton7",6,ui->pushButton7);
    setLoadedColor("pushButton8",7,ui->pushButton8);
    setLoadedColor("pushButton9",8,ui->pushButton9);
}

void Widget::on_pushButton_10_clicked()
{
    saveColor("pushButton1",colorList[0]);
    saveColor("pushButton2",colorList[1]);
    saveColor("pushButton3",colorList[2]);
    saveColor("pushButton4",colorList[3]);
    saveColor("pushButton5",colorList[4]);
    saveColor("pushButton6",colorList[5]);
    saveColor("pushButton7",colorList[6]);
    saveColor("pushButton8",colorList[7]);
    saveColor("pushButton9",colorList[8]);

}

void Widget::saveColor(QString key, QColor color)
{
    int red = color.red();
    int green = color.green();
    int blue = color.blue();

    QSettings settings("Blikoon","SettingDemo");
    settings.beginGroup("ButtonColor");
    settings.setValue(key+"r",red);
    settings.setValue(key+"g",green);
    settings.setValue(key+"b",blue);
    settings.endGroup();

}

QColor Widget::loadColor(QString key)
{
    int red;
    int green;
    int blue;

    QSettings settings("Blikoon","SettingDemo");
    settings.beginGroup("ButtonColor");
    red = settings.value(key+"r",QVariant(0)).toInt();
    green = settings.value(key+"g",QVariant(0)).toInt();
    blue = settings.value(key+"b",QVariant(0)).toInt();

    settings.endGroup();

    return QColor(red,green,blue);
}

void Widget::setLoadedColor(QString key, int index, QPushButton *button)
{
    QColor color = loadColor(key);
    colorList[index] = color;
    QString css = QString("background-color: %1").arg(color.name());
    button->setStyleSheet(css);
}
