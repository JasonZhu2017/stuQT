#ifndef PROGRESSDLG_H
#define PROGRESSDLG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QProgressBar>
#include <QProgressDialog>
#include <QPushButton>


class ProgressDlg : public QDialog
{
    Q_OBJECT

public:
    ProgressDlg(QWidget *parent = 0);
    ~ProgressDlg();

private slots:
    void startProgress();
private:
    QLabel* fileNum;
    QLineEdit * fileNumLEdit;
    QLabel* progressType;
    QComboBox* progressComboBox;
    QProgressBar* progressBar;
    QGridLayout* mainLayout;
    QPushButton* startBtn;
};

#endif // PROGRESSDLG_H
