#include "widget.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // First NAme
    QLabel * firstNameLabel = new QLabel("FIrst Name", this);
    firstNameLabel->setMinimumSize(70,50);
    firstNameLabel->move(10,10);

    QLineEdit * firstNameLineEdit = new QLineEdit(this);
    firstNameLineEdit->setMinimumSize(200,50);
    firstNameLineEdit->move(100,10);

    // Last NAme
    QLabel * lastNameLabel = new QLabel("Last Name", this);
    lastNameLabel->setMinimumSize(70,50);
    lastNameLabel->move(10,70);

    QLineEdit * lastNameLineEdit = new QLineEdit(this);
    lastNameLineEdit->setMinimumSize(200,50);
    lastNameLineEdit->move(100,70);

    // City
    QLabel * cityLabel = new QLabel("City", this);
    cityLabel->setMinimumSize(70,50);
    cityLabel->move(10,130);

    QLineEdit * cityLineEdit = new QLineEdit(this);
    cityLineEdit->setMinimumSize(200,50);
    cityLineEdit->move(100,130);

    //Button
    QFont buttonFont("Times", 20, QFont::Bold);
    QPushButton * button = new QPushButton("Grab Data", this);
    button->setFont(buttonFont);
    button->move(80,190);
    connect(button, &QPushButton::clicked,[=](){
        QString firstName = firstNameLineEdit->text();
        QString lastName = lastNameLineEdit->text();
        QString city = cityLineEdit->text();

        qDebug() << " First Name: " << firstName;
        qDebug() << " Last Name: " << lastName;
        qDebug() << " City: " << city;


    });

    //Respond to signals from QLineEdit

    // Cursor Postion changed
    connect(firstNameLineEdit,&QLineEdit::cursorPositionChanged,[=](){
        qDebug() << "Cursor pos : " << firstNameLineEdit->cursorPosition();

    });

    //editingFinished
    connect(lastNameLineEdit,&QLineEdit::editingFinished,[=](){
        qDebug() << "Editing finished.";

    });

    //returnPressed
    connect(cityLineEdit,&QLineEdit::returnPressed,[=](){
        qDebug() << "Return pressed.";

    });

    //selection changed
    connect(cityLineEdit,&QLineEdit::selectionChanged,[=](){
        qDebug() << "Selection Changed";

    });

    //text changed
    connect(cityLineEdit,&QLineEdit::textChanged,[=](){
        qDebug() << "Text Changed";

    });

    //text edited
    connect(lastNameLineEdit,&QLineEdit::textEdited,[=](){
        qDebug() << "Text Edited";

    });

    //Change text in QLineEdit Programatically
    //lastNameLineEdit->setText("Say your Last name");

    //Hint text
    firstNameLineEdit->setPlaceholderText("Firstname");

}

Widget::~Widget()
{
}

