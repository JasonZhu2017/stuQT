#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QDialog>
#include <QLabel>
#include <QGridLayout>
#include <QMouseEvent>
#include <QResizeEvent>

class Geometry : public QDialog
{
    Q_OBJECT

public:
    Geometry(QWidget *parent = 0);
    ~Geometry();

    void updateLabel();
private:
    QLabel* xLabel;
    QLabel* xValue;
    QLabel* yLabel;
    QLabel* yValue;
    QLabel* frmLabel;
    QLabel* frmValue;
    QLabel* posLabel;
    QLabel* posValue;
    QLabel* geoLabel;
    QLabel* geoValue;
    QLabel* widthLabel;
    QLabel* widthValue;
    QLabel* heightLabel;
    QLabel* heightValue;
    QLabel* rectLabel;
    QLabel* rectValue;
    QLabel* sizeLabel;
    QLabel* sizeValue;
    QGridLayout * layout;

protected:
    void moveEvent(QMouseEvent* e);
    void resizeEvent(QResizeEvent *e);

};

#endif // GEOMETRY_H
