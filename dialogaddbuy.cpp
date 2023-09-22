#include "dialogaddbuy.h"
#include "ui_dialogaddbuy.h"

DialogAddBuy::DialogAddBuy(QSqlDatabase &db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddBuy)
{
    ui->setupUi(this);
    query = new QSqlQuery(db);

    query->exec("SELECT First_name + ' ' + Middle_name + ' ' + Last_name, Phone_number FROM Client");
    while(query->next())
    {
        ui->comboBox_client->addItem(query->value(0).toString(), query->value(1).toString());
    }

    query->clear();
    query->exec("SELECT model + ' ' + Cast(Year_ as nvarchar(10)), ID FROM Car WHERE isSold is null");
    while(query->next())
    {
        ui->comboBox_car->addItem(query->value(0).toString(), query->value(1).toInt());
    }
}

DialogAddBuy::~DialogAddBuy()
{
    delete ui;
    delete query;
}

void DialogAddBuy::on_pushButton_add_clicked()
{
    QString client = ui->comboBox_client->currentData().toString();
    int car = ui->comboBox_car->currentData().toInt();

    query->prepare("EXEC addBuy :c, :m");
    query->bindValue(":c", client);
    query->bindValue(":m", car);

    if(query->exec())
    {
        qDebug() << "Покупка оформлена";
    }

    this->close();
    ui->comboBox_car->clear();

    query->clear();
    query->exec("SELECT model + ' ' + Cast(Year_ as nvarchar(10)), ID FROM Car WHERE isSold is null");
    while(query->next())
    {
        ui->comboBox_car->addItem(query->value(0).toString(), query->value(1).toInt());
    }
}

