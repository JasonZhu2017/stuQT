#ifndef DIGITCLOCK_H
#define DIGITCLOCK_H
#include <QLCDNumber>
#include <QMouseEvent>
class DigitClock : public QLCDNumber
{
public:
    DigitClock(QWidget* parent = 0);
    void mouseMoveEvent(QMouseEvent* e);
    void mousePressEvent(QMouseEvent* e);
private slots:
    void showTime();
private:
    QPoint  dragPoint;
    bool showColon;
};

#endif // DIGITCLOCK_H
