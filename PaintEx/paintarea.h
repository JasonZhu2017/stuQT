#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPainter>

class PaintArea : public QWidget
{
    Q_OBJECT
public:
    enum Shape{Line, Rectangle, RoundRect, Ellipse, Polygon, Polyline, Points, Arc, Path, Text, Pixmap};
    explicit PaintArea(QWidget *parent = 0);

    void setShape(Shape s);
    void setPen(QPen p);
    void setBrush(QBrush b);
    void setFillRule(Qt::FillRule rule);
    void paintEvent(QPaintEvent* e);

signals:

public slots:

private:
    Shape shape;
    QPen pen;
    QBrush brush;
    Qt::FillRule fillRule;
};

#endif // PAINTAREA_H
