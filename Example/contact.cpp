#include "contact.h"

Contact::Contact(QWidget *parent) : QWidget(parent)
{
    emailLabel = new QLabel(tr("邮箱： "));
    emailLEdit = new QLineEdit();
    addrLabel = new QLabel(tr("地址： "));
    addrLEdit = new QLineEdit();
    codeLabel = new QLabel(tr("邮编： "));
    codeLEdit = new QLineEdit();
    mobileLabel = new QLabel(tr("移动电话： "));
    mobileLEdit = new QLineEdit();
    mobileCheckBox = new QCheckBox(tr("接收留言"));

    workPhoneLabel = new QLabel(tr("办公电话： "));
    workPhoneLEdit = new QLineEdit();

    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(5);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(emailLabel, 0, 0);
    mainLayout->addWidget(emailLEdit, 0, 1);
    mainLayout->addWidget(addrLabel, 1, 0);
    mainLayout->addWidget(addrLEdit, 1, 1);
    mainLayout->addWidget(codeLabel, 2, 0);
    mainLayout->addWidget(codeLEdit, 2, 1);
    mainLayout->addWidget(mobileLabel, 3, 0);
    mainLayout->addWidget(mobileLEdit, 3, 1);
    mainLayout->addWidget(mobileCheckBox, 3, 2);
    mainLayout->addWidget(workPhoneLabel, 4, 0);
    mainLayout->addWidget(workPhoneLEdit, 4, 1);

    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

}
