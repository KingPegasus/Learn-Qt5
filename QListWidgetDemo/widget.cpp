#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_addButton_clicked()
{
    ui->listWidget->addItem("My Item");

}

void Widget::on_delButton_clicked()
{
    ui->listWidget->takeItem(ui->listWidget->currentRow());
}

void Widget::on_selButton_clicked()
{
    QList<QListWidgetItem *> list = ui->listWidget->selectedItems();
    for (int i=0; i< list.count();i++){
        qDebug() << "selected :" << list.at(i)->text() << " row id: " << ui->listWidget->row(list.at(i));

    }
}
