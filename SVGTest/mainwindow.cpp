#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("SVG Test"));
    svgWindow = new SvgWindow;
    this->setCentralWidget(svgWindow);
    createMenu();
}

MainWindow::~MainWindow()
{

}

void MainWindow::createMenu()
{
    QMenu* menu = this->menuBar()->addMenu(tr("File"));
    QAction* fileAct = new QAction(tr("open"), this);
    connect(fileAct, &QAction::triggered, this, &MainWindow::openFile);
    menu->addAction(fileAct);
}

void MainWindow::openFile()
{
    QString name = QFileDialog::getOpenFileName(this, tr("open file"), "./", "svg file(*.svg)");
    svgWindow->setFile(name);
}
