#include "dialogmanager.h"
#include "ui_dialogmanager.h"

DialogManager::DialogManager(QSqlDatabase &db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogManager)
{
    ui->setupUi(this);
    addManager = new DialogAddManager(db);
    query = new QSqlQuery(db);
}

DialogManager::~DialogManager()
{
    delete ui;
}

void DialogManager::showMan() const
{
    query->clear();
    query->exec("SELECT * FROM Manager");
    int i = 0;
    while(query->next())
    {
        QString first = query->value(1).toString();
        QString middle = query->value(2).toString();
        QString last = query->value(3).toString();
        QDate date = query->value(4).toDate();
        QString exp = query->value(5).toString();
        QString phone = query->value(6).toString();

        ui->tableWidget_manager->setRowCount(i + 1);

        QTableWidgetItem* First = new QTableWidgetItem();
        QTableWidgetItem* Middle = new QTableWidgetItem();
        QTableWidgetItem* Last = new QTableWidgetItem();
        QTableWidgetItem* Phone = new QTableWidgetItem();
        QTableWidgetItem* Birthday = new QTableWidgetItem();
        QTableWidgetItem* Exp = new QTableWidgetItem();

        First->setText(first);
        Middle->setText(middle);
        Last->setText(last);
        Phone->setText(phone);
        Birthday->setText(date.toString());
        Exp->setText(exp);

        ui->tableWidget_manager->setItem(i, 0, First);
        ui->tableWidget_manager->setItem(i, 1, Middle);
        ui->tableWidget_manager->setItem(i, 2, Last);
        ui->tableWidget_manager->setItem(i, 3, Phone);
        ui->tableWidget_manager->setItem(i, 4, Birthday);
        ui->tableWidget_manager->setItem(i, 5, Exp);

        i++;
    }

}


void DialogManager::on_pushButton_clicked()
{
    addManager->show();
}

