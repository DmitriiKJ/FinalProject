#include "dialogmanager.h"
#include "ui_dialogmanager.h"

DialogManager::DialogManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogManager)
{
    ui->setupUi(this);
}

DialogManager::~DialogManager()
{
    delete ui;
}

void DialogManager::showMan(AutoShop shop) const
{
    QVector<Manager*> arr = shop.get_managers();

    for(int i = 0; i < arr.size(); i++)
    {
        ui->tableWidget_manager->setRowCount(i + 1);

        QTableWidgetItem* First = new QTableWidgetItem();
        QTableWidgetItem* Middle = new QTableWidgetItem();
        QTableWidgetItem* Last = new QTableWidgetItem();
        QTableWidgetItem* Phone = new QTableWidgetItem();
        QTableWidgetItem* Birthday = new QTableWidgetItem();
        QTableWidgetItem* Exp = new QTableWidgetItem();

        First->setText(arr[i]->get_first_name());
        Middle->setText(arr[i]->get_middle_name());
        Last->setText(arr[i]->get_last_name());
        Phone->setText(arr[i]->get_phone_number());
        Birthday->setText(arr[i]->get_birthday().toString());
        Exp->setTextAlignment(arr[i]->get_experience());

        ui->tableWidget_manager->setItem(i, 0, First);
        ui->tableWidget_manager->setItem(i, 1, Middle);
        ui->tableWidget_manager->setItem(i, 2, Last);
        ui->tableWidget_manager->setItem(i, 3, Phone);
        ui->tableWidget_manager->setItem(i, 4, Birthday);
        ui->tableWidget_manager->setItem(i, 5, Exp);
    }
}


void DialogManager::on_pushButton_clicked()
{

}

