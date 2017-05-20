#include "svgwindow.h"

SvgWindow::SvgWindow(QWidget *parent)
    :QScrollArea(parent)
{
    svgWidget = new SvgWidget;
    setWidget(svgWidget);
}

void SvgWindow::mouseMoveEvent(QMouseEvent *e)
{
    horizontalScrollBar()->setValue(scrollBarValue.rx() + mousePressPos.rx()
                                    - e->pos().x());
    verticalScrollBar()->setValue(scrollBarValue.ry() + mousePressPos.ry()
                                  - e->pos().y());
    horizontalScrollBar()->update();
    verticalScrollBar()->update();
    e->accept();
}

void SvgWindow::mousePressEvent(QMouseEvent *e)
{
    mousePressPos = e->pos();
    scrollBarValue.rx() = horizontalScrollBar()->value();
    scrollBarValue.ry() = verticalScrollBar()->value();
    e->accept();
}

void SvgWindow::setFile(QString name)
{
    svgWidget->load(name);
    QSvgRenderer * render = svgWidget->renderer();
    svgWidget->resize(render->defaultSize());
}

