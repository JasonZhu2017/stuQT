#ifndef BASEINFO_H
#define BASEINFO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QPushButton>
#include <QGridLayout>

class BaseInfo : public QWidget
{
    Q_OBJECT
public:
    explicit BaseInfo(QWidget *parent = 0);
//    ~BaseInfo();
//private:
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

//    QPushButton *okBtn;
//    QPushButton *cancelBtn;
//    QHBoxLayout *bottomLayout;

signals:

public slots:
};

#endif // BASEINFO_H
