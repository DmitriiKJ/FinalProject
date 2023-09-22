#include "dialogcar.h"
#include "ui_dialogcar.h"

DialogCar::DialogCar(QSqlDatabase &db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCar)
{
    ui->setupUi(this);
    query = new QSqlQuery(db);
    addCar = new DialogAddCar(db);
}

DialogCar::~DialogCar()
{
    delete ui;
    delete query;
    delete addCar;
}

void DialogCar::showCar() const
{
    query->exec("SELECT c.Model, c.Brand, c.Year_, m.First_name, m.Middle_name, m.Last_name FROM Car c JOIN Manager m ON m.ID = c.Manager_ID WHERE c.isSold is null");

    int i = 0;
    while(query->next())
    {
        QString model = query->value(0).toString();
        QString brand = query->value(1).toString();
        QString year = query->value(2).toString();
        QString name = query->value(3).toString() + " " + query->value(4).toString() + " " + query->value(5).toString();

        ui->tableWidget_car->setRowCount(i + 1);

        QTableWidgetItem *Model = new QTableWidgetItem();
        QTableWidgetItem *Brand = new QTableWidgetItem();
        QTableWidgetItem *Year = new QTableWidgetItem();
        QTableWidgetItem *Name = new QTableWidgetItem();

        Model->setText(model);
        Brand->setText(brand);
        Year->setText(year);
        Name->setText(name);

        ui->tableWidget_car->setItem(i, 0, Model);
        ui->tableWidget_car->setItem(i, 1, Brand);
        ui->tableWidget_car->setItem(i, 2, Year);
        ui->tableWidget_car->setItem(i, 3, Name);

        i++;
    }
}

void DialogCar::on_pushButton_clicked()
{
    addCar->show();
    this->close();
}

