#include "dialog.h"
#include <QFileDialog>
#include <QColorDialog>
#include <QColor>
#include <QPalette>
#include <QFontDialog>
#include <QFont>
#include <QDebug>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    count = 1;
    mainLayout = new QGridLayout(this);

    fileBtn = new QPushButton(tr("文件标准对话框"));
    fileLEdit = new QLineEdit();
    mainLayout->addWidget(fileBtn, 0, 0);
    mainLayout->addWidget(fileLEdit, 0, 1);
    connect(fileBtn, &QPushButton::clicked, this, &Dialog::showFile);

    colorBtn = new QPushButton(tr("颜色标准对话框"));
    colorFrame = new QFrame();
    colorFrame->setFrameStyle(QFrame::Box);
    colorFrame->setAutoFillBackground(true);
    mainLayout->addWidget(colorBtn, 1, 0);
    mainLayout->addWidget(colorFrame, 1, 1);
    connect(colorBtn, &QPushButton::clicked, this, &Dialog::showColor);

    fontBtn = new QPushButton(tr("字体标准对话框"));
    fontLEdit = new QLineEdit();
    fontLEdit->setText("Welcome 123");
    mainLayout->addWidget(fontBtn, 2, 0);
    mainLayout->addWidget(fontLEdit, 2, 1);
    connect(fontBtn, &QPushButton::clicked, this, &Dialog::showFont);

    inputBtn = new QPushButton(tr("输入标准对话框"));
    mainLayout->addWidget(inputBtn, 3, 0);
    connect(inputBtn, &QPushButton::clicked, this, &Dialog::showInput);


    msgBoxBtn = new QPushButton(tr("消息标准对话框"));
    mainLayout->addWidget(msgBoxBtn, 3, 1);
    connect(msgBoxBtn, &QPushButton::clicked, this, &Dialog::showMsgBox);

    customBtn = new QPushButton(tr("自定义对话框"));
    customLabel = new QLabel();
    customLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    mainLayout->addWidget(customBtn, 4, 0);
    mainLayout->addWidget(customLabel, 4, 1);
    connect(customBtn, &QPushButton::clicked, this, &Dialog::showCustomDlg);
}

Dialog::~Dialog()
{

}

void Dialog::showFile()
{
    QString str = QFileDialog::getOpenFileName(this, tr("Open File"), "./",
                                               tr("C++ files(*.cpp);;C files(*.c);;Head files(*.h)"));
    fileLEdit->setText(str);
}

void Dialog::showColor()
{
    QColor c = QColorDialog::getColor();
    if (c.isValid())
    {
        colorFrame->setPalette(QPalette(c));
    }
}

void Dialog::showFont()
{
    bool bOK = false;
    QFont f = QFontDialog::getFont(&bOK);
    if (bOK)
    {
        fontLEdit->setFont(f);
    }
}

void Dialog::showInput()
{
    inputDlg = new InputDlg(this);
    inputDlg->show();
}

void Dialog::showMsgBox()
{
    msgBoxDlg = new MsgBoxDlg(this);
    msgBoxDlg->show();
}

void Dialog::showCustomDlg()
{
    customLabel->setText(tr("custom dialog"));
    QMessageBox customBox;
    customBox.setWindowTitle(tr("自定义消息框"));
    QPushButton* yesBtn = customBox.addButton(tr("Yes"), QMessageBox::ActionRole);
    QPushButton* noBtn = customBox.addButton(tr("No"), QMessageBox::ActionRole);
    QPushButton* cancelBtn = customBox.addButton(QMessageBox::Cancel);
    customBox.setText(tr("用户自定义消息框"));
    customBox.setIconPixmap(QPixmap("./Qt.png"));
    customBox.exec();
    if (customBox.clickedButton() == yesBtn)
        customLabel->setText(tr("clicked yes"));
    else if (customBox.clickedButton() == noBtn)
        customLabel->setText(tr("clicked no"));
    else if (customBox.clickedButton() == cancelBtn)
        customLabel->setText(tr("clicked cancel"));
    else
        return;
}
