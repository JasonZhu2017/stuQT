#include "content.h"
#include <QApplication>
#include <QSplitter>
#include <QListWidget>
//#include <QListWidgetItem>
#include <QSizePolicy>

#include <QFont>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("AR PL KaitiM GB", 12);
    a.setFont(font);

    QSplitter* mainSplitter = new QSplitter(Qt::Horizontal, 0);
    mainSplitter->setOpaqueResize(true);
    QListWidget* list = new QListWidget(mainSplitter);
    list->insertItem(0, QObject::tr("基本信息"));
    list->insertItem(1, QObject::tr("联系方式"));
    list->insertItem(2, QObject::tr("详细资料"));

    Content* content = new Content(mainSplitter);

    QObject::connect(list, &QListWidget::currentRowChanged, content->stack, &QStackedWidget::setCurrentIndex);

    mainSplitter->setWindowTitle(QObject::tr("修改用户资料"));
//    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
//    mainSplitter->setSizePolicy(sizePolicy);
//    mainSplitter->setMinimumSize(1000, 500);
//    mainSplitter->setMaximumSize(1000, 500);
//    mainSplitter->setFixedSize(500, 400);
//    mainSplitter->setFixedSize(mainSplitter->size());
    mainSplitter->show();

//    Content w;
//    w.show();

    return a.exec();
}
