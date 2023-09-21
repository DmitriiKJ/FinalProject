#include "dialogmodel.h"
#include "ui_dialogmodel.h"

DialogModel::DialogModel(QSqlDatabase &db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogModel)
{
    ui->setupUi(this);
    query = new QSqlQuery(db);
    addModel = new DialogAddModel(db);
}

DialogModel::~DialogModel()
{
    delete ui;
    delete query;
    delete addModel;
}

void DialogModel::showModel()
{
    query->exec("SELECT * FROM Model");

    int i = 0;
    while(query->next())
    {
        QString model = query->value(0).toString();
        QString body = query->value(1).toString();
        QString price = query->value(2).toString();
        QString engine = query->value(3).toString();

        ui->tableWidget_model->setRowCount(i + 1);

        QTableWidgetItem *Model = new QTableWidgetItem();
        QTableWidgetItem *Body = new QTableWidgetItem();
        QTableWidgetItem *Price = new QTableWidgetItem();
        QTableWidgetItem *Engine = new QTableWidgetItem();

        Model->setText(model);
        Body->setText(body);
        Price->setText(price);
        Engine->setText(engine);

        ui->tableWidget_model->setItem(i, 0, Model);
        ui->tableWidget_model->setItem(i, 1, Body);
        ui->tableWidget_model->setItem(i, 2, Price);
        ui->tableWidget_model->setItem(i, 3, Engine);

        i++;
    }
}

void DialogModel::on_pushButton_clicked()
{
    addModel->show();
    this->close();
}

