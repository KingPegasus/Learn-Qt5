#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // Retrive the palette
    QPalette palette = ui->label->palette();
    ui->label->setAutoFillBackground(true);

    //Modify
    palette.setColor(QPalette::Window,Qt::blue);
    palette.setColor(QPalette::WindowText,Qt::red);

    //Reset
    ui->label->setPalette(palette);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QPalette::ColorGroup activeButtonColorGroup = ui->pushButton->palette().currentColorGroup();
    QPalette::ColorGroup disabledButtonColorGroup = ui->pushButton_2->palette().currentColorGroup();
    qDebug() << "ACtive button color grp : " << activeButtonColorGroup;
    qDebug() << "Disabled button color grp : " << disabledButtonColorGroup;

}

void Widget::on_pushButton_2_clicked()
{

}
