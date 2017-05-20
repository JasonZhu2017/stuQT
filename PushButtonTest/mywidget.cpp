#include "mywidget.h"
#include <QPushButton>
#include <QFont>
#include <QApplication>

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(200, 120);
    setMaximumSize(300, 220);
    QPushButton * pQuitBtn = new QPushButton("quit", this);
    pQuitBtn->setGeometry(62, 40, 75, 30);
    pQuitBtn->setFont(QFont("time", 18, QFont::Bold));
    pQuitBtn->move(0,0);
    QObject::connect(pQuitBtn, &QPushButton::clicked,  &QApplication::quit);
}

myWidget::~myWidget()
{

}
