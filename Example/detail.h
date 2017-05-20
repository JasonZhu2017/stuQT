#ifndef DETAIL_H
#define DETAIL_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>
#include <QLineEdit>

class Detail : public QWidget
{
    Q_OBJECT
public:
    explicit Detail(QWidget *parent = 0);
private:
    QLabel* nationalLabel;
    QComboBox* nationalComboBox;
    QLabel* provinceLabel;
    QComboBox* provinceComboBox;
    QLabel* cityLabel;
    QLineEdit* cityLEdit;
    QLabel* introductLabel;
    QTextEdit* introductTEdit;
    QGridLayout* mainLayout;
signals:

public slots:
};

#endif // DETAIL_H
