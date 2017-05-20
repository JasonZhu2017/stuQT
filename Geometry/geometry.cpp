#include "geometry.h"
#include <QDebug>

Geometry::Geometry(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Geometry"));
    xLabel =new QLabel(tr("x():"));
    xValue =new QLabel;
    yLabel =new QLabel(tr("y():"));
    yValue =new QLabel;
    frmLabel =new QLabel(tr("Frame:"));
    frmValue =new QLabel;
    posLabel =new QLabel(tr("pos():"));
    posValue =new QLabel;
    geoLabel =new QLabel(tr("geometry():"));
    geoValue =new QLabel;
    widthLabel =new QLabel(tr("width():"));
    widthValue =new QLabel;
    heightLabel =new QLabel(tr("height():"));
    heightValue =new QLabel;
    rectLabel =new QLabel(tr("rect():"));
    rectValue =new QLabel;
    sizeLabel =new QLabel(tr("size():"));
    sizeValue =new QLabel;

    layout =new QGridLayout(this);
    layout->addWidget(xLabel,0,0);
    layout->addWidget(xValue,0,1);
    layout->addWidget(yLabel,1,0);
    layout->addWidget(yValue,1,1);
    layout->addWidget(posLabel,2,0);
    layout->addWidget(posValue,2,1);
    layout->addWidget(frmLabel,3,0);
    layout->addWidget(frmValue,3,1);
    layout->addWidget(geoLabel,4,0);
    layout->addWidget(geoValue,4,1);
    layout->addWidget(widthLabel,5,0);
    layout->addWidget(widthValue,5,1);
    layout->addWidget(heightLabel,6,0);
    layout->addWidget(heightValue,6,1);
    layout->addWidget(rectLabel,7,0);
    layout->addWidget(rectValue,7,1);
    layout->addWidget(sizeLabel,8,0);
    layout->addWidget(sizeValue,8,1);

    updateLabel();
}

Geometry::~Geometry()
{

}

void Geometry::updateLabel()
{
    QString xStr;                      	//获得x()函数的结果并显示
    xValue->setText(xStr.setNum(x()));

    QString yStr;                      	//获得y()函数的结果并显示
    yValue->setText(yStr.setNum(y()));

    QString frameStr;                 	//获得frameGeometry()函数的结果并显示
    QString tempStr1,tempStr2,tempStr3,tempStr4;
    qDebug() << this->parent();
    frameStr = tempStr1.setNum(frameGeometry().x())+","+tempStr2.setNum(frameGeometry().y())+","+tempStr3.setNum(frameGeometry().width())+","+tempStr4.setNum(frameGeometry().height());
    frmValue->setText(frameStr);

    QString positionStr;            	//获得pos()函数的结果并显示
    QString tempStr11,tempStr12;
    positionStr =tempStr11.setNum(pos().x())+","+tempStr12.setNum(pos().y());
    posValue->setText(positionStr);

    QString geoStr;               		//获得geometry()函数的结果并显示
    QString tempStr21,tempStr22,tempStr23,tempStr24;
//    geoStr =tempStr21.setNum(geometry().x())+","+tempStr22.setNum(geometry().y())+","+tempStr23.setNum(geometry().width())+","+tempStr24.setNum(geometry().height());
    geoStr =tempStr21.setNum(geoLabel->geometry().x())+","+tempStr22.setNum(geoLabel->geometry().y())+","+tempStr23.setNum(geoLabel->geometry().width())+","+tempStr24.setNum(geoLabel->geometry().height());
    geoValue->setText(geoStr);

    QString wStr,hStr;                  //获得width()、height()函数的结果并显示
    widthValue->setText(wStr.setNum(width()));
    heightValue->setText(hStr.setNum(height()));

    QString rectStr;                    //获得rect()函数的结果并显示
    QString tempStr31,tempStr32,tempStr33,tempStr34;
    rectStr =tempStr31.setNum(rect().x())+","+tempStr32.setNum(rect().y())+","+tempStr33.setNum(/*rect().width()*/width())+","+tempStr34.setNum(height()/*rect().height()*/);
    rectValue->setText(rectStr);

    QString sizeStr;                 	//获得size()函数的结果并显示
    QString tempStr41,tempStr42;
    sizeStr =tempStr41.setNum(size().width())+","+tempStr42.setNum(size().height());
    sizeValue->setText(sizeStr);
}

void Geometry::moveEvent(QMouseEvent *e)
{
    updateLabel();
}

void Geometry::resizeEvent(QResizeEvent *e)
{
    updateLabel();
}
