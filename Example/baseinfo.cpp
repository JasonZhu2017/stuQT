#include "baseinfo.h"
#include <QHBoxLayout>
#include <QDebug>
BaseInfo::BaseInfo(QWidget *parent) : QWidget(parent)
{
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

//    leftLayout->setColumnStretch(0, 1);
//    leftLayout->setColumnStretch(1, 0.5);

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

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    mainLayout->setStretchFactor(leftLayout, 1);
    mainLayout->setStretchFactor(rightLayout, 1);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    qDebug() << "headIconLabel parent" << headIconLabel->parent();
    qDebug() << "baseinfo" << this;
}
