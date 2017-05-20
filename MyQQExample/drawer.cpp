#include "drawer.h"

#include <QPixmap>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QLabel>

Drawer::Drawer(QWidget* parent, Qt::WindowFlags f):QToolBox(parent, f)
{
    this->setWindowTitle(tr("QQ"));
    toolBtn1_1 = new QToolButton();
    toolBtn1_1->setText(tr("张三"));
    toolBtn1_1->setIcon(QPixmap("11.png"));
    toolBtn1_1->setIconSize(QPixmap("11.png").size());
    toolBtn1_1->setAutoRaise(true);
    toolBtn1_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn1_2 = new QToolButton();
    toolBtn1_2->setText(tr("李四"));
    toolBtn1_2->setAutoRaise(true);
    toolBtn1_2->setIcon(QPixmap("12.png"));
    toolBtn1_2->setIconSize(QPixmap("12.png").size());
    toolBtn1_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn1_3 = new QToolButton();
    toolBtn1_3->setText(tr("王二"));
    toolBtn1_3->setAutoRaise(true);
    toolBtn1_3->setIcon(QPixmap("13.png"));
    toolBtn1_3->setIconSize(QPixmap("13.png").size());
    toolBtn1_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

//    QGroupBox* group1 = new QGroupBox();
//    QLabel* label1 = new QLabel();
    QWidget* widget1 = new QWidget();
    QVBoxLayout* layout1 = new QVBoxLayout(widget1);
    layout1->setMargin(5);
//    layout1->setSpacing(5);
    layout1->setAlignment(Qt::AlignHCenter);
    layout1->addWidget(toolBtn1_1);
    layout1->addWidget(toolBtn1_2);
    layout1->addWidget(toolBtn1_3);
    layout1->addStretch();

    toolBtn2_1 = new QToolButton();
    toolBtn2_1->setText(tr("赵钱"));
    toolBtn2_1->setAutoRaise(true);
    toolBtn2_1->setIcon(QPixmap("21.png"));
    toolBtn2_1->setIconSize(QPixmap("21.png").size());
    toolBtn2_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn2_2 = new QToolButton();
    toolBtn2_2->setText(tr("孙李"));
    toolBtn2_2->setAutoRaise(true);
    toolBtn2_2->setIcon(QPixmap("22.png"));
    toolBtn2_2->setIconSize(QPixmap("22.png").size());
    toolBtn2_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QGroupBox* group2 = new QGroupBox();
    QVBoxLayout* layout2 = new QVBoxLayout(group2);
    layout2->setMargin(5);
//    layout2->setSpacing(5);
    layout2->setAlignment(Qt::AlignHCenter);
    layout2->addWidget(toolBtn2_1);
    layout2->addWidget(toolBtn2_2);
    layout2->addStretch();

    toolBtn3_1 = new QToolButton();
    toolBtn3_1->setText(tr("麻子"));
    toolBtn3_1->setAutoRaise(true);
    toolBtn3_1->setIcon(QPixmap("31.png"));
    toolBtn3_1->setIconSize(QPixmap("31.png").size());
    toolBtn3_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QGroupBox* group3 = new QGroupBox();
    QVBoxLayout* layout3 = new QVBoxLayout(group3);
    layout3->setMargin(5);
//    layout3->setSpacing(5);
    layout3->setAlignment(Qt::AlignHCenter);
    layout3->addWidget(toolBtn3_1);
    layout3->addStretch();

    this->addItem((QWidget*)widget1, tr("我的好友h"));
    this->addItem((QWidget*)group2, tr("陌生人h"));
    this->addItem((QWidget*)group3, tr("黑名单h"));


}
