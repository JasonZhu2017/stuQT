#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTableView>
#include <QSplitter>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createAction();
    void createMenu();
    void setupModel();
    void setupView();

private:
    QAction* openAct;
    QMenu* fileMenu;

    QStandardItemModel* model;
    QTableView* table;

    QSplitter* splitter;
    void openFile(QString filename);
    
private slots:
    void slotOpen();
    
};

#endif // MAINWINDOW_H
