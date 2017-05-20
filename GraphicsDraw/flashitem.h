#ifndef FLASHITEM_H
#define FLASHITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QTimer>
#include <QTimerEvent>


class FlashItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit FlashItem(QObject *parent = 0);

    void timerEvent(QTimerEvent *event);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
signals:

public slots:

private:
    bool flash;
    QTimer * timer;

};

#endif // FLASHITEM_H
