#include "mainwindow.h"
#include <QApplication>
#include <QFont>
#include <QSplitter>
#include <QTextEdit>
//#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("ZYSong18030",12);
    a.setFont(font);
    QSplitter * mainSplitter = new QSplitter(Qt::Horizontal, 0);
    QTextEdit* textLeft = new QTextEdit(QObject::tr("Left Widget"), mainSplitter);
    textLeft->setAlignment(Qt::AlignCenter);

    QSplitter * rightSplitter = new QSplitter(Qt::Vertical, mainSplitter);
//    rightSplitter->setOpaqueResize(false);
    QTextEdit* textUp = new QTextEdit(QObject::tr("top Widget"), rightSplitter);
    textUp->setAlignment(Qt::AlignCenter);

//    QTextEdit* textDown = new QTextEdit(QObject::tr("down Widget"), rightSplitter);
//    textDown->setAlignment(Qt::AlignCenter);

//    QTextEdit* textRight2 = new QTextEdit(QObject::tr("center Widget"), mainSplitter);
//    textRight2->setAlignment(Qt::AlignCenter);
//    MainWindow w;
//    w.show();
    mainSplitter->setStretchFactor(1,1);

    mainSplitter->show();
    return a.exec();
}
