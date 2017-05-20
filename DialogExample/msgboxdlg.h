#ifndef MSGBOXDLG_H
#define MSGBOXDLG_H

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>

class MsgBoxDlg : public QDialog
{
    Q_OBJECT
public:
    MsgBoxDlg(QWidget* parent = 0);
    ~MsgBoxDlg();

private slots:
    void showQuestion();
    void showInfomation();
    void showWarning();
    void showCritical();
    void showAbout();
    void showAboutQt();

private:
    QLabel* label;
    QPushButton* questionBtn;
    QPushButton* infoBtn;
    QPushButton* warningBtn;
    QPushButton* criticalBtn;
    QPushButton* aboutBtn   ;
    QPushButton* aboutQtBtn;

    QGridLayout* mainLayout;
};

#endif // MSGBOXDLG_H
