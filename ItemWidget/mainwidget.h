#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "pixitem.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFrame>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

    createCtrlFrame();

private:
    int angle;
    qreal scaleValue;
    qreal shearValue;
    qreal translateValue;

    QGraphicsView* view;
    QFrame* ctrlFrame;
    PixItem * pixitem;

public slots:
    void slotRotate(int value);
    void slotScale(int value);
    void slotShear(int value);
    void slotTranslate(int value);
};

#endif // MAINWIDGET_H
