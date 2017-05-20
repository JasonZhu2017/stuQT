#ifndef MAPWIDGET_H
#define MAPWIDGET_H
#include <QGraphicsView>
//#include <QPixmap>
//#include <QPainter>
#include <QLabel>
#include <QMouseEvent>


class MapWidget : public QGraphicsView
{
public:
    MapWidget();

    void readMap();
    QPointF mapToMap(QPointF);

public slots:
    void slotZoom(int);

protected:
    void drawBackground(QPainter* painter, const QRectF & rect);
    void mouseMoveEvent(QMouseEvent* event);

private:
    QPixmap map;
    qreal zoom;
    QLabel* viewCoord;
    QLabel* sceneCoord;
    QLabel* mapCoord;
    qreal x1, y1;
    qreal x2, y2;

};

#endif // MAPWIDGET_H
