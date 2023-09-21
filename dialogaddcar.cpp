#include "dialogaddcar.h"
#include "ui_dialogaddcar.h"

DialogAddCar::DialogAddCar(QSqlDatabase &db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddCar)
{
    ui->setupUi(this);
    query = new QSqlQuery(db);
    query->exec("SELECT Model FROM Model");
    while(query->next())
    {
        ui->comboBox_model->addItem(query->value(0).toString());
    }

    query->clear();
    query->exec("SELECT Name FROM Brand");
    while(query->next())
    {
        ui->comboBox_brand->addItem(query->value(0).toString());
    }

    query->clear();
    query->exec("SELECT Phone_number, First_name + ' ' + Middle_name + ' ' + Last_name FROM Manager");
    while(query->next())
    {
        ui->comboBox_manager->addItem(query->value(1).toString(), query->value(0));
    }
}

DialogAddCar::~DialogAddCar()
{
    delete ui;
    delete query;
}

void DialogAddCar::on_pushButton_add_clicked()
{
    QString model = ui->comboBox_model->currentText();
    QString brand = ui->comboBox_brand->currentText();
    QString year = ui->spinBox_year->text();
    QString manager = ui->comboBox_manager->currentData().toString();

    query->clear();
    query->prepare("EXEC addCar :m, :n, :y, :b");
    query->bindValue(":m", model);
    query->bindValue(":n", manager);
    query->bindValue(":y", year);
    query->bindValue(":b", brand);

    if(query->exec())
    {
        qDebug() << "Машина успешно добавлена.";
    }

    this->close();
}

