#include "mapwidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>
#include <QGridLayout>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <math.h>


MapWidget::MapWidget()
{
    readMap();
    zoom = 50;
    int width = map.width();
    int height = map.height();
    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->setSceneRect(-width/2, -height/2, width, height);
    this->setScene(scene);
    this->setCacheMode(CacheBackground);

    QSlider* slider = new QSlider;
    slider->setOrientation(Qt::Vertical);
    slider->setRange(1,100);
    slider->setTickInterval(10);
    slider->setValue(zoom);
    connect(slider, &QSlider::valueChanged, this, &MapWidget::slotZoom);

    QLabel* zoomInLabel = new QLabel;
    zoomInLabel->setScaledContents(true);
    zoomInLabel->setPixmap(QPixmap("zoomIn.png"));
    QLabel* zoomOutLabel = new QLabel;
    zoomOutLabel->setScaledContents(true);
    zoomOutLabel->setPixmap(QPixmap("zoomOut.png"));

    QLabel* label1 = new QLabel(tr("GrapichsView::"));
    viewCoord = new QLabel;
    QLabel* label2 = new QLabel(tr("GrapichsScene:"));
    sceneCoord = new QLabel;
    QLabel* label3 = new QLabel(tr("map:"));
    mapCoord = new QLabel;

    QGridLayout* gridlayout = new QGridLayout;
    gridlayout->addWidget(label1, 0, 0);
    gridlayout->addWidget(viewCoord, 0, 1);
    gridlayout->addWidget(label2, 1, 0);
    gridlayout->addWidget(sceneCoord, 1, 1);
    gridlayout->addWidget(label3, 2, 0);
    gridlayout->addWidget(mapCoord, 2, 1);
    gridlayout->setSizeConstraint(QLayout::SetFixedSize);

    QFrame* frame = new QFrame;
    frame->setLayout(gridlayout);
    QVBoxLayout* coordlayout = new QVBoxLayout;
    coordlayout->addWidget(frame);
    coordlayout->addStretch();

    QVBoxLayout* zoomLayout = new QVBoxLayout;
    zoomLayout->addWidget(zoomInLabel);
    zoomLayout->addWidget(slider);
    zoomLayout->addWidget(zoomOutLabel);

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->addLayout(zoomLayout);
    mainLayout->addLayout(coordlayout);
    mainLayout->addStretch();
    mainLayout->setMargin(30);
    mainLayout->setSpacing(10);

    this->setWindowTitle(tr("Map Viewer"));
    this->setMinimumSize(600, 400);


}

void MapWidget::readMap()
{
    QString mapName;
    QFile mapfile("map.txt");

    bool ok = mapfile.open(QIODevice::ReadOnly);
    if (ok)
    {
        QTextStream ts(&mapfile);
        if (!ts.atEnd())
        {
            ts >> mapName;
            ts >> x1 >> y1 >> x2 >> y2;

        }
        map.load(mapName);
    }
}

QPointF MapWidget::mapToMap(QPointF p)
{
    QPointF latLon;
    qreal w = sceneRect().width();
    qreal h = sceneRect().height();

    qreal lat = y1 - ((h/2 + p.y()) * abs(y1 - y2)/h);
    qreal lon = x1 + ((w/2 + p.x()) * abs(x1 -x2)/w);

    latLon.setX(lon);
    latLon.setY(lat);
    return latLon;
}

void MapWidget::slotZoom(int value)
{
    qreal s;
    if (value > zoom)
    {
        s = pow(1.01, (value-zoom));
    }
    else
    {
        s = pow(1/1.01, (zoom - value));
    }
    scale(s, s);
    qDebug() << s << sceneRect();
    zoom = value;
}

void MapWidget::drawBackground(QPainter *painter, const QRectF &rect)
{
   painter->drawPixmap(sceneRect().x(), sceneRect().y(), map);

}

void MapWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPoint viewPoint = event->pos();
    viewCoord->setText(QString::number(viewPoint.x()) + " , " + QString::number(viewPoint.y()));

    QPointF scenePoint = mapToScene(viewPoint);
    sceneCoord->setText(QString::number(scenePoint.x()) + " , " + QString::number(scenePoint.y()));

    QPointF mapPoint = mapToMap(scenePoint);
    mapCoord->setText(QString::number(mapPoint.x()) + " , " + QString::number(mapPoint.y()));

}
