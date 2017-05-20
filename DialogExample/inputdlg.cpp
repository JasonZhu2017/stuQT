#include "inputdlg.h"
#include <QString>
#include <QInputDialog>

InputDlg::InputDlg(QWidget* parent) : QDialog(parent)
{
    nameLabel1 = new QLabel(tr("姓名： "));
    nameLabel2 = new QLabel(tr("张三"));
    nameLabel2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    sexLabel1 = new QLabel(tr("性别： "));
    sexLabel2 = new QLabel(tr("男"));
    sexLabel2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    ageLabel1 = new QLabel(tr("年龄： "));
    ageLabel2 = new QLabel(tr("25"));
    ageLabel2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    scoreLabel1 = new QLabel(tr("成绩： "));
    scoreLabel2 = new QLabel(tr("88"));
    scoreLabel2->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    nameBtn = new QPushButton(tr("修改姓名"));
    sexBtn = new QPushButton(tr("修改性别"));
    ageBtn = new QPushButton(tr("修改年龄"));
    scoreBtn = new QPushButton(tr("修改成绩"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(nameLabel1, 0, 0);
    mainLayout->addWidget(nameLabel2, 0, 1);
    mainLayout->addWidget(nameBtn, 0, 2);
    mainLayout->addWidget(sexLabel1, 1, 0);
    mainLayout->addWidget(sexLabel2, 1, 1);
    mainLayout->addWidget(sexBtn, 1, 2);
    mainLayout->addWidget(ageLabel1, 2, 0);
    mainLayout->addWidget(ageLabel2, 2, 1);
    mainLayout->addWidget(ageBtn, 2, 2);
    mainLayout->addWidget(scoreLabel1, 3, 0);
    mainLayout->addWidget(scoreLabel2, 3, 1);
    mainLayout->addWidget(scoreBtn, 3, 2);

    connect(nameBtn, &QPushButton::clicked, this, &InputDlg::changeName);
    connect(sexBtn, &QPushButton::clicked, this, &InputDlg::changeSex);
    connect(ageBtn, &QPushButton::clicked, this, &InputDlg::changeAge);
    connect(scoreBtn, &QPushButton::clicked, this, &InputDlg::changeScore);

}

InputDlg::~InputDlg()
{

}

void InputDlg::changeName()
{
    bool ok;
    QString str = QInputDialog::getText(this,
                                        tr("标准字符串输入"),
                                        tr("姓名： "),
                                        QLineEdit::Normal,
                                        nameLabel2->text(),
                                        &ok);
    if (ok & !str.isEmpty())
    {
        nameLabel2->setText(str);
    }
}

void InputDlg::changeSex()
{
    bool ok;
    QStringList items;
    items << tr("男") << tr("女");
    QString item = QInputDialog::getItem(this,
                                         tr("标准条目选择"),
                                         tr("性别： "),
                                         items,
                                         0,
                                         false,
                                         &ok);
    if (ok & !item.isEmpty())
    {
        sexLabel2->setText(item);
    }
}

void InputDlg::changeAge()
{
    bool ok;
    int age = QInputDialog::getInt(this,
                                   tr("标准整数选择"),
                                   tr("年龄： "),
                                   ageLabel2->text().toInt(&ok),
                                   0,
                                   200,
                                   1,
                                   &ok);
    if (ok)
        ageLabel2->setText(QString(tr("%1")).arg(age));

}

void InputDlg::changeScore()
{
    bool ok;
    double score = QInputDialog::getDouble(this,
                                          tr("标准浮点数类型"),
                                          tr("分数： "),
                                          scoreLabel2->text().toDouble(&ok),
                                          0,
                                          100,
                                          2.0,
                                          &ok);
    if (ok)
        scoreLabel2->setText(QString(tr("%1")).arg(score));
}
