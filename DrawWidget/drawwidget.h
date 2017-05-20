#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>
#include <QColor>
#include <QMouseEvent>
#include <QResizeEvent>
#include <QPaintEvent>

class DrawWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawWidget(QWidget *parent = 0);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);


signals:

public slots:
    void setStyle(int s);
    void setWidth(int w);
    void setColor(QColor);
    void clear();

private:
    QPixmap* pix;
    QPoint startPos;
    QPoint endPos;
    int style;
    int weight;
    QColor color;
};

#endif // DRAWWIDGET_H
