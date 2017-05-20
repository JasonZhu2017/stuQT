#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QToolButton>
#include <QToolBar>
#include "drawwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createToolBar();

public slots:
    void onStyle();
    void onColor();

private:
    DrawWidget* drawWidget;
    QLabel* styleLabel;
    QComboBox* styleCBox;
    QLabel* widthLabel;
    QSpinBox* widthSpinBox;
    QToolButton* colorBtn;
    QToolButton* cleanBtn;

};

#endif // MAINWINDOW_H
