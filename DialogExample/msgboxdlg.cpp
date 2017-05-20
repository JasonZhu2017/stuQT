#include "msgboxdlg.h"
#include <QMessageBox>

MsgBoxDlg::MsgBoxDlg(QWidget *parent)
    :QDialog(parent)
{
    this->setWindowTitle(tr("标准消息对话框"));
    label = new QLabel(tr("请选择需要的模式"));

    questionBtn = new QPushButton(tr("question"));
    infoBtn = new QPushButton(tr("information"));
    warningBtn = new QPushButton(tr("warning"));
    criticalBtn = new QPushButton(tr("critical"));
    aboutBtn = new QPushButton(tr("about"));
    aboutQtBtn = new QPushButton(tr("aboutQt"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(label, 0, 0, 1, 2);
    mainLayout->addWidget(questionBtn, 1, 0);
    mainLayout->addWidget(infoBtn, 1, 1);
    mainLayout->addWidget(warningBtn, 2, 0);
    mainLayout->addWidget(criticalBtn, 2, 1);
    mainLayout->addWidget(aboutBtn, 3, 0);
    mainLayout->addWidget(aboutQtBtn, 3, 1);

    connect(questionBtn, &QPushButton::clicked, this, &MsgBoxDlg::showQuestion);
    connect(infoBtn, &QPushButton::clicked, this, &MsgBoxDlg::showInfomation);
    connect(warningBtn, &QPushButton::clicked, this, &MsgBoxDlg::showWarning);
    connect(criticalBtn, &QPushButton::clicked, this, &MsgBoxDlg::showCritical);
    connect(aboutBtn, &QPushButton::clicked, this,&MsgBoxDlg::showAbout);
    connect(aboutQtBtn, &QPushButton::clicked, this, &MsgBoxDlg::showAboutQt);

}

MsgBoxDlg::~MsgBoxDlg()
{

}

void MsgBoxDlg::showQuestion()
{
    label->setText(tr("Question messageBox"));
    switch (QMessageBox::question(this, tr("question"),
                                  tr("是否保存修改？"),
                                  QMessageBox::Ok | QMessageBox::Cancel,
                                  QMessageBox::Ok))
    {
    case QMessageBox::Ok:
        label->setText(tr("selected ok"));
        break;
    case QMessageBox::Cancel:
        label->setText(tr("selected cancel"));
        break;
    default:
        break;
    }
    return;
}

void MsgBoxDlg::showInfomation()
{
    label->setText("information messageBox");
    QMessageBox::information(this,
                             tr("information"),
                             tr("this a note"));
    return;
}

void MsgBoxDlg::showWarning()
{
    QMessageBox::warning(this, tr("warning"), tr("warning box"));
}

void MsgBoxDlg::showCritical()
{
    QMessageBox::critical(this,
                          tr("critical"),
                          tr("critical box"));
}

void MsgBoxDlg::showAbout()
{
    QMessageBox::about(this,
                       tr("about"),
                       tr("about box"));
}

void MsgBoxDlg::showAboutQt()
{
    QMessageBox::aboutQt(this,
                         tr("about qt box"));
}
