#include "mainwindow.h"
#include <QColorDialog>
#include <drawwidget.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    drawWidget = new DrawWidget;
    this->setCentralWidget(drawWidget);
    createToolBar();
    drawWidget->setColor(Qt::black);
//    drawWidget->setStyle(styleCBox->currentIndex());
    onStyle();
    drawWidget->setWidth(widthSpinBox->value());
}

MainWindow::~MainWindow()
{

}

void MainWindow::createToolBar()
{
    QToolBar * toolBar = addToolBar(tr("Tool"));
    styleLabel = new QLabel(tr(" 线条风格： "));
    styleCBox = new QComboBox;
    styleCBox->addItem(tr("SolidLine"), static_cast<int>(Qt::SolidLine));
    styleCBox->addItem(tr("Dashline"), static_cast<int>(Qt::DashLine));
    styleCBox->addItem(tr("DotLine"),static_cast<int>(Qt::DotLine));
    styleCBox->addItem(tr("DashDotLine"),static_cast<int>(Qt::DashDotLine));
    styleCBox->addItem(tr("DashDotDotLine"),static_cast<int>(Qt::DashDotDotLine));
    void (QComboBox:: * activated_int)(int) = &QComboBox::activated;
    connect(styleCBox, activated_int, this, &MainWindow::onStyle);

    widthLabel = new QLabel(tr(" 线宽： "));
    widthSpinBox = new QSpinBox;
    void (QSpinBox::* valueChanged_int)(int) = &QSpinBox::valueChanged;
    connect(widthSpinBox, valueChanged_int, drawWidget, &DrawWidget::setWidth);

    colorBtn = new QToolButton;
    QPixmap pixmap(20,20);
    pixmap.fill(Qt::black);
    colorBtn->setIcon(QIcon(pixmap));
    connect(colorBtn, &QToolButton::clicked, this, &MainWindow::onColor);

    cleanBtn = new QToolButton;
    cleanBtn->setText(tr("清除"));
    connect(cleanBtn, &QToolButton::clicked, drawWidget, &DrawWidget::clear);

    toolBar->addWidget(styleLabel);
    toolBar->addWidget(styleCBox);
    toolBar->addWidget(widthLabel);
    toolBar->addWidget(widthSpinBox);
    toolBar->addWidget(colorBtn);
    toolBar->addWidget(cleanBtn);


}

void MainWindow::onStyle()
{
    drawWidget->setStyle(styleCBox->itemData(styleCBox->currentIndex(), Qt::UserRole).toInt());
}

void MainWindow::onColor()
{
    QColor color = QColorDialog::getColor(static_cast<int>(Qt::black), this);
    if (color.isValid())
    {
        qDebug() << color;
        drawWidget->setColor(color);
        QPixmap p(20, 20);
        p.fill(color);
        colorBtn->setIcon(QIcon(p));
    }
}
