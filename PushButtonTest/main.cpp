#include "mywidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myWidget w;
    w.setGeometry(100,100,600,120);
//    w.resize(100,20);
    w.move(0,0);
    w.show();

    return a.exec();
}
