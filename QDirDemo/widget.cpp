#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
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
    QString filename = QFileDialog::getExistingDirectory(this, "Choose Folder");
    if(filename.isEmpty())
        return;
    ui->lineEdit->setText(filename);
}

void Widget::on_pushButton_2_clicked()
{
     QString dirPath = ui->lineEdit->text();
     if(dirPath.isEmpty())
         return;
     QDir dir(dirPath);
     if(!dir.exists()){
         if(dir.mkdir(dirPath)){
             QMessageBox::information(this,"Message","Directory created");
         }
     }else{
         QMessageBox::information(this,"Message","Directory already exists");
     }

}

void Widget::on_pushButton_3_clicked()
{
    QString dirPath = ui->lineEdit->text();
    if(dirPath.isEmpty())
        return;
    QDir dir(dirPath);
    if(dir.exists()){
        QMessageBox::information(this,"Message","Directory exists");
    }else{
        QMessageBox::information(this,"Message","Directory doesnot exists");

    }
}

void Widget::on_pushButton_4_clicked()
{
    QFileInfo fileInfo(ui->listWidget->currentItem()->text());
    if(fileInfo.isDir()){
        QMessageBox::information(this,"Message","This is a Dir");
    }else if(fileInfo.isFile()){
        QMessageBox::information(this,"Message","This is a File");
    }else{
        QMessageBox::information(this,"Message","This is a Other");
    }
}

void Widget::on_pushButton_5_clicked()
{
    ui->listWidget->clear();
    QString dirPath = ui->lineEdit->text();
    if(dirPath.isEmpty())
        return;
    QDir dir(dirPath);

    dir.entryInfoList();

    QList <QFileInfo> fileList = dir.entryInfoList();

    for (int i=0; i<fileList.size(); i++){
//        QString prefix;
//        if(fileList.at(i).isFile()){
//            prefix = "FILE:";
//        }
//        if(fileList.at(i).isDir()){
//            prefix = "DIRECTORY: ";
//        }
        ui->listWidget->addItem(fileList.at(i).absoluteFilePath());
    }
}
