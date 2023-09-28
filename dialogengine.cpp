#include "dialogengine.h"
#include "ui_dialogengine.h"

DialogEngine::DialogEngine(QSqlDatabase &db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEngine)
{
    ui->setupUi(this);
    addEngine = new DialogAddEngine(db);
    query = new QSqlQuery(db);
}

DialogEngine::~DialogEngine()
{
    delete ui;
    delete query;
    delete addEngine;
}

void DialogEngine::showEngine() const
{
    ui->tableWidget_engine->setRowCount(0);
    query->exec("SELECT * FROM Engine");

    int i = 0;
    while(query->next())
    {
        QString model = query->value(0).toString();
        QString type = query->value(1).toString();
        QString power = query->value(2).toString();

        ui->tableWidget_engine->setRowCount(i + 1);

        QTableWidgetItem* Model = new QTableWidgetItem();
        QTableWidgetItem* Type = new QTableWidgetItem();
        QTableWidgetItem* Power = new QTableWidgetItem();

        Model->setText(model);
        Type->setText(type);
        Power->setText(power);

        ui->tableWidget_engine->setItem(i, 0, Model);
        ui->tableWidget_engine->setItem(i, 1, Type);
        ui->tableWidget_engine->setItem(i, 2, Power);

        i++;
    }
}

void DialogEngine::on_pushButton_add_clicked()
{
    addEngine->show();
    this->close();
}


void DialogEngine::on_pushButton_sort_model_clicked()
{
    ui->tableWidget_engine->setRowCount(0);
    query->exec("SELECT * FROM Engine ORDER BY Engine_model ASC");

    int i = 0;
    while(query->next())
    {
        QString model = query->value(0).toString();
        QString type = query->value(1).toString();
        QString power = query->value(2).toString();

        ui->tableWidget_engine->setRowCount(i + 1);

        QTableWidgetItem* Model = new QTableWidgetItem();
        QTableWidgetItem* Type = new QTableWidgetItem();
        QTableWidgetItem* Power = new QTableWidgetItem();

        Model->setText(model);
        Type->setText(type);
        Power->setText(power);

        ui->tableWidget_engine->setItem(i, 0, Model);
        ui->tableWidget_engine->setItem(i, 1, Type);
        ui->tableWidget_engine->setItem(i, 2, Power);

        i++;
    }
}


void DialogEngine::on_pushButton_sort_power_clicked()
{
    ui->tableWidget_engine->setRowCount(0);
    query->exec("SELECT * FROM Engine ORDER BY Power_ DESC");

    int i = 0;
    while(query->next())
    {
        QString model = query->value(0).toString();
        QString type = query->value(1).toString();
        QString power = query->value(2).toString();

        ui->tableWidget_engine->setRowCount(i + 1);

        QTableWidgetItem* Model = new QTableWidgetItem();
        QTableWidgetItem* Type = new QTableWidgetItem();
        QTableWidgetItem* Power = new QTableWidgetItem();

        Model->setText(model);
        Type->setText(type);
        Power->setText(power);

        ui->tableWidget_engine->setItem(i, 0, Model);
        ui->tableWidget_engine->setItem(i, 1, Type);
        ui->tableWidget_engine->setItem(i, 2, Power);

        i++;
    }
}


void DialogEngine::on_pushButton_search_clicked()
{
    QString model = ui->lineEdit_model->text();
    QString type = ui->lineEdit_type->text();
    ui->tableWidget_engine->setRowCount(0);
    query->prepare("SELECT * FROM Engine WHERE UPPER(Engine_model) like :m AND UPPER(Type_engine) like :t");
    query->bindValue(":m", "%" + model.toUpper() + "%");
    query->bindValue(":t", "%" + type.toUpper() + "%");
    query->exec();

    int i = 0;
    while(query->next())
    {
        QString model = query->value(0).toString();
        QString type = query->value(1).toString();
        QString power = query->value(2).toString();

        ui->tableWidget_engine->setRowCount(i + 1);

        QTableWidgetItem* Model = new QTableWidgetItem();
        QTableWidgetItem* Type = new QTableWidgetItem();
        QTableWidgetItem* Power = new QTableWidgetItem();

        Model->setText(model);
        Type->setText(type);
        Power->setText(power);

        ui->tableWidget_engine->setItem(i, 0, Model);
        ui->tableWidget_engine->setItem(i, 1, Type);
        ui->tableWidget_engine->setItem(i, 2, Power);

        i++;
    }
}

