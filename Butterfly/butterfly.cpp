#include "butterfly.h"
#include <QPoint>
#include <QPainter>
#include <QDebug>

const static double PI = 3.1416;
Butterfly::Butterfly(QObject *parent) : QObject(parent)
{
    up = true;
    pix_up.load("up.png");
    pix_down.load("down.png");
    startTimer(100);
}

void Butterfly::timerEvent(QTimerEvent *e)
{
    qreal edgex = scene()->sceneRect().right() + boundingRect().width()/2;
    qreal edgeTop = scene()->sceneRect().top() + boundingRect().height()/2;
    qreal edgeBottom = scene()->sceneRect().bottom() + boundingRect().height()/2;
//    qDebug() << scene()->sceneRect();
    if (pos().x() >= edgex)
        setPos(scene()->sceneRect().left(), pos().y());
    if (pos().x() <= edgeTop)
        setPos(pos().x(), scene()->sceneRect().bottom());
    if (pos().y() >= edgeBottom)
        setPos(pos().x(), scene()->sceneRect().top());

    angle += (qrand()%10)/20.0;
    qreal dx = fabs(sin(angle*PI)*10.0);
    qreal dy = (qrand()%20)-10.0;
    setPos(mapToParent(dx, dy));
}

QRectF Butterfly::boundingRect() const
{
    qreal adjust = 2;
    return QRectF(-pix_up.width()/2-adjust, -pix_up.height()/2-adjust,
                  pix_up.width()+2*adjust, pix_up.height()+2*adjust);

}

void Butterfly::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(up)

    {
        painter->drawPixmap(boundingRect().topLeft(), pix_up);
        up = !up;
    }
    else
    {
        painter->drawPixmap(boundingRect().topLeft(), pix_down);
        up = !up;
    }
}
