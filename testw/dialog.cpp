#include "dialog.h"
#include "ui_dialog.h"
#include <QRegExp>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QRegExp exp("[A-Za-z][1-9][6-9]{5}");
    ui->lineEdit->setValidator(new QRegExpValidator(exp, this));
    connect(ui->okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->cancelButton, &QPushButton::clicked, this, &Dialog::reject);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &Dialog::on_editLine_textChanged);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_editLine_textChanged()
{
    ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}
