#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QFrame>
#include <inputdlg.h>
#include <msgboxdlg.h>
#include <QLabel>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    int count;
    QGridLayout* mainLayout;

    QPushButton* fileBtn;
    QLineEdit* fileLEdit;

    QPushButton* colorBtn;
    QFrame* colorFrame;

    QPushButton* fontBtn;
    QLineEdit* fontLEdit;

    QPushButton* inputBtn;
    InputDlg* inputDlg;

    QPushButton* msgBoxBtn;
    MsgBoxDlg* msgBoxDlg;

    QPushButton* customBtn;
    QLabel* customLabel;
private slots:
    void showFile();
    void showColor();
    void showFont();
    void showInput();
    void showMsgBox();
    void showCustomDlg();

};

#endif // DIALOG_H
