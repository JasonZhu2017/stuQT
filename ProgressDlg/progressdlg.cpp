#include "progressdlg.h"
#include <Qfont>
#include <QPalette>



ProgressDlg::ProgressDlg(QWidget *parent)
    : QDialog(parent)
{
    QFont font("ZYSong18030", 12);
    this->setFont(font);

    fileNum = new QLabel(tr("文件数目： "));
    fileNumLEdit = new QLineEdit();
    fileNumLEdit->setText(tr("10000"));

    progressType = new QLabel(tr("显示类型： "));
    progressComboBox = new QComboBox();
    progressComboBox->addItem(tr("progress bar"));
    progressComboBox->addItem(tr("progress Dialog"));

    progressBar = new QProgressBar();

    startBtn = new QPushButton(tr("start"));

    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(5);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(fileNum, 0, 0);
    mainLayout->addWidget(fileNumLEdit, 0, 1);
    mainLayout->addWidget(progressType, 1, 0);
    mainLayout->addWidget(progressComboBox, 1, 1);
    mainLayout->addWidget(progressBar, 2, 0, 1, 2);
    mainLayout->addWidget(startBtn, 3, 1);

    connect(startBtn, &QPushButton::clicked, this, &ProgressDlg::startProgress);
}

ProgressDlg::~ProgressDlg()
{

}

void ProgressDlg::startProgress()
{
    bool ok;
    int num = fileNumLEdit->text().toInt(&ok);
    if (progressComboBox->currentIndex() == 0)
    {
        progressBar->setRange(0, num);
        for (int i=0; i<num; i++)
        {
            progressBar->setValue(i);
        }
    }
    else if (progressComboBox->currentIndex() == 1)
    {
        QProgressDialog * dlg = new QProgressDialog(this);
        QFont font("ZYSong18030", 12);
        dlg->setFont(font);
        dlg->setWindowModality(Qt::WindowModal);
        dlg->setMinimumDuration(5);
        dlg->setWindowTitle(tr("please wait"));
        dlg->setLabelText(tr("please waiting..."));
        dlg->setCancelButtonText(tr("Cancel"));
        dlg->setRange(0, num);
        for(int i=0; i<num; i++)
        {
            dlg->setValue(i);
            if (dlg->wasCanceled())
                return;
        }
    }

}
