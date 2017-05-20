#include "content.h"
#include <QHBoxLayout>
#include <QDebug>


Content::Content(QWidget *parent)
    : QFrame(parent)
{
    stack =  new QStackedWidget(this);
    stack->setFrameStyle(QFrame::Panel | QFrame::Raised);
    baseInfo = new BaseInfo();
    contact = new Contact();
    detail = new Detail();

    stack->addWidget(baseInfo);
    stack->addWidget(contact);
    stack->addWidget(detail);

    qDebug() << "headIconLabel parent stack" << baseInfo->headIconLabel->parent();
    qDebug() << "stack" << stack;

    amendBtn = new QPushButton(tr("修改"));
    closeBtn = new QPushButton(tr("关闭"));

    QHBoxLayout* bottomLayout = new QHBoxLayout;
//    qDebug() << "bottomLayout father" << bottomLayout->parent();
    bottomLayout->addStretch(1);
    bottomLayout->addWidget(amendBtn);
    bottomLayout->addWidget(closeBtn);

    QVBoxLayout* rightLayout = new QVBoxLayout(this);
    rightLayout->setMargin(1);
    rightLayout->setSpacing(6);
    rightLayout->addWidget(stack);
    qDebug() << "headIconLabel parent layout" << baseInfo->headIconLabel->parent();
    qDebug() << "content" << this;
    rightLayout->addLayout(bottomLayout);
//    qDebug() << "bottomLayout father" << bottomLayout->parent();
//    qDebug() << "rightLayout" << rightLayout;
//    qDebug() << "rightLayout father" << rightLayout->parent();
//    qDebug() << "content" << this;

}

Content::~Content()
{

}
