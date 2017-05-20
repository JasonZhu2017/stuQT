#include "mainwidget.h"
#include <QSlider>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QVBoxLayout>
#include "math.h"
#include <QDebug>
#include <QGraphicsRectItem>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    angle = 0;
    scaleValue = 5;
    shearValue = 5;
    translateValue = 50;

    QGraphicsScene* scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, 20, 20);

    QPixmap *pixmap = new QPixmap("image.png");
    pixitem = new PixItem(pixmap);
    scene->addItem(pixitem);
    pixitem->setPos(0, 0);

    QGraphicsRectItem *rect = new QGraphicsRectItem(QRectF(0, 0, 40, 40));
    scene->addItem(rect);
//    rect->setPos(20,20);
    view = new QGraphicsView;
    view->setScene(scene);
    view->setMinimumSize(400, 400);
//    view->setsi

    ctrlFrame = new QFrame();
    createCtrlFrame();

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(10);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(view);
    mainLayout->addWidget(ctrlFrame);

    setWindowTitle(tr("Item Widget"));
}

MainWidget::~MainWidget()
{

}

MainWidget::createCtrlFrame()
{
    QSlider* rotateSlider = new QSlider;
    rotateSlider->setOrientation(Qt::Horizontal);
    rotateSlider->setRange(0, 360);

    QHBoxLayout *rotateLayout = new QHBoxLayout;
    rotateLayout->addWidget(rotateSlider);

    QGroupBox * rotateBox = new QGroupBox(tr("rotate item"));
    rotateBox->setLayout(rotateLayout);

    QSlider* scaleSlider = new QSlider;
    scaleSlider->setOrientation(Qt::Horizontal);
    scaleSlider->setRange(0, 2*scaleValue);
    scaleSlider->setValue(scaleValue);
    QHBoxLayout *scaleLayout = new QHBoxLayout;
    scaleLayout->addWidget(scaleSlider);
    QGroupBox * scaleBox = new QGroupBox(tr("scale item"));
    scaleBox->setLayout(scaleLayout);

    QSlider* shearSlider = new QSlider;
    shearSlider->setOrientation(Qt::Horizontal);
    shearSlider->setRange(0, 2*shearValue);
    shearSlider->setValue(shearValue);
    QHBoxLayout* shearLayout = new QHBoxLayout;
    shearLayout->addWidget(shearSlider);
    QGroupBox* shearBox = new QGroupBox(tr("shear item"));
    shearBox->setLayout(shearLayout);

    QSlider* translateSlider = new QSlider;
    translateSlider->setOrientation(Qt::Horizontal);
    translateSlider->setRange(0, 2*translateValue);
    translateSlider->setValue(translateValue);
    QHBoxLayout* translateLayout = new QHBoxLayout;
    translateLayout->addWidget(translateSlider);
    QGroupBox * translateBox = new QGroupBox(tr("translate item"));
    translateBox->setLayout(translateLayout);

    connect(rotateSlider, &QSlider::valueChanged, this, &MainWidget::slotRotate);
    connect(scaleSlider, &QSlider::valueChanged, this, &MainWidget::slotScale);
    connect(shearSlider, &QSlider::valueChanged, this, &MainWidget::slotShear);
    connect(translateSlider, &QSlider::valueChanged, this, &MainWidget::slotTranslate);

    QVBoxLayout* frameLayout = new QVBoxLayout;
    frameLayout->setMargin(10);
    frameLayout->setSpacing(10);
    frameLayout->addWidget(rotateBox);
    frameLayout->addWidget(scaleBox);
    frameLayout->addWidget(shearBox);
    frameLayout->addWidget(translateBox);

    ctrlFrame->setLayout(frameLayout);

}

void MainWidget::slotRotate(int value)
{
    view->rotate(value-angle);
    angle = value;
}

void MainWidget::slotScale(int value)
{
    qreal s;
    if (value > scaleValue)
    {
        s = pow(1.2, (value - scaleValue));
    }
    else
    {
        s = pow(1/1.2, (scaleValue - value));
    }
    view->scale(s, s);
    scaleValue = value;
    qDebug() << view->size();
}

void MainWidget::slotShear(int value)
{
    view->shear((value-shearValue)/5, 0);
    shearValue = value;
}

void MainWidget::slotTranslate(int value)
{
    view->translate(value, value);
//    qDebug() << value << translateValue;
//    view->translate(value-translateValue, value-translateValue);
    translateValue = value;
}
