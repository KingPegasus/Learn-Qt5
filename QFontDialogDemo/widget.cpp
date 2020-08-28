#include "widget.h"
#include "ui_widget.h"
#include <QFontDialog>
#include <QDebug>
#include <QMessageBox>

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
    bool ok;
     QFont font = QFontDialog::getFont(
                     &ok, QFont("Helvetica [Cronyx]", 10), this);
     if (ok) {
         ui->label->setFont(font);
         // the user clicked OK and font is set to the font the user selected
     } else {
         // the user canceled the dialog; font is set to the initial
         // value, in this case Helvetica [Cronyx], 10
         QMessageBox::information(this, "Meassge", "User didn't choose the font");

     }
}
