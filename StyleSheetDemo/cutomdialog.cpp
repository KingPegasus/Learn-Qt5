#include "cutomdialog.h"
#include "ui_cutomdialog.h"

CutomDialog::CutomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CutomDialog)
{
    ui->setupUi(this);
}

CutomDialog::~CutomDialog()
{
    delete ui;
}
