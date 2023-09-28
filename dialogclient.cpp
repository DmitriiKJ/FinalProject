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
    delete addClient;
}

void DialogClient::showClient() const
{
    ui->tableWidget_client->setRowCount(0);
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

void DialogClient::on_pushButton_add_clicked()
{
    addClient->show();
    this->close();
}


void DialogClient::on_pushButton_sort_first_clicked()
{
    ui->tableWidget_client->setRowCount(0);
    query->exec("SELECT * FROM Client ORDER BY First_name ASC");

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


void DialogClient::on_pushButton_sort_middle_clicked()
{
    ui->tableWidget_client->setRowCount(0);
    query->exec("SELECT * FROM Client ORDER BY Middle_name ASC");

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


void DialogClient::on_pushButton_sort_last_clicked()
{
    ui->tableWidget_client->setRowCount(0);
    query->exec("SELECT * FROM Client ORDER BY Last_name ASC");

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


void DialogClient::on_pushButton_search_clicked()
{
    ui->tableWidget_client->setRowCount(0);
    QString first = ui->lineEdit_first->text();
    QString middle = ui->lineEdit_middle->text();
    QString last = ui->lineEdit_last->text();
    QString phone = ui->lineEdit_NUM->text();
    QString address = ui->lineEdit_address->text();

    query->prepare("SELECT * FROM Client WHERE UPPER(First_name) like :f AND UPPER(Middle_name) like :m AND UPPER(Last_name) like :l AND UPPER(Phone_number) like :p AND UPPER(Address_) like :a");
    query->bindValue(":f", "%" + first.toUpper() + "%");
    query->bindValue(":m", "%" + middle.toUpper() + "%");
    query->bindValue(":l", "%" + last.toUpper() + "%");
    query->bindValue(":p", "%" + phone.toUpper() + "%");
    query->bindValue(":a", "%" + address.toUpper() + "%");

    query->exec();
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

