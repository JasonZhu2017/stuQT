#include "imgpro.h"
#include <QLineEdit>
#include <QMenuBar>
#include <QFileDialog>
#include <QDebug>
#include <iostream>
#include <QMatrix>
#include <QColorDialog>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextList>

ImgPro::ImgPro(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle(tr("Easy Word"));

    showWidget = new ShowWidget(this);
    this->setCentralWidget(showWidget);

    listLabel = new QLabel(tr(" 排序："));
    listComboBox = new QComboBox;
    listComboBox->addItem("Standard");
    listComboBox->addItem("QTextListFormat::ListDisc");
    listComboBox->addItem("QTextListFormat::ListCircle");
    listComboBox->addItem("QTextListFormat::ListSquare");
    listComboBox->addItem("QTextListFormat::ListDecimail");
    listComboBox->addItem("QTextListFormat::ListLowerAlpha");
    listComboBox->addItem("QTextListFormat::ListUpperAlpha");
    listComboBox->addItem("QTextListFormat::ListLowerRoman");
    listComboBox->addItem("QTextListFormat::ListUpperRoman");


    fontLabel1 = new QLabel(tr(" 字体："));
    fontComboBox = new QFontComboBox;
    fontComboBox->setFontFilters(QFontComboBox::ScalableFonts);
    fontLabel2 = new QLabel(tr(" 字号："));
    sizeComboBox = new QComboBox;

    QFontDatabase db;
    foreach (int size, db.standardSizes())
        sizeComboBox->addItem(QString::number(size));

    boldBtn = new QToolButton;
    boldBtn->setIcon(QIcon("bold.png"));
    boldBtn->setCheckable(true);

    italicBtn = new QToolButton;
    italicBtn->setIcon(QIcon("italic.png"));
    italicBtn->setCheckable(true);

    underlineBtn = new QToolButton;
    underlineBtn->setIcon(QIcon("underline.png"));
    underlineBtn->setCheckable(true);

    colorBtn = new QToolButton;
    colorBtn->setIcon(QIcon("color.png"));
    colorBtn->setCheckable(true);

    void (QFontComboBox:: * activated_str)(const QString &) = &QFontComboBox::activated;
    connect(fontComboBox, activated_str, this, &ImgPro::showFontComboBox);
    void (QComboBox:: * activated_string)(const QString &) = &QComboBox::activated;
    connect(sizeComboBox, activated_string, this, &ImgPro::showSizeSpinBox);
    connect(boldBtn, &QToolButton::clicked, this, &ImgPro::showBoldBtn);
    connect(italicBtn, &QToolButton::clicked, this, &ImgPro::showItalicBtn);
    connect(underlineBtn, &QToolButton::clicked, this, &ImgPro::showUnderLineBtn);
    connect(colorBtn, &QToolButton::clicked, this, &ImgPro::showColorBtn);
    connect(showWidget->textEdit, &QTextEdit::currentCharFormatChanged, this, &ImgPro::showCurrentFormatChanged);

    createActions();
    createToolBars();
    createMenus();
    void (QComboBox:: * activated_int)(int) = QComboBox::activated;
    connect(listComboBox, activated_int, this, &ImgPro::showList);
    connect(showWidget->textEdit->document(), &QTextDocument::undoAvailable, undoAct, &QAction::setEnabled);
    connect(showWidget->textEdit->document(), &QTextDocument::redoAvailable, redoAct, &QAction::setEnabled);
    connect(showWidget->textEdit, &QTextEdit::cursorPositionChanged, this, &ImgPro::showCursorPositionChanged);

    if (img.load("img.png"))
    {
        showWidget->imgLabel->setPixmap(QPixmap::fromImage(img));
    }


}

ImgPro::~ImgPro()
{

}

void ImgPro::createMenus()
{
    fileMenu = this->menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(openFileAct);
    fileMenu->addAction(newFileAct);
    fileMenu->addAction(printTextAct);
    fileMenu->addAction(printImgAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
    fileMenu->addAction(aboutAct);

    editMenu = this->menuBar()->addMenu(tr("编辑"));
    editMenu->addAction(copyAct);
    editMenu->addAction(cutAct);
    editMenu->addAction(pasteAct);
    editMenu->addSeparator();
    editMenu->addAction(zoomInAct);
    editMenu->addAction(zoomOutAct);

    rotateMenu = this->menuBar()->addMenu(tr("旋转"));
    rotateMenu->addAction(rotate90Act);
    rotateMenu->addAction(rotate180Act);
    rotateMenu->addAction(rotate270Act);

    mirrorMenu = this->menuBar()->addMenu(tr("镜像"));
    mirrorMenu->addAction(mirrorVerAct);
    mirrorMenu->addAction(mirrorHorAct);

}

void ImgPro::createToolBars()
{
    fileTBar = this->addToolBar(tr("file"));
    fileTBar->addAction(openFileAct);
    fileTBar->addAction(newFileAct);
    fileTBar->addAction(printTextAct);
    fileTBar->addAction(printImgAct);

    fileTBar->setAllowedAreas(Qt::TopToolBarArea | Qt::LeftToolBarArea | Qt::RightToolBarArea);
//    fileTBar->setMovable(false);

    editTBar = this->addToolBar(tr("edit"));
    editTBar->addAction(copyAct);
    editTBar->addAction(cutAct);
    editTBar->addAction(pasteAct);
    editTBar->addSeparator();
    editTBar->addAction(zoomInAct);
    editTBar->addAction(zoomOutAct);

    rotateTBar = this->addToolBar(tr("rotate"));
    rotateTBar->addAction(rotate90Act);
    rotateTBar->addAction(rotate180Act);
    rotateTBar->addAction(rotate270Act);

    doTBar = this->addToolBar(tr("do"));
    doTBar->addAction(undoAct);
    doTBar->addAction(redoAct);

    fontTBar = this->addToolBar(tr("Font"));
    fontTBar->addWidget(fontLabel1);
    fontTBar->addWidget(fontComboBox);
    fontTBar->addWidget(fontLabel2);
    fontTBar->addWidget(sizeComboBox);
    fontTBar->addSeparator();
    fontTBar->addWidget(boldBtn);
    fontTBar->addWidget(italicBtn);
    fontTBar->addWidget(underlineBtn);
    fontTBar->addSeparator();
    fontTBar->addWidget(colorBtn);

    listTBar = this->addToolBar(tr("list"));
    listTBar->addWidget(listLabel);
    listTBar->addWidget(listComboBox);
    listTBar->addSeparator();
    listTBar->addActions(actGrp->actions());

}

void ImgPro::createActions()
{
    //打开
    openFileAct = new QAction(QIcon("open.png"), tr("打开"), this);
    openFileAct->setShortcut(tr("Ctrl+O"));
    openFileAct->setStatusTip(tr("打开一个文件"));
    connect(openFileAct, &QAction::triggered, this, &ImgPro::showOpenFile);

    //新建
    newFileAct = new QAction(QIcon("new.png"), tr("新建"), this);
    newFileAct->setShortcut(tr("Ctrl+N"));
    newFileAct->setStatusTip(tr("新建一个文件"));
    connect(newFileAct, &QAction::triggered, this, &ImgPro::showNewFile);

    //退出
    exitAct = new QAction(QIcon("exit.png"), tr("退出"), this);
    exitAct->setShortcut(tr("Ctrl+Q"));
    exitAct->setStatusTip(tr("退出程序"));
    connect(exitAct, &QAction::triggered, this, &ImgPro::close);

    //复制
    copyAct = new QAction(QIcon("copy.png"), tr("复制"), this);
    copyAct->setShortcut(tr("Ctrl+C"));
    copyAct->setStatusTip(tr("复制文件"));
//    connect(copyAct, &QAction::triggered, this, &ImgPro::copy);

    //剪切
    cutAct = new QAction(QIcon("cut.png"), tr("剪切"), this);
    cutAct->setShortcut(tr("Ctrl+X"));
    cutAct->setStatusTip(tr("剪切文件"));
//    connect(cutAct, &QAction::triggered, this, &ImgPro::cut);

    //粘贴
    pasteAct = new QAction(QIcon("paste.png"), tr("粘贴"), this);
    pasteAct->setShortcut(tr("Ctrl+V"));
    pasteAct->setStatusTip(tr("粘贴文件"));
//    connect(pasteAct, &QAction::triggered, this, &ImgPro::past);

    //关于
    aboutAct = new QAction(QIcon("about.png"), tr("关于"), this);
//    aboutAct->setShortcut();
//    connect(aboutAct, &QAction::triggered, this, &ImgPro::about);

    //打印文本
    printTextAct = new QAction(QIcon("printText.png"), tr("打印文本"), this);
    printTextAct->setStatusTip(tr("打印一个文本"));
    connect(printTextAct, &QAction::triggered, this, &ImgPro::showPrintText);


    //打印图像
    printImgAct = new QAction(QIcon("printImage.png"), tr("打印图像"), this);
    printImgAct->setStatusTip(tr("打印一幅图像"));
    connect(printImgAct, &QAction::triggered, this, &ImgPro::showPrintImg);

    //放大
    zoomInAct = new QAction(QIcon("zoomIn.png"), tr("放大"), this);
    zoomInAct->setStatusTip(tr("放大一幅图像"));
    connect(zoomInAct, &QAction::triggered, this, &ImgPro::showZoomIn);

    //缩小
    zoomOutAct = new QAction(QIcon("zoomOut.png"), tr("缩小"), this);
    zoomOutAct->setStatusTip(tr("缩小一幅图像"));
    connect(zoomOutAct, &QAction::triggered, this, &ImgPro::showZoomOut);


    //旋转
    rotate90Act = new QAction(QIcon("rotate90.png"), tr("旋转90°"), this);
    rotate90Act->setStatusTip(tr("将图像旋转90°"));
    connect(rotate90Act, &QAction::triggered, this, &ImgPro::showRotate90);

    rotate180Act = new QAction(QIcon("rotate180.png"), tr("旋转180°"), this);
    rotate180Act->setStatusTip(tr("将图像旋转180°"));
    connect(rotate180Act, &QAction::triggered, this, &ImgPro::showRotate180);

    rotate270Act = new QAction(QIcon("rotate270.png"), tr("旋转270°"), this);
    rotate270Act->setStatusTip(tr("将图像旋转270°"));
    connect(rotate270Act, &QAction::triggered, this, &ImgPro::showRotate270);

    //镜像
    mirrorVerAct = new QAction(QIcon("mirrorVer.png"), tr("纵向镜像"), this);
    mirrorVerAct->setStatusTip(tr("对图像做纵向镜像"));
    connect(mirrorVerAct, &QAction::triggered, this, &ImgPro::showMirrorVer);

    mirrorHorAct = new QAction(QIcon("mirrorHor.png"), tr("横向镜像"), this);
    mirrorHorAct->setStatusTip(tr("对图像做横向镜像"));
    connect(mirrorHorAct, &QAction::triggered, this, &ImgPro::showMirrorHor);

    //撤销与恢复
    undoAct = new QAction(QIcon("undo.png"), tr("撤销"), this);
    connect(undoAct, &QAction::triggered, this->showWidget->textEdit, &QTextEdit::undo);

    redoAct = new QAction(QIcon("redo.png"), tr("恢复"), this);
    connect(redoAct, &QAction::triggered, this->showWidget->textEdit, &QTextEdit::redo);

    actGrp = new QActionGroup(this);
    leftAct = new QAction(QIcon("left.png"), tr("左对齐"), actGrp);
    leftAct->setCheckable(true);

    rightAct = new QAction(QIcon("right.png"), tr("右对齐"), actGrp);
    rightAct->setCheckable(true);

    centerAct = new QAction(QIcon("center.png"), tr("居中"), actGrp);
    centerAct->setCheckable(true);

    justifyAct = new QAction(QIcon("justify.png"), tr("两端对齐"), actGrp);
    justifyAct->setCheckable(true);

    connect(actGrp, &QActionGroup::triggered, this, &ImgPro::showAlignment);


}

void ImgPro::showNewFile()
{
    ImgPro * newImgPro = new ImgPro(this);
    newImgPro->show();
}

void ImgPro::showOpenFile()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (this->showWidget->textEdit->document()->isEmpty())
    {
        loadFile(fileName);
    }
    else
    {
        ImgPro* newImgPro = new ImgPro(this);
        newImgPro->show();
        newImgPro->loadFile(fileName);
    }
}

void ImgPro::showPrintText()
{
    QPrinter printer;
    QPrintDialog printDlg(&printer, this);
    if(printDlg.exec())
    {
        QTextDocument *textDoc = this->showWidget->textEdit->document();
        textDoc->print(&printer);
    }
}

void ImgPro::showPrintImg()
{
    QPrinter printer;
    QPrintDialog printDlg(&printer, this);
    if (printDlg.exec())
    {
        QPainter painter(&printer);
        QRect rect = painter.viewport();
        qDebug() << "viewport: " << rect;
        QSize size = img.size();
        qDebug() << "size: " << size;
//        size.scale(rect.size(),Qt::KeepAspectRatio);
        qDebug() << "size: " << size;
        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
        qDebug() << rect.x() << rect.y() << size.width() << size.height();
        painter.setWindow(img.rect());
        qDebug() << img.rect();
        painter.drawImage(0, 0, img);
    }

}

void ImgPro::showZoomIn()
{
    if (img.isNull())
        return;
    QMatrix matrix;
    matrix.scale(2, 2);
    img = img.transformed(matrix);
    showWidget->imgLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgPro::showZoomOut()
{
    if (img.isNull())
        return;
    QMatrix matrix;
    matrix.scale(0.5, 0.5);
    img = img.transformed(matrix);
    showWidget->imgLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgPro::showRotate90()
{
    if (img.isNull())
        return;
    QMatrix matrix;
    matrix.rotate(90);
    img = img.transformed(matrix);
    showWidget->imgLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgPro::showRotate180()
{
    if (img.isNull())
        return;
    QMatrix matrix;
    matrix.rotate(180);
    img = img.transformed(matrix);
    showWidget->imgLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgPro::showRotate270()
{
    if (img.isNull())
        return;
    QMatrix matrix;
    matrix.rotate(270);
    img = img.transformed(matrix);
    showWidget->imgLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgPro::showMirrorVer()
{
    if (img.isNull())
        return;
    img = img.mirrored(false, true);
    showWidget->imgLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgPro::showMirrorHor()
{
    if (img.isNull())
        return;
    img = img.mirrored(true, false);
    showWidget->imgLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgPro::showFontComboBox(QString str)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(str);
    mergeFormat(fmt);
}

void ImgPro::showSizeSpinBox(QString str)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(str.toFloat());
//    showWidget->textEdit->mergeCurrentCharFormat(fmt);
    mergeFormat(fmt);
}

void ImgPro::showBoldBtn()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(boldBtn->isChecked()?QFont::Bold : QFont::Normal);
    showWidget->textEdit->mergeCurrentCharFormat(fmt);
}

void ImgPro::showItalicBtn()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(italicBtn->isChecked());
    mergeFormat(fmt);
}

void ImgPro::showUnderLineBtn()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(underlineBtn->isChecked());
    mergeFormat(fmt);
}

void ImgPro::showColorBtn()
{
    QColor color = QColorDialog::getColor(Qt::red, this);
    if (color.isValid())
    {
        QTextCharFormat fmt;
        fmt.setForeground(color);
        showWidget->textEdit->mergeCurrentCharFormat(fmt);
    }
}

void ImgPro::showCurrentFormatChanged(const QTextCharFormat &fmt)
{
    fontComboBox->setCurrentIndex(fontComboBox->findText(fmt.fontFamily()));
    sizeComboBox->setCurrentIndex(sizeComboBox->findText(QString::number(fmt.fontPointSize())));
    boldBtn->setChecked(fmt.font().bold());
    italicBtn->setChecked(fmt.fontItalic());
    underlineBtn->setChecked(fmt.fontUnderline());
}

void ImgPro::showList(int index)
{
    QTextCursor cursor = showWidget->textEdit->textCursor();
    if (index != 0)
    {
        QTextListFormat::Style style = QTextListFormat::ListDisc;
        switch(index)
        {
        default:
        case 1:
            style = QTextListFormat::ListDisc; break;
        case 2:
            style = QTextListFormat::ListCircle; break;
        case 3:
            style = QTextListFormat::ListSquare; break;
        case 4:
            style = QTextListFormat::ListDecimal; break;
        case 5:
            style = QTextListFormat::ListLowerAlpha; break;
        case 6:
            style = QTextListFormat::ListUpperAlpha; break;
        case 7:
            style = QTextListFormat::ListLowerRoman; break;
        case 8:
            style = QTextListFormat::ListUpperRoman; break;
        }
        cursor.beginEditBlock();
        QTextBlockFormat bfmt = cursor.blockFormat();
        QTextListFormat lfmt;
        if (cursor.currentList())
        {
            lfmt = cursor.currentList()->format();
        }
        else
        {
            lfmt.setIndent(bfmt.indent() + 1);
            bfmt.setIndent(0);
            cursor.setBlockFormat(bfmt);
        }
        lfmt.setStyle(style);
        cursor.createList(lfmt);

        cursor.endEditBlock();
    }
    else
    {
        QTextBlockFormat bfmt;
        bfmt.setObjectIndex(-1);
        cursor.mergeBlockFormat(bfmt);
    }
}

void ImgPro::showAlignment(QAction *act)
{
    if (act == leftAct)
        showWidget->textEdit->setAlignment(Qt::AlignLeft);
    if (act == rightAct)
        showWidget->textEdit->setAlignment(Qt::AlignRight);
    if (act == centerAct)
        showWidget->textEdit->setAlignment(Qt::AlignCenter);
    if (act == justifyAct)
        showWidget->textEdit->setAlignment(Qt::AlignJustify);
}

void ImgPro::showCursorPositionChanged()
{
    if (showWidget->textEdit->alignment() == Qt::AlignLeft)
        leftAct->setChecked(true);
    if (showWidget->textEdit->alignment() == Qt::AlignRight)
        rightAct->setChecked(true);
    if (showWidget->textEdit->alignment() == Qt::AlignCenter)
        centerAct->setChecked(true);
    if (showWidget->textEdit->alignment() == Qt::AlignJustify)
        justifyAct->setChecked(true);

}

void ImgPro::loadFile(QString fileName)
{
//    printf("file name is:%s\n", fileName.data());
//    QByteArray bArray = fileName.toLatin1();
//    printf("file name is:%s\n", bArray.data());
    qDebug() << "file name is:" << fileName;
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        while (!stream.atEnd())
        {
            showWidget->textEdit->append(stream.readLine());
//            printf("read line");
            qDebug() << "read line";
        }
//        printf("end\n");
        qDebug() << "end";
    }
}

void ImgPro::mergeFormat(QTextCharFormat fmt)
{
    QTextCursor cursor = showWidget->textEdit->textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(fmt);
    showWidget->textEdit->mergeCurrentCharFormat(fmt);
}
