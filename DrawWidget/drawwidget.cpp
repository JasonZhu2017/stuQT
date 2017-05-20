#include "drawwidget.h"
#include <QPainter>
#include <QPaintDevice>
#include <QPoint>
#include <QPen>
#include <QDebug>

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    pix = new QPixmap(size());
    pix->fill(Qt::white);
    setMinimumSize(600, 400);
}

void DrawWidget::mousePressEvent(QMouseEvent *event)
{
    startPos = event->pos();
}

void DrawWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPainter painter;


    QPen pen;
    pen.setStyle((Qt::PenStyle)style);
    pen.setWidth(weight);
    pen.setColor(color);
    painter.begin(pix);
//    qDebug() << color;
    painter.setPen(pen);
    painter.drawLine(startPos, event->pos());
    painter.end();
    startPos = event->pos();
    update();
}

void DrawWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(QPoint(0, 0), *pix);

}

void DrawWidget::resizeEvent(QResizeEvent *event)
{
    if (width() > pix->width() || height() > pix->height())
    {
        QPixmap * newPix = new QPixmap(size());
        newPix->fill(Qt::white);
        QPainter painter(newPix);
        painter.drawPixmap(QPoint(0, 0), *pix);
        pix = newPix;
    }
    QWidget::resizeEvent(event);
}

void DrawWidget::setStyle(int s)
{
    style = s;
}

void DrawWidget::setWidth(int w)
{
    weight = w;
}

void DrawWidget::setColor(QColor c)
{
    color = c;
}

void DrawWidget::clear()
{
    QPixmap * clearPix = new QPixmap(size());
    clearPix->fill(Qt::white);
    pix = clearPix;
    update();
}
