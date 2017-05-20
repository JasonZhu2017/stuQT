#include "dockwindows.h"
#include <QDockWidget>
#include <QTextEdit>
#include <QLabel>

DockWindows::DockWindows(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle(tr("Dock Windows"));
    QTextEdit* ed = new QTextEdit(this);
    ed->setText(tr("Main Window"));
    ed->setAlignment(Qt::AlignCenter);
    this->setCentralWidget(ed);
    QDockWidget * dock = new QDockWidget(tr("dockwidget1"), this);
    dock->setFeatures(QDockWidget::DockWidgetMovable);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    QTextEdit * ed1 = new QTextEdit;
    ed1->setText(tr("windows1, the dockwidget can be moved by user"));
    dock->setWidget(ed1);
    this->addDockWidget(Qt::RightDockWidgetArea, dock);

    dock = new QDockWidget(tr("dockWidget2"), this);
    dock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetClosable);
//    dock->setAllowedAreas();
    QLabel * label = new QLabel;
    label->setText(tr("Window2, the dockwidget"));
    dock->setWidget(label);
    this->addDockWidget(Qt::RightDockWidgetArea, dock);

    dock = new QDockWidget(tr("dockwidget3"), this);
    dock->setFeatures(QDockWidget::AllDockWidgetFeatures);
    QTextEdit * ed3 = new QTextEdit(tr("window3 textEdit"),this);
    dock->setWidget(ed3);
    this->addDockWidget(Qt::BottomDockWidgetArea, dock);



}

DockWindows::~DockWindows()
{

}
