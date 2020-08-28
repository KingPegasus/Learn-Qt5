#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent,Qt::WindowSystemMenuHint | Qt::WindowTitleHint),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QString userPosition = ui->lineEdit->text();
    if(!userPosition.isEmpty()){
        position = userPosition;

        if(ui->radioButton->isChecked())
        {
            FavOne = "windows";
        }
        if(ui->radioButton_2->isChecked())
        {
            FavOne = "Mac";
        }
        if(ui->radioButton_3->isChecked())
        {
            FavOne = "linux";
        }
    }

    accept();

}

void Dialog::on_pushButton_2_clicked()
{
    reject();
}

QString Dialog::getPosition() const
{
    return position;
}

QString Dialog::getFavOne() const
{
    return FavOne;
}
