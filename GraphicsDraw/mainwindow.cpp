#include "mainwindow.h"
#include <QMenuBar>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createAction();
    createMenu();

    scene = new QGraphicsScene;
    scene->setSceneRect(-200, -200, 400, 400);
    initScene();

    QGraphicsView * view = new QGraphicsView;
    view->setScene(scene);
    view->setMinimumSize(400, 400);
    view->show();   //???

    this->setCentralWidget(view);
    this->resize(550, 450);
    this->setWindowTitle(tr("Graphics"));
}

MainWindow::~MainWindow()
{

}

void MainWindow::initScene()
{
    int i;
    for (i=0; i<3; i++)
        slotAddEllipse();
    for (i=0; i<3; i++)
        slotAddPolygon();
    for (i=0; i<3; i++)
        slotAddText();
    for (i=0; i<3; i++)
        slotAddRect();
    for (i=0; i<3; i++)
        slotAddAlpha();
    for (i=0; i<3; i++)
        slotAddFlash();
    for (i=0; i<3; i++)
        slotAddStar();
    qDebug() << "finish createAction";
}

void MainWindow::createMenu()
{
    QMenu* file = menuBar()->addMenu(tr("文件"));
    file->addAction(newAct);
    file->addAction(clearAct);
    file->addSeparator();
    file->addAction(exitAct);

    QMenu* elem = menuBar()->addMenu(tr("元素"));
    elem->addAction(addEllipseAct);
    elem->addAction(addPolygonAct);
    elem->addAction(addTextAct);
    elem->addAction(addRectAct);
    elem->addAction(addAlphaAct);
    elem->addAction(addFlashAct);
    elem->addAction(addStarAct);
}

void MainWindow::createAction()
{
    newAct = new QAction(tr("新建"), this);
    clearAct = new QAction(tr("清除"), this);
    exitAct = new QAction(tr("退出"), this);
    addEllipseAct = new QAction(tr("加入 椭圆"), this);
    addPolygonAct = new QAction(tr("加入 多边形"), this);
    addTextAct = new QAction(tr("加入 文字"), this);
    addRectAct = new QAction(tr("加入 矩形"), this);
    addAlphaAct = new QAction(tr("加入 透明图"), this);
    addFlashAct = new QAction(tr("加入 闪烁图"), this);
    addStarAct = new QAction(tr("加入 星星"), this);

    connect(newAct, &QAction::triggered, this, &MainWindow::slotNew);
    connect(clearAct, &QAction::triggered, this, &MainWindow::slotClear);
    connect(exitAct, &QAction::triggered, this, &MainWindow::close);
    connect(addEllipseAct, &QAction::triggered, this, &MainWindow::slotAddEllipse);
    connect(addPolygonAct, &QAction::triggered, this, &MainWindow::slotAddPolygon);
    connect(addTextAct, &QAction::triggered, this, &MainWindow::slotAddText);
    connect(addRectAct, &QAction::triggered, this, &MainWindow::slotAddRect);
    connect(addAlphaAct, &QAction::triggered, this, &MainWindow::slotAddAlpha);
    connect(addFlashAct, &QAction::triggered, this, &MainWindow::slotAddFlash);
    connect(addStarAct, &QAction::triggered, this, &MainWindow::slotAddStar);
}

void MainWindow::slotNew()
{
    slotClear();
    initScene();
    MainWindow* newWin = new MainWindow;
    newWin->show();
}



void MainWindow::slotClear()
{
    QList<QGraphicsItem*> itemList = scene->items();
    while(!itemList.empty())
    {
        scene->removeItem(itemList.at(0));
        itemList.removeAt(0);
    }
}

void MainWindow::slotAddEllipse()
{
    QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem(QRectF(0,0,80,60));
    ellipse->setPen(Qt::NoPen);
    ellipse->setBrush(QColor(qrand()%256, qrand()%256, qrand()%256));
    ellipse->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(ellipse);
    ellipse->setPos(qrand()%int(scene->sceneRect().width()) - 200,
                    qrand()%int(scene->sceneRect().height()) - 200);
}

void MainWindow::slotAddPolygon()
{
    QVector<QPoint> v;
    v << QPoint(30, -15) << QPoint(0, -30) << QPoint(-30, -15) << QPoint(-30, 15)
      << QPoint(0, 30) << QPoint(30, 15);
    QGraphicsPolygonItem * item = new  QGraphicsPolygonItem(QPolygonF(v));
    item->setBrush(QColor(qrand()%256, qrand()%256, qrand()%256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos(qrand()%int(scene->sceneRect().width()) - 200,
                 qrand()%int(scene->sceneRect().height()) - 200);

}

void MainWindow::slotAddText()
{
    QFont font("Times", 16);
    QGraphicsTextItem* text = new QGraphicsTextItem("Hello, Qt!");
    text->setFont(font);
    text->setFlag(QGraphicsItem::ItemIsMovable);
    text->setDefaultTextColor(QColor(qrand()%256, qrand()%256, qrand()%256));
    scene->addItem(text);
    text->setPos(qrand()%int(scene->sceneRect().width()) - 200,
                 qrand()%int(scene->sceneRect().height()) - 200);


}

void MainWindow::slotAddRect()
{
    QGraphicsRectItem *rectItem = new QGraphicsRectItem(QRectF(0, 0, 60, 40));
    QPen pen;
    pen.setWidth(4);
    pen.setColor(QColor(qrand()%256, qrand()%256, qrand()%256));
    rectItem->setPen(pen);
    rectItem->setBrush(QColor(qrand()%256, qrand()%256, qrand()%256));
    rectItem->setFlag(QGraphicsItem::ItemIsMovable);
    rectItem->setPos(qrand()%int(scene->sceneRect().width()) - 200,
                     qrand()%int(scene->sceneRect().height()) - 200);
    scene->addItem(rectItem);
}

void MainWindow::slotAddAlpha()
{
    QGraphicsPixmapItem* pixmapItem = scene->addPixmap(QPixmap("image.png"));
    pixmapItem->setFlag(QGraphicsItem::ItemIsMovable);
    pixmapItem->setPos(qrand()%int(scene->sceneRect().width()) - 200,
                       qrand()%int(scene->sceneRect().height()) - 200);
}

void MainWindow::slotAddFlash()
{
    FlashItem* flash = new FlashItem;
    scene->addItem(flash);
    flash->setPos(qrand()%int(scene->sceneRect().width()) - 200,
                  qrand()%int(scene->sceneRect().height()) - 200);
}

void MainWindow::slotAddStar()
{
    StarItem* item = new StarItem;
    QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
    animation->setItem(item);
    QTimeLine* timeLine = new QTimeLine(4000);
    timeLine->setCurveShape(QTimeLine::SineCurve);
    timeLine->setLoopCount(0);

    animation->setTimeLine(timeLine);

    int y = qrand()%400 -200;
    for (int i=0; i< 400; i++)
    {
        animation->setPosAt(i/400.0, QPointF(i-200, y));
    }
    timeLine->start();
    scene->addItem(item);
}
