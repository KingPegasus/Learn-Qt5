#include "widget.h"
#include <QTextEdit>
#include <QPushButton>
#include <QDebug>
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setupUi();
    setFixedSize(400,400);
}

Widget::~Widget()
{
}

void Widget::setupUi()
{
    QFont labelFont("Times", 10, QFont::Bold);
    QLabel * mLabel = new QLabel("This is my text",this);
    mLabel->setFont(labelFont);
    mLabel->move(100,25);

    QTextEdit * textEdit = new QTextEdit(this);
    textEdit->move(70,55);

    //textchanged
    /*connect(textEdit,&QTextEdit::textChanged,[=](){
        qDebug() << "Text Changed";
    });*/

    //copy, cut and paste
    QPushButton * copyButton =  new QPushButton("Copy",this);
    copyButton->setMinimumSize(50,25);
    copyButton->move(10,250);
    connect(copyButton,&QPushButton::clicked,[=](){
        textEdit->copy();
    });

    QPushButton * cutButton =  new QPushButton("Cut",this);
    cutButton->setMinimumSize(50,25);
    cutButton->move(110,250);
    connect(cutButton,&QPushButton::clicked,[=](){
        textEdit->cut();
    });

    QPushButton * pasteButton =  new QPushButton("Paste",this);
    pasteButton->setMinimumSize(50,25);
    pasteButton->move(210,250);
    connect(pasteButton,&QPushButton::clicked,[=](){
        textEdit->paste();
    });

    //Undo Redo
    QPushButton * undoButton =  new QPushButton("Undo",this);
    undoButton->setMinimumSize(50,25);
    undoButton->move(10,280);
    connect(undoButton,&QPushButton::clicked,[=](){
        textEdit->undo();
    });

    QPushButton * redoButton =  new QPushButton("Redo",this);
    redoButton->setMinimumSize(50,25);
    redoButton->move(110,280);
    connect(redoButton,&QPushButton::clicked,[=](){
        textEdit->redo();
    });

    //Set Text and html to the test edit
    QPushButton * plainTextButton =  new QPushButton("Plain Text",this);
    plainTextButton->setMinimumSize(100,25);
    plainTextButton->move(10,310);
    connect(plainTextButton,&QPushButton::clicked,[=](){
        textEdit->setPlainText("This is a Plaintext");
    });

    QPushButton * htmlButton =  new QPushButton("HTML",this);
    htmlButton->setMinimumSize(100,25);
    htmlButton->move(10,310);
    connect(htmlButton,&QPushButton::clicked,[=](){
        textEdit->setHtml("<h1>This is heading 1</h1>\
                          <h2>This is heading 2</h2>\
                          <h3>This is heading 3</h3>\
                          <h4>This is heading 4</h4>\
                          <h5>This is heading 5</h5>\
                          <h6>This is heading 6</h6>");
    });

    //Grab text and html
    QPushButton * grabTextButton =  new QPushButton("Grab Text",this);
    grabTextButton->setMinimumSize(100,25);
    grabTextButton->move(10,340);
    connect(grabTextButton,&QPushButton::clicked,[=](){
        qDebug() <<"Grabbed: " << textEdit->toPlainText();
    });

    QPushButton * htmlTextButton =  new QPushButton("Grab Html",this);
    htmlTextButton->setMinimumSize(100,25);
    htmlTextButton->move(120,340);
    connect(htmlTextButton,&QPushButton::clicked,[=](){
        qDebug() <<"Grabbed: " << textEdit->toHtml();
    });

}

