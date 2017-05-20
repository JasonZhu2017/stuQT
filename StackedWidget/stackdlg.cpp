#include "stackdlg.h"
#include <QHBoxLayout>
StackDlg::StackDlg(QWidget *parent)
    : QDialog(parent)
{
    list = new QListWidget(this);
//    list->addItem(tr("Window1"));
//    list->addItem(tr("Window2"));
//    list->addItem(tr("Window3"));
    list->insertItem(0,tr("Window1"));
    list->insertItem(1,tr("window3"));
    list->insertItem(2,tr("window2"));
    label1 = new QLabel(tr("this is Label 1"));
    label2 = new QLabel(tr("this is Label 2"));
    label3 = new QLabel(tr("this is Label 3"));
    stack = new QStackedWidget(this);
    stack->addWidget(label1);
    stack->addWidget(label2);
    stack->addWidget(label3);
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(5);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(list);
    mainLayout->addWidget(stack,0, Qt::AlignCenter);
    mainLayout->setStretchFactor(list, 1);
    mainLayout->setStretchFactor(stack, 3);
    connect(list, &QListWidget::currentRowChanged, stack, &QStackedWidget::setCurrentIndex);
}

StackDlg::~StackDlg()
{

}
