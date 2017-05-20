//#include "mainwindow.h"
#include <QApplication>

#include <QAbstractItemView>
#include <QDirModel>
#include <QTreeView>
#include <QListView>
#include <QTableView>
#include <QSplitter>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    QDirModel model;

    QTreeView tree;
    QListView list;
    QTableView tabel;

    tree.setModel(&model);
    list.setModel(&model);
    tabel.setModel(&model);

    tree.setSelectionMode(QAbstractItemView::MultiSelection);
    list.setSelectionModel(tree.selectionModel());
    tabel.setSelectionModel(tree.selectionModel());

    QObject::connect(&tree, &QTreeView::doubleClicked, &list, &QListView::setRootIndex);
    QObject::connect(&tree, &QTreeView::doubleClicked, &tabel, &QTableView::setRootIndex);

    QSplitter *splitter = new QSplitter;
    splitter->addWidget(&tree);
    splitter->addWidget(&list);
    splitter->addWidget(&tabel);
    splitter->setWindowTitle(QObject::tr("Model/View"));

    splitter->show();
    return a.exec();
}
