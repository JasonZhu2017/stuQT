#include "mainwindow.h"
#include <QMenuBar>
#include <QItemSelectionModel>
#include <QItemSelection>
#include <QFileDialog>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createAction();
    createMenu();
    setupModel();
    setupView();

    setWindowTitle(tr("View ex"));
    resize(600, 600);
}

MainWindow::~MainWindow()
{

}

void MainWindow::createAction()
{
    openAct = new QAction(tr("打开"), this);

    connect(openAct, &QAction::triggered, this, &MainWindow::slotOpen);

}

void MainWindow::createMenu()
{
    fileMenu = menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(openAct);
}

void MainWindow::setupModel()
{
    model = new QStandardItemModel(4, 4, this);
    model->setHeaderData(0, Qt::Horizontal, tr("部门"));
    model->setHeaderData(1, Qt::Horizontal, tr("男"));
    model->setHeaderData(2, Qt::Horizontal, tr("女"));
    model->setHeaderData(3, Qt::Horizontal, tr("退休"));

}

void MainWindow::setupView()
{
    table = new QTableView;
    table->setModel(model);

    QItemSelectionModel* selectionModel = new QItemSelectionModel(model);
    table->setSelectionModel(selectionModel);
//    void (QTableView::* selectionChanged_)(const QItemSelection&, const QItemSelection&) = &QTableView::selectionChanged;
//     connect(selectionModel, &QItemSelectionModel::selectionChanged, table, selectionChanged_);
    connect(selectionModel,SIGNAL(selectionChanged(QItemSelection,QItemSelection)),table,SLOT(selectionChanged(QItemSelection,QItemSelection)));

    splitter = new QSplitter;
    splitter->setOrientation(Qt::Vertical);
    splitter->addWidget(table);

    setCentralWidget(splitter);
}

void MainWindow::openFile(QString filename)
{
    if (filename.isEmpty())
        return;
    QFile file(filename);
    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream stream(&file);
        QString line;
        
        model->removeRows(0, model->rowCount(QModelIndex()), QModelIndex());
        int row = 0;
        do 
        {
            line = stream.readLine();
            if (!line.isEmpty())
            {
                model->insertRows(row, 1, QModelIndex());
                QStringList pieces = line.split(",", QString::SkipEmptyParts);
                model->setData(model->index(row, 0, QModelIndex()), pieces[0]);
                model->setData(model->index(row, 1, QModelIndex()), pieces[1]);
                model->setData(model->index(row, 2, QModelIndex()), pieces[2]);
                model->setData(model->index(row, 3, QModelIndex()), pieces[3]);
            }
        }while(!line.isEmpty());
        file.close();
    }
}

void MainWindow::slotOpen()
{
    QString filename;
    filename = QFileDialog::getOpenFileName(this, tr("open file"), "./", tr("text file(*.txt)"));
    if (!filename.isEmpty())
        openFile(filename);
}
