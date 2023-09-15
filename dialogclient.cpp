#include "dialogclient.h"
#include "ui_dialogclient.h"

DialogClient::DialogClient(QSqlDatabase &db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogClient)
{
    ui->setupUi(this);
    query = new QSqlQuery(db);
    addClient = new DialogAddClients(db);
}

DialogClient::~DialogClient()
{
    delete ui;
    delete query;
}

void DialogClient::showClient() const
{
    query->exec("SELECT * FROM Client");

    int i  = 0;
    while(query->next())
    {
        QString first = query->value(1).toString();
        QString middle = query->value(2).toString();
        QString last = query->value(3).toString();
        QString phone = query->value(4).toString();
        QString address = query->value(5).toString();


        ui->tableWidget_client->setRowCount(i + 1);

        QTableWidgetItem* First = new QTableWidgetItem();
        QTableWidgetItem* Middle = new QTableWidgetItem();
        QTableWidgetItem* Last = new QTableWidgetItem();
        QTableWidgetItem* Phone = new QTableWidgetItem();
        QTableWidgetItem* Address = new QTableWidgetItem();

        First->setText(first);
        Middle->setText(middle);
        Last->setText(last);
        Phone->setText(phone);
        Address->setText(address);

        ui->tableWidget_client->setItem(i, 0, First);
        ui->tableWidget_client->setItem(i, 1, Middle);
        ui->tableWidget_client->setItem(i, 2, Last);
        ui->tableWidget_client->setItem(i, 3, Phone);
        ui->tableWidget_client->setItem(i, 4, Address);

        i++;
    }
}

void DialogClient::on_pushButton_clicked()
{
    addClient->show();
    this->close();
}

