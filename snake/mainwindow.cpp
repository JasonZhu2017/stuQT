#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    scene(new QGraphicsScene(this)),
    view(new QGraphicsItem(this))
{
    setCentralWidget(view);
    resize(600,600);
    initScene();
    initSceneBackground();
    QTimer::singleShot(0, this, SLOT(adjustViewSize()))
}

MainWindow::~MainWindow()
{
}
