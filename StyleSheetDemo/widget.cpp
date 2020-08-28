#include "widget.h"
#include "ui_widget.h"
#include "cutomdialog.h"
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
    CutomDialog * dialog = new CutomDialog(this);

    dialog->setStyleSheet("QPushButton{background-color:yellow; color: blue;}");
    dialog->exec();
}
