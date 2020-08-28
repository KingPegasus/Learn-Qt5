#include "widget.h"
#include "ui_widget.h"
#include "dialog.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    Dialog * dialog = new Dialog(this);

    /*
    //show the dialog modal
    int ret = dialog->exec();

    if( ret== QDialog::Accepted){
        QString position = dialog->getPosition();
        QString os = dialog->getFavOne();
        ui->label->setText("Position= " + position + " and Fav os=" + os);
        qDebug() << "Accepted: Position= "<< position<<" and Fav os=" << os;
    }
    if( ret== QDialog::Rejected){
        qDebug() << "Rejected";
    }*/

    //show the dialog non-modal
    // now we will make connection because .show() does not return anything
    connect(dialog, &Dialog::accepted,[=](){
        QString position = dialog->getPosition();
        QString os = dialog->getFavOne();
        ui->label->setText("Position= " + position + " and Fav os=" + os);
        qDebug() << "Accepted: Position= "<< position<<" and Fav os=" << os;

    });

    connect(dialog, &Dialog::rejected,[=](){
        qDebug() << "Rejected";

    });

    dialog->show();
    dialog->raise();
    dialog->activateWindow();
}
