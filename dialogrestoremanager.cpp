#include "dialogrestoremanager.h"
#include "ui_dialogrestoremanager.h"

DialogRestoreManager::DialogRestoreManager(QSqlDatabase &db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRestoreManager)
{
    ui->setupUi(this);
    query = new QSqlQuery(db);
    update_info();
}

DialogRestoreManager::~DialogRestoreManager()
{
    delete ui;
    delete query;
}

void DialogRestoreManager::update_info()
{
    query->clear();
    ui->comboBox_restore->clear();
    query->exec("SELECT First_name + ' ' + Middle_name + ' ' + Last_name, Phone_number FROM Manager WHERE isFired is not NULL");

    while(query->next())
    {
        ui->comboBox_restore->addItem(query->value(0).toString(), query->value(1).toString());
    }
}

void DialogRestoreManager::on_pushButton_restore_clicked()
{
    QString n = ui->comboBox_restore->currentData().toString();
    query->prepare("EXEC restoreManager :n");
    query->bindValue(":n", n);

    if(query->exec())
    {
        qDebug() << "Manager has been restored!";
    }
    this->close();

    update_info();
}

