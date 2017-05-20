#ifndef SVGWIDGET_H
#define SVGWIDGET_H
#include <QSvgWidget>
#include <QSvgRenderer>
#include <QWheelEvent>


class SvgWidget : public QSvgWidget
{
public:
    SvgWidget(QWidget* parent=0);
    void wheelEvent(QWheelEvent* );

private:
    QSvgRenderer* render;

};

#endif // SVGWIDGET_H
