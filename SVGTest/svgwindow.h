#ifndef SVGWINDOW_H
#define SVGWINDOW_H
#include <QWidget>
#include <QScrollArea>
#include <svgwidget.h>
#include <QMouseEvent>
#include <QString>
#include <QPoint>
#include <QScrollBar>


class SvgWindow : public QScrollArea
{
public:
    SvgWindow(QWidget* parent=0);

    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void setFile(QString name);

private:
    SvgWidget* svgWidget;
    QPoint mousePressPos;
    QPoint scrollBarValue;

};

#endif // SVGWINDOW_H
