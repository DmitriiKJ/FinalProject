#include "dialogfiremanager.h"
#include "ui_dialogfiremanager.h"

DialogFireManager::DialogFireManager(QSqlDatabase &db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFireManager)
{
    ui->setupUi(this);
    query = new QSqlQuery(db);
    update_info();
}

DialogFireManager::~DialogFireManager()
{
    delete ui;
    delete query;
}

void DialogFireManager::update_info()
{
    query->clear();
    ui->comboBox_fire->clear();
    query->exec("SELECT First_name + ' ' + Middle_name + ' ' + Last_name, Phone_number FROM Manager WHERE isFired is NULL");

    while(query->next())
    {
        ui->comboBox_fire->addItem(query->value(0).toString(), query->value(1).toString());
    }
}

void DialogFireManager::on_pushButton_fire_clicked()
{
    QString p = ui->comboBox_fire->currentData().toString();
    query->prepare("EXEC fireManager :p");
    query->bindValue(":p", p);
    if(query->exec())
    {
        qDebug() << "Manager is fires!";
    }
    this->close();

    update_info();
}

