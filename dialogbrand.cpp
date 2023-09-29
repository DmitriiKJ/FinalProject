#include "dialogbrand.h"
#include "ui_dialogbrand.h"

DialogBrand::DialogBrand(QSqlDatabase &db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogBrand)
{
    ui->setupUi(this);
    addBrand = new DialogAddBrand(db);
    query = new QSqlQuery(db);
}

DialogBrand::~DialogBrand()
{
    delete ui;
    delete query;
    delete addBrand;
}

void DialogBrand::showBrands() const
{
    ui->tableWidget_Brand->setRowCount(0);
    query->exec("SELECT * FROM Brand");

    int i = 0;
    while(query->next())
    {
        QString name = query->value(0).toString();
        QString info = query->value(1).toString();

        ui->tableWidget_Brand->setRowCount(i + 1);

        QTableWidgetItem* Name = new QTableWidgetItem();
        QTableWidgetItem* Info = new QTableWidgetItem();

        Name->setText(name);
        Info->setText(info);

        ui->tableWidget_Brand->setItem(i, 0, Name);
        ui->tableWidget_Brand->setItem(i, 1, Info);

        i++;
    }
}

void DialogBrand::on_pushButton_add_clicked()
{
    addBrand->show();
    this->close();
}


void DialogBrand::on_pushButton_sort_clicked()
{
    ui->tableWidget_Brand->setRowCount(0);
    query->exec("SELECT * FROM Brand ORDER BY Name ASC");

    int i = 0;
    while(query->next())
    {
        QString name = query->value(0).toString();
        QString info = query->value(1).toString();

        ui->tableWidget_Brand->setRowCount(i + 1);

        QTableWidgetItem* Name = new QTableWidgetItem();
        QTableWidgetItem* Info = new QTableWidgetItem();

        Name->setText(name);
        Info->setText(info);

        ui->tableWidget_Brand->setItem(i, 0, Name);
        ui->tableWidget_Brand->setItem(i, 1, Info);

        i++;
    }
}


void DialogBrand::on_pushButton_search_clicked()
{
    ui->tableWidget_Brand->setRowCount(0);
    QString n = ui->lineEdit_name->text();
    query->prepare("SELECT * FROM Brand WHERE UPPER(Name) like :n");
    query->bindValue(":n", "%" + n.toUpper() + "%");
    query->exec();

    int i = 0;
    while(query->next())
    {
        QString name = query->value(0).toString();
        QString info = query->value(1).toString();

        ui->tableWidget_Brand->setRowCount(i + 1);

        QTableWidgetItem* Name = new QTableWidgetItem();
        QTableWidgetItem* Info = new QTableWidgetItem();

        Name->setText(name);
        Info->setText(info);

        ui->tableWidget_Brand->setItem(i, 0, Name);
        ui->tableWidget_Brand->setItem(i, 1, Info);

        i++;
    }
}

