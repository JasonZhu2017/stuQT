#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    QLabel *userNameLabel;
    QLabel *nameLabel;
    QLabel *sexLabel;
    QLabel *departmentLabel;
    QLabel *ageLabel;
    QLabel *otherLabel;
    QLineEdit *userNameLEdit;
    QLineEdit *nameLEdit;
    QComboBox *sexComboBox;
    QTextEdit *departmentTEdit;
    QLineEdit *ageLEdit;

    QGridLayout *leftLayout;
    QLabel *headLabel;
    QLabel *headIconLabel;
    QPushButton *updateHeadBtn;
    QHBoxLayout *topRightLayout;
    QLabel *introductionLabel;
    QTextEdit *introductionTEdit;
    QVBoxLayout *rightLayout;

    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QHBoxLayout *bottomLayout;
};

#endif // DIALOG_H
