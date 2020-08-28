#include "infodialog.h"
#include "ui_infodialog.h"

#include <QDebug>
InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    QDialogButtonBox::StandardButton stdButton = ui->buttonBox->standardButton(button);

    if(stdButton == QDialogButtonBox::Ok){
        qDebug() << "OK button clicked";
    }
    if(stdButton == QDialogButtonBox::Save){
        qDebug() << "Save button clicked";
    }
    if(stdButton == QDialogButtonBox::SaveAll){
        qDebug() << "SaveAll button clicked";
    }
    if(stdButton == QDialogButtonBox::Cancel){
        qDebug() << "Cancel button clicked";
    }
}
