//#include "dialog.h"
#include <QApplication>
#include <digitclock.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DigitClock w;
    w.show();

    return a.exec();
}
