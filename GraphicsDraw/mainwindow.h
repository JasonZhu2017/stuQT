#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QMenu>
#include <QAction>
#include "flashitem.h"
#include "staritem.h"
#include <QTimerEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initScene();
    void createMenu();
    void createAction();

public slots:
    void slotNew();
    void slotClear();

    void slotAddEllipse();
    void slotAddPolygon();
    void slotAddText();
    void slotAddRect();
    void slotAddAlpha();
    void slotAddFlash();
    void slotAddStar();

private:
    QGraphicsScene* scene;
    QAction* newAct;
    QAction* clearAct;
    QAction* exitAct;
    QAction* addEllipseAct;
    QAction* addPolygonAct;
    QAction* addTextAct;
    QAction* addRectAct;
    QAction* addAlphaAct;
    QAction* addFlashAct;
    QAction* addStarAct;
};

#endif // MAINWINDOW_H
