#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimerEvent>
#include <QRectF>
#include <QPainter>



class Butterfly : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Butterfly(QObject *parent = 0);
    void timerEvent(QTimerEvent* e);
    QRectF boundingRect() const;


signals:

public slots:

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

private:
    bool up;
    QPixmap pix_up;
    QPixmap pix_down;

    qreal angle;
};

#endif // BUTTERFLY_H
