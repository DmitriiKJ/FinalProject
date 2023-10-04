#include "dialogmanager.h"
#include "ui_dialogmanager.h"

DialogManager::DialogManager(QSqlDatabase &db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogManager)
{
    ui->setupUi(this);
    addManager = new DialogAddManager(db);
    query = new QSqlQuery(db);
    fire = new DialogFireManager(db);
    restore = new DialogRestoreManager(db);
}

DialogManager::~DialogManager()
{
    delete ui;
    delete addManager;
    delete query;
    delete restore;
    delete fire;
}

void DialogManager::showMan() const
{
    ui->tableWidget_manager->setRowCount(0);
    query->clear();
    query->exec("SELECT * FROM Manager WHERE isFired is NULL");
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

void DialogManager::on_pushButton_sort_clicked()
{
    ui->tableWidget_manager->setRowCount(0);
    query->clear();
    query->exec("SELECT * FROM Manager ORDER BY Experience DESC");
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


void DialogManager::on_pushButton_add_clicked()
{
    addManager->show();
    this->close();
}


void DialogManager::on_pushButton_find_clicked()
{
    QString first = ui->lineEdit_first->text();
    QString middle = ui->lineEdit_middle->text();
    QString last = ui->lineEdit_last->text();
    QString phone = ui->lineEdit_phone->text();

    query->prepare("SELECT * FROM Manager WHERE UPPER(First_name) like :f AND UPPER(Middle_name) like :m AND UPPER(Last_name) like :l AND UPPER(Phone_number) like :p AND isFired is null");
    query->bindValue(":f", "%" + first.toUpper() + "%");
    query->bindValue(":m", "%" + middle.toUpper() + "%");
    query->bindValue(":l", "%" + last.toUpper() + "%");
    query->bindValue(":p", "%" + phone.toUpper() + "%");

    query->exec();
    ui->tableWidget_manager->setRowCount(0);
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


void DialogManager::on_pushButton_fire_clicked()
{
    fire->update_info();
    fire->show();
    this->close();
}


void DialogManager::on_pushButton_restore_clicked()
{
    restore->update_info();
    restore->show();
    this->close();
}


void DialogManager::on_pushButton_fired_clicked()
{
    ui->tableWidget_manager->setRowCount(0);
    query->clear();
    query->exec("SELECT * FROM Manager WHERE isFired is not NULL");
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

