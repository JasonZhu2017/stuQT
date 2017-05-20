#include "widget.h"
#include "ui_widget.h"
#include <QRect>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->treeWidget->setWindowTitle("tree Widget");
//    QSize size = this->size();
//    QRect rect = this->geometry();
//    ui->treeWidget->setGeometry(rect);
    init();
    connect(ui->treeWidget, &QTreeWidget::itemChanged, this, &Widget::treeItemChanged);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{
    ui->treeWidget->clear();
    QTreeWidgetItem* group1 = new QTreeWidgetItem(ui->treeWidget);
    group1->setText(0, "group1");
    group1->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    group1->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem* subItem11 = new QTreeWidgetItem(group1);
    subItem11->setText(0, "subItem11");
    subItem11->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem11->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem* subItem12 = new QTreeWidgetItem(group1);
    subItem12->setText(0, "subItem12");
    subItem12->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem12->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem* subItem13 = new QTreeWidgetItem(group1);
    subItem13->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem13->setText(0, "subItem13");
    subItem13->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem* group2 = new QTreeWidgetItem(ui->treeWidget);
    group2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    group2->setText(0, "group2");
    group2->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem* subItem21 = new QTreeWidgetItem(group2);
    subItem21->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem21->setText(0, "subItem21");
    subItem21->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem* subItem22 = new QTreeWidgetItem(group2);
    subItem22->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem22->setText(0, "subItem22");
    subItem22->setCheckState(0, Qt::Unchecked);
}

void Widget::updateParentItem(QTreeWidgetItem *item)
{
    QTreeWidgetItem* parent = item->parent();
    if (parent == NULL){
        return;
    }
    int selectedCount = 0;
    int childCount = parent->childCount();
    for (int i=0; i<childCount; i++){
        QTreeWidgetItem* item = parent->child(i);
        if (item->checkState(0) == Qt::Checked){
            selectedCount ++ ;
        }
    }
    if (selectedCount <= 0){
        parent->setCheckState(0, Qt::Unchecked);
    }else if(selectedCount < childCount) {
        parent->setCheckState(0, Qt::PartiallyChecked);
    }else if (selectedCount == childCount) {
        parent->setCheckState(0, Qt::Checked);
    }

}

void Widget::treeItemChanged(QTreeWidgetItem *item, int coulumn)
{
    QString itemText = item->text(0);
    if (Qt::Checked == item->checkState(0)){
//        QTreeWidgetItem* parent = item->parent();
        int count = item->childCount();
        if (count > 0){
            for (int i=0; i<count; i++){
                item->child(i)->setCheckState(0, Qt::Checked);
            }
        }else{
            updateParentItem(item);
        }
    }else if (Qt::Unchecked == item->checkState(0)){
        int count = item->childCount();
        if (count > 0){
            for (int i=0; i<count; i++){
                item->child(i)->setCheckState(0, Qt::Unchecked);
            }
        }else{
            updateParentItem(item);
        }
    }
}

void Widget::on_pushButton_clicked()
{
    QTreeWidgetItem* t = ui->treeWidget->itemBelow(ui->treeWidget->currentItem());
    if (Qt::Checked == t->checkState(0))
        t->setCheckState(0, Qt::Unchecked);
    else
        t->setCheckState(0, Qt::Checked);
}
