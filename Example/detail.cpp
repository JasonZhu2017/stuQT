#include "detail.h"

Detail::Detail(QWidget *parent) : QWidget(parent)
{
    nationalLabel = new QLabel(tr("国家： "));
    nationalComboBox = new QComboBox();
    nationalComboBox->insertItem(0, tr("美国"));
    nationalComboBox->addItem(tr("中国"));
    nationalComboBox->insertItem(1, tr("英国"));
    nationalComboBox->insertItem(3, tr("法国"));

    provinceLabel = new QLabel(tr("省份： "));
    provinceComboBox = new QComboBox();
    provinceComboBox->addItem(tr("北京"));
    provinceComboBox->addItem(tr("上海"));
    provinceComboBox->addItem(tr("广州"));

    cityLabel = new QLabel(tr("城市： "));
    cityLEdit = new QLineEdit();

    introductLabel = new QLabel(tr("个人说明： "));
    introductTEdit = new QTextEdit();

    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(nationalLabel, 0, 0);
    mainLayout->addWidget(nationalComboBox, 0, 1);
    mainLayout->addWidget(provinceLabel, 1, 0);
    mainLayout->addWidget(provinceComboBox, 1, 1);
    mainLayout->addWidget(cityLabel, 2, 0);
    mainLayout->addWidget(cityLEdit, 2, 1);
    mainLayout->addWidget(introductLabel, 3, 0);
    mainLayout->addWidget(introductTEdit, 3, 1);

    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

}
