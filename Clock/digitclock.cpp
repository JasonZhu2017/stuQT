#include "digitclock.h"
#include <QTimer>
#include <QTime>
#include <QString>
#include <QDebug>


DigitClock::DigitClock(QWidget *parent)
    :QLCDNumber(parent)
{
    QPalette p = this->palette();
    p.setColor(QPalette::Window, Qt::white);
    this->setPalette(p);

    setWindowFlags(Qt::FramelessWindowHint);
    setWindowOpacity(0.5);
    QTimer * timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DigitClock::showTime);
    timer->start(1000);
    showTime();
    resize(150,60);
    showColon = false;

}

void DigitClock::mouseMoveEvent(QMouseEvent *e)
{
    if (e->buttons() & Qt::LeftButton)
    {
//        move(e->globalPos()-dragPoint);
        move(e->globalPos());
//        qDebug
//        e->accept();
    }
}

void DigitClock::mousePressEvent(QMouseEvent *e)
{
    if (e->buttons() == Qt::LeftButton)
    {
        dragPoint = e->globalPos() - frameGeometry().topLeft();
        e->accept();
//        qDebug() << "press: " << dragPoint;
    }
    if (e->buttons() == Qt::RightButton)
    {
        close();
    }
}

void DigitClock::showTime()
{
    QTime time = QTime::currentTime();
    QString text;
    if (showColon)
    {
        text = time.toString("HH:mm");
        showColon = false;
    }
    else
    {
        text = time.toString("HH mm");
        showColon = true;
    }
    display(text);
}
