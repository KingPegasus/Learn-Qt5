#include "rockwidget.h"
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

RockWidget::RockWidget(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("ROCk Widget");
    QLabel * label = new QLabel("This is my Label",this);

    QFont label1Font("Times", 20, QFont::Bold);
    QPalette label1Palette;
    label1Palette.setColor(QPalette::Window,Qt::yellow);
    label1Palette.setColor(QPalette::WindowText,Qt::blue);

    QLabel * label1 = new QLabel(this);
    label1->setAutoFillBackground(true);
    label1->setText("This is another label lets move it.");
    label1->setFont(label1Font);
    label1->setPalette(label1Palette);
    label1->move(50,50);

    //Add a button and connect to slot
    QFont button1Font("Times", 30, QFont::Bold);
    QPushButton * button1 = new QPushButton(this);
    button1->setFont(button1Font);
    button1->setText("Click Me");
    button1->move(100,100);
    connect(button1,SIGNAL(clicked()),this,SLOT(buttonClicked()));
}

void RockWidget::buttonClicked()
{
    QMessageBox::information(this,"Message","You clicked on my button");
}

QSize RockWidget::sizeHint() const
{
    return QSize(500,300);
}
