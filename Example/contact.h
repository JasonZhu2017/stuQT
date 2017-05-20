#ifndef CONTACT_H
#define CONTACT_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QGridLayout>

class Contact : public QWidget
{
    Q_OBJECT
public:
    explicit Contact(QWidget *parent = 0);
private:
    QLabel* emailLabel;
    QLineEdit* emailLEdit;
    QLabel* addrLabel;
    QLineEdit* addrLEdit;
    QLabel* codeLabel;
    QLineEdit* codeLEdit;
    QLabel* mobileLabel;
    QLineEdit* mobileLEdit;
    QCheckBox* mobileCheckBox;
    QLabel* workPhoneLabel;
    QLineEdit* workPhoneLEdit;
    QGridLayout* mainLayout;
signals:

public slots:
};

#endif // CONTACT_H
