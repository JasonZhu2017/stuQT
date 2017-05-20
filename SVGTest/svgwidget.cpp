#include "svgwidget.h"

SvgWidget::SvgWidget(QWidget *parent)
    :QSvgWidget(parent)
{
    render = renderer();
}

void SvgWidget::wheelEvent(QWheelEvent * e)
{
    const double diff = 0.1;
    QSize size = render->defaultSize();
    int width = size.width();
    int height = size.height();
    if (e->delta() > 0)
    {
        width = this->width() * (1 + diff);
        height = this->height() * (1+ diff);
    }
    else
    {
        width = this->width() * (1 - diff);
        height = this->height() * (1 - diff);
    }
    resize(width, height);
}



