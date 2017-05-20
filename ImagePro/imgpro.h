#ifndef IMGPRO_H
#define IMGPRO_H

#include <QMainWindow>
#include <QString>
#include <QTextCharFormat>
#include <QMenu>
#include <QToolBar>
#include <QAction>
#include <QImage>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>

#include <showwidget.h>
#include <QFontComboBox>
#include <QToolButton>
#include <QActionGroup>


class ImgPro : public QMainWindow
{
    Q_OBJECT

public:
    ImgPro(QWidget *parent = 0);
    ~ImgPro();

    void createMenus();
    void createToolBars();
    void createActions();

    void loadFile(QString fileName);
    void mergeFormat(QTextCharFormat);

private:
    QMenu* fileMenu;
    QMenu* editMenu;
    QMenu* rotateMenu;
    QMenu* mirrorMenu;

    QImage img;
    QString filename;
    ShowWidget* showWidget;

    QAction* openFileAct;
    QAction* newFileAct;
    QAction* printTextAct;
    QAction* printImgAct;
    QAction* exitAct;

    QAction* copyAct;
    QAction* cutAct;
    QAction* pasteAct;
    QAction* aboutAct;
    QAction* zoomInAct;
    QAction* zoomOutAct;

    QAction* rotate90Act;
    QAction* rotate180Act;
    QAction* rotate270Act;

    QAction* mirrorVerAct;
    QAction* mirrorHorAct;

    QAction* undoAct;
    QAction* redoAct;


    QToolBar* fileTBar;
    QToolBar* editTBar;
    QToolBar* rotateTBar;
    QToolBar* mirrorTBar;

    QToolBar* doTBar;

    QLabel * fontLabel1;
    QFontComboBox* fontComboBox;
    QLabel * fontLabel2;
    QComboBox * sizeComboBox;
    QToolButton* boldBtn;
    QToolButton* italicBtn;
    QToolButton* underlineBtn;
    QToolButton* colorBtn;

    QToolBar * fontTBar;

    QLabel* listLabel;
    QComboBox* listComboBox;
    QActionGroup* actGrp;
    QAction* leftAct;
    QAction* rightAct;
    QAction* centerAct;
    QAction* justifyAct;

    QToolBar* listTBar;



private slots:
    void showNewFile();
    void showOpenFile();
    void showPrintText();
    void showPrintImg();
    void showZoomIn();
    void showZoomOut();
    void showRotate90();
    void showRotate180();
    void showRotate270();
    void showMirrorVer();
    void showMirrorHor();

    void showFontComboBox(QString str);
    void showSizeSpinBox(QString str);
    void showBoldBtn();
    void showItalicBtn();
    void showUnderLineBtn();
    void showColorBtn();
    void showCurrentFormatChanged(const QTextCharFormat &fmt);

    void showList(int);
    void showAlignment(QAction* act);
    void showCursorPositionChanged();

};

#endif // IMGPRO_H
