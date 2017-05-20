#include "flashitem.h"
#include <QDebug>

FlashItem::FlashItem(QObject *parent) : QObject(parent)
{
    flash = true;

    setFlag(ItemIsMovable);
    startTimer(1000);
}

void FlashItem::timerEvent(QTimerEvent *event)
{
    flash = !flash;
    update();
//    qDebug() << flash << "call timerEvent";
}

void FlashItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkGray);
    painter->drawEllipse(-7, -7, 40, 40);

//    painter->setPen(QPen(Qt::black, 0));
    painter->setPen(Qt::NoPen);
    painter->setBrush(flash? (Qt::red) : (Qt::yellow));
    painter->drawEllipse(-10, -10, 40, 40);
//    qDebug() << flash << "call paint";
}

QRectF FlashItem::boundingRect() const
{
    qreal adjust = 2;
    QRectF rect(-10-adjust, -10-adjust, 43+adjust, 43+adjust);
    return rect;
}
