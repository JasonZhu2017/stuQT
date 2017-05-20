#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <paintarea.h>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QFrame>
#include <QPushButton>
#include <QGradient>
#include <QGridLayout>
#include <QColor>
#include <QColorDialog>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
private:
    PaintArea* paintArea;
    QLabel* shapeLabel;
    QComboBox* shapeComboBox;
    QLabel* penWidthLabel;
    QSpinBox* penWidthSpinBox;
    QLabel* penColorLabel;
    QFrame* penColorFrame;
    QPushButton* penColorBtn;
    QLabel* penStyleLabel;
    QComboBox* penStyleComboBox;
    QLabel* penCapLabel;
    QComboBox* penCapComboBox;
    QLabel* penJoinLabel;
    QComboBox* penJoinComboBox;
    QLabel* fillRuleLabel;
    QComboBox* fillRuleComboBox;
    QLabel* spreadLabel;
    QComboBox* spreadComboBox;
    QGradient::Spread spread;
    QLabel* brushStyleLabel;
    QComboBox* brushStyleComboBox;
    QLabel* brushColorLabel;
    QFrame* brushColorFrame;
    QPushButton* brushColorBtn;
    QGridLayout* rightLayout;

private slots:
//protected slots:
    void ShowShape(int value);
    void ShowPenWidth(int value);
    void ShowPenColor();
    void ShowPenStyle(int styleValue);
    void ShowPenCap(int capValue);
    void ShowPenJoin(int joinValue);
    void ShowSpreadStyle();
    void ShowFillRule();
    void ShowBrushColor();
    void ShowBrush(int value);
};

#endif // MAINWIDGET_H
