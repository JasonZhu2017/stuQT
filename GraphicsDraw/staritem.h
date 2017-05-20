#ifndef STARITEM_H
#define STARITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

class StarItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit StarItem(QObject *parent = 0);

    QRectF boundingRect() const;
    void timerEvent(QTimerEvent *event);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QPixmap pix;
signals:

public slots:
};

#endif // STARITEM_H
