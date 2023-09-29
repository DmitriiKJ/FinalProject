#include "dialogbuy.h"
#include "ui_dialogbuy.h"

DialogBuy::DialogBuy(QSqlDatabase &db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogBuy)
{
    ui->setupUi(this);
    query = new QSqlQuery(db);
    addBuy = new DialogAddBuy(db);
    ui->tableWidget_buy->setColumnWidth(0, 200);
    ui->tableWidget_buy->setColumnWidth(1, 200);
    ui->tableWidget_buy->setColumnWidth(2, 200);

}

DialogBuy::~DialogBuy()
{
    delete ui;
    delete query;
    delete addBuy;
}

void DialogBuy::showBuy() const
{
    query->exec("SELECT c.First_name + ' ' + c.Middle_name + ' ' + c.Last_name, cr.Model + ' ' + Cast(cr.Year_ as nvarchar(10)), b.Date_buy  FROM Buy b JOIN Client c ON c.ID = b.Client_ID JOIN Car cr ON cr.ID = b.Car_ID");

    int i = 0;
    while(query->next())
    {
        QString name = query->value(0).toString();
        QString model_year = query->value(1).toString();
        QDate date = query->value(2).toDate();

        ui->tableWidget_buy->setRowCount(i + 1);

        QTableWidgetItem* Name = new QTableWidgetItem();
        QTableWidgetItem* Model_year = new QTableWidgetItem();
        QTableWidgetItem* Date = new QTableWidgetItem();

        Name->setText(name);
        Model_year->setText(model_year);
        Date->setText(date.toString());

        ui->tableWidget_buy->setItem(i, 0, Name);
        ui->tableWidget_buy->setItem(i, 1, Model_year);
        ui->tableWidget_buy->setItem(i, 2, Date);

        i++;
    }
}

void DialogBuy::on_pushButton_add_clicked()
{
    addBuy->show();
    this->close();
}


void DialogBuy::on_pushButton_sort_clicked()
{
    ui->tableWidget_buy->setRowCount(0);
    query->exec("SELECT c.First_name + ' ' + c.Middle_name + ' ' + c.Last_name, cr.Model + ' ' + Cast(cr.Year_ as nvarchar(10)), b.Date_buy  FROM Buy b JOIN Client c ON c.ID = b.Client_ID JOIN Car cr ON cr.ID = b.Car_ID ORDER BY b.Date_buy DESC");

    int i = 0;
    while(query->next())
    {
        QString name = query->value(0).toString();
        QString model_year = query->value(1).toString();
        QDate date = query->value(2).toDate();

        ui->tableWidget_buy->setRowCount(i + 1);

        QTableWidgetItem* Name = new QTableWidgetItem();
        QTableWidgetItem* Model_year = new QTableWidgetItem();
        QTableWidgetItem* Date = new QTableWidgetItem();

        Name->setText(name);
        Model_year->setText(model_year);
        Date->setText(date.toString());

        ui->tableWidget_buy->setItem(i, 0, Name);
        ui->tableWidget_buy->setItem(i, 1, Model_year);
        ui->tableWidget_buy->setItem(i, 2, Date);

        i++;
    }
}


void DialogBuy::on_pushButton_search_clicked()
{
    ui->tableWidget_buy->setRowCount(0);
    QString l = ui->lineEdit_last->text();
    query->prepare("SELECT c.First_name + ' ' + c.Middle_name + ' ' + c.Last_name, cr.Model + ' ' + Cast(cr.Year_ as nvarchar(10)), b.Date_buy  FROM Buy b JOIN Client c ON c.ID = b.Client_ID JOIN Car cr ON cr.ID = b.Car_ID WHERE UPPER(c.Last_name) like :l");
    query->bindValue(":l", "%" + l.toUpper() + "%");
    query->exec();

    int i = 0;
    while(query->next())
    {
        QString name = query->value(0).toString();
        QString model_year = query->value(1).toString();
        QDate date = query->value(2).toDate();

        ui->tableWidget_buy->setRowCount(i + 1);

        QTableWidgetItem* Name = new QTableWidgetItem();
        QTableWidgetItem* Model_year = new QTableWidgetItem();
        QTableWidgetItem* Date = new QTableWidgetItem();

        Name->setText(name);
        Model_year->setText(model_year);
        Date->setText(date.toString());

        ui->tableWidget_buy->setItem(i, 0, Name);
        ui->tableWidget_buy->setItem(i, 1, Model_year);
        ui->tableWidget_buy->setItem(i, 2, Date);

        i++;
    }
}

