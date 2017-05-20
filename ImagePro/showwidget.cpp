#include "showwidget.h"
#include <QHBoxLayout>

ShowWidget::ShowWidget(QWidget *parent) : QWidget(parent)
{
    imgLabel = new QLabel;
//    imgLabel->setScaledContents(true);

    textEdit =  new QTextEdit();
    QHBoxLayout* layout = new QHBoxLayout(this);

    layout->addWidget(imgLabel);
    layout->addWidget(textEdit);
}
