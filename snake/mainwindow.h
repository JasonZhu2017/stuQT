#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>

//namespace Ui {
//class MainWindow;
//}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
//    explicit MainWindow(QWidget *parent = 0);

    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
//    Ui::MainWindow *ui;
    void initScene();
    void initSceneBackground();
    QGraphicsScene * scene;
    QGraphicsView * view;
//	GameController * gameController;
//private slots:
//    void adjustViewSize();

};

#endif // MAINWINDOW_H
