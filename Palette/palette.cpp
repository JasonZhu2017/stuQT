#include "palette.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPalette>
#include <QDebug>

Palette::Palette(QWidget *parent)
    : QDialog(parent)
{
    createCtrlFrame();
    createContentFrame();
    QHBoxLayout * mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(ctrlFrame);
    mainLayout->addWidget(contentFrame);
}

Palette::~Palette()
{

}

void Palette::createCtrlFrame()
{
    ctrlFrame = new QFrame;
    windowLabel =  new QLabel(tr("QPalette::Window: "));
    windowComboBox = new QComboBox;
    fillColorList(windowComboBox);
    void (QComboBox:: * cbBoxSignal)(int) = &QComboBox::activated;
    connect(windowComboBox, cbBoxSignal, this, &Palette::showWindow);

    windowTextLabel = new QLabel(tr("QPalette::WindowText: "));
    windowTextComboBox = new QComboBox;
    fillColorList(windowTextComboBox);
    connect(windowTextComboBox, cbBoxSignal, this, &Palette::showWindowText);

    buttonLabel = new QLabel(tr("QPalette::Button: "));
    buttonComboBox = new QComboBox;
    fillColorList(buttonComboBox);
    connect(buttonComboBox, cbBoxSignal, this, &Palette::showButton);

    buttonTextLabel = new QLabel(tr("QPalette::ButtonText: "));
    buttonTextComboBox = new QComboBox;
    fillColorList(buttonTextComboBox);
    connect(buttonTextComboBox, cbBoxSignal, this, &Palette::showButtonText);

    baseLabel = new QLabel(tr("QPalette::Base: "));
    baseComboBox = new QComboBox;
    fillColorList(baseComboBox);
    connect(baseComboBox, cbBoxSignal, this, &Palette::showBase);

    QGridLayout *mainLayout=new QGridLayout(ctrlFrame);
    mainLayout->setSpacing(20);
    mainLayout->addWidget(windowLabel,0,0);
    mainLayout->addWidget(windowComboBox,0,1);
    mainLayout->addWidget(windowTextLabel,1,0);
    mainLayout->addWidget(windowTextComboBox,1,1);
    mainLayout->addWidget(buttonLabel,2,0);
    mainLayout->addWidget(buttonComboBox,2,1);
    mainLayout->addWidget(buttonTextLabel,3,0);
    mainLayout->addWidget(buttonTextComboBox,3,1);
    mainLayout->addWidget(baseLabel,4,0);
    mainLayout->addWidget(baseComboBox,4,1);
}

void Palette::createContentFrame()
{
    contentFrame =new QFrame;                                //具体显示面板

    label1 =new QLabel(tr("请选择一个值："));
    comboBox1 =new QComboBox;
    comboBox1->addItem(tr("item1"));
    comboBox1->addItem(tr("items2"));
    comboBox1->addItem(tr("items3"));

    label2 =new QLabel(tr("请输入字符串："));
    label2->setAutoFillBackground(true);
    lineEdit2 =new QLineEdit;
    lineEdit2->setAutoFillBackground(true);

    textEdit =new QTextEdit;

    QGridLayout *TopLayout =new QGridLayout;
    TopLayout->addWidget(label1,0,0);
    TopLayout->addWidget(comboBox1,0,1);
    TopLayout->addWidget(label2,1,0);
    TopLayout->addWidget(lineEdit2,1,1);
    TopLayout->addWidget(textEdit,2,0,1,2);

    okBtn =new QPushButton(tr("确认"));
    cancelBtn =new QPushButton(tr("取消"));
    okBtn->setAutoFillBackground(true);
    cancelBtn->setAutoFillBackground(true);

    QHBoxLayout *BottomLayout =new QHBoxLayout;
    BottomLayout->addStretch(1);
    BottomLayout->addWidget(okBtn);
    BottomLayout->addWidget(cancelBtn);

    QVBoxLayout *mainLayout =new QVBoxLayout(contentFrame);
    mainLayout->addLayout(TopLayout);
    mainLayout->addLayout(BottomLayout);
    contentFrame->setAutoFillBackground(true);
}

void Palette::fillColorList(QComboBox * comboBox)
{
    QStringList colorList = QColor::colorNames();
    QString color;
    foreach (color, colorList) {
       QPixmap pix(QSize(70, 20));
       pix.fill(QColor(color));
       comboBox->addItem(QIcon(pix), NULL);
       comboBox->setIconSize(QSize(70, 20));
       comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    }
}

void Palette::showWindow()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[windowComboBox->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::Window, color);
    contentFrame->setPalette(p);
    qDebug() << "showWindow";
//    contentFrame->update();
}

void Palette::showWindowText()
{
    QStringList colorList = QColor::colorNames();
    QColor color(colorList[windowTextComboBox->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::WindowText, color);
    contentFrame->setPalette(p);
}

void Palette::showButton()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[buttonComboBox->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::Button, color);
    contentFrame->setPalette(p);
//    contentFrame->update();
}

void Palette::showButtonText()
{
    QStringList colorList = QColor::colorNames();
    QColor color(colorList[buttonTextComboBox->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::ButtonText, color);
    contentFrame->setPalette(p);
}

void Palette::showBase()
{
    QStringList colorList = QColor::colorNames();
    QColor color(colorList[baseComboBox->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::Base, color);
    contentFrame->setPalette(p);
}
