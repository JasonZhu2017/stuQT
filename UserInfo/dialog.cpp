#include "dialog.h"
#include <QFrame>
#include <QPixmap>
#include <QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("UserInfo"));

    userNameLabel = new QLabel(tr("用户名： "));
    userNameLEdit = new QLineEdit;
    nameLabel = new QLabel(tr("名字： "));
    nameLEdit = new QLineEdit;
    sexLabel = new QLabel(tr("性别： "));
    sexComboBox = new QComboBox;
    sexComboBox->addItem(tr("男"));
    sexComboBox->addItem(tr("女"));
    departmentLabel = new QLabel(tr("部门： "));
    departmentTEdit =  new QTextEdit();
    ageLabel = new QLabel(tr("年龄： "));
    ageLEdit = new QLineEdit();
    otherLabel = new QLabel(tr("其他： "));
    otherLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    leftLayout = new QGridLayout();
    leftLayout->addWidget(userNameLabel, 0, 0);
    leftLayout->addWidget(userNameLEdit, 0, 1);

    leftLayout->addWidget(nameLabel, 1, 0);
    leftLayout->addWidget(nameLEdit, 1, 1);

    leftLayout->addWidget(sexLabel, 2, 0);
    leftLayout->addWidget(sexComboBox, 2, 1);

    leftLayout->addWidget(departmentLabel, 3, 0);
    leftLayout->addWidget(departmentTEdit, 3, 1);

    leftLayout->addWidget(ageLabel, 4, 0);
    leftLayout->addWidget(ageLEdit, 4, 1);

    leftLayout->addWidget(otherLabel, 5, 0, 1, 2);

    leftLayout->setColumnStretch(0, 1);
    leftLayout->setColumnStretch(1, 3);

    headLabel = new QLabel(tr("头像： "));
    headIconLabel = new QLabel();
    QPixmap  icon("baboon.jpg");
    headIconLabel->setPixmap(icon);
    headIconLabel->resize(icon.width(), icon.height());
    updateHeadBtn =  new QPushButton(tr("更新"));

    topRightLayout = new QHBoxLayout();
    topRightLayout->setSpacing(20);
    topRightLayout->addWidget(headLabel);
    topRightLayout->addWidget(headIconLabel);
    topRightLayout->addWidget(updateHeadBtn);

    introductionLabel = new QLabel(tr("个人说明： "));
    introductionTEdit = new QTextEdit();

    rightLayout = new QVBoxLayout();
    rightLayout->setMargin(10);
    rightLayout->addLayout(topRightLayout);
    rightLayout->addWidget(introductionLabel);
    rightLayout->addWidget(introductionTEdit);

    okBtn =  new QPushButton(tr("确定"));
    cancelBtn = new QPushButton(tr("取消"));

    bottomLayout = new QHBoxLayout();
    bottomLayout->addStretch();
    bottomLayout->addWidget(okBtn);
    bottomLayout->addWidget(cancelBtn);

    QGridLayout * mainLayout = new QGridLayout(this);
    mainLayout->addLayout(leftLayout, 0, 0);
    mainLayout->addLayout(rightLayout, 0, 1);
    mainLayout->addLayout(bottomLayout, 1, 0, 1, 2);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    qDebug() << tr("main") << this;
    qDebug() << tr("mianLayout") << mainLayout->parent();
    qDebug() << tr("bottomLayout") << bottomLayout->parent();
    qDebug() << tr("okButton") << okBtn->parent();
    qDebug() << tr("topLeftLayout") << topRightLayout->parent();
    qDebug() << tr("rightLayout") << rightLayout->parent();
    qDebug() << tr("rightLayout") << rightLayout;
    qDebug() << tr("headIconLabel") <<headIconLabel->parent();
    qDebug() << tr("nameLtext") << nameLEdit->parent();

}

Dialog::~Dialog()
{

}
