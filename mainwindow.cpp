#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Connect
    db = QSqlDatabase::addDatabase("QODBC");

    QString connectString = "Driver={SQL Server};";
    connectString.append("Server=DESKTOP-QDVET6F\\SQLEXPRESS;");
    connectString.append("Database=AutoShop;");
    db.setDatabaseName(connectString);

    if(db.open())
    {
        ui->statusbar->showMessage("CONECT");
        query = new QSqlQuery(db);
        show_cars();
    }
    else
    {
        ui->statusbar->showMessage("ERROR CONECT");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_cars() const
{
    query->exec("SELECT m.Body, m.Price, e.Type_engine, e.Power_, c.Brand, c.Year_, g.Last_name + ' ' + g.First_name + ' ' + g.Middle_name as 'Full name manager' FROM Car c JOIN Model m ON c.Model = m.Model JOIN Manager g ON c.Manager_ID = g.ID JOIN Engine e ON m.Engine_model = e.Engine_model");

    int i = 0;
    while(query->next())
    {
        QString body = query->value(0).toString();
        QString price = query->value(1).toString();
        QString type = query->value(2).toString();
        QString power = query->value(3).toString();
        QString brand = query->value(4).toString();
        QString year = query->value(5).toString();
        QString name = query->value(6).toString();

        ui->tableWidget_Car->setRowCount(i + 1);

        QTableWidgetItem* Body = new QTableWidgetItem();
        QTableWidgetItem* Price = new QTableWidgetItem();
        QTableWidgetItem* Type = new QTableWidgetItem();
        QTableWidgetItem* Power = new QTableWidgetItem();
        QTableWidgetItem* Brand = new QTableWidgetItem();
        QTableWidgetItem* Year = new QTableWidgetItem();
        QTableWidgetItem* Name = new QTableWidgetItem();

        Body->setText(body);
        Price->setText(price);
        Type->setText(type);
        Power->setText(power);
        Brand->setText(brand);
        Year->setText(year);
        Name->setText(name);

        ui->tableWidget_Car->setItem(i, 0, Body);
        ui->tableWidget_Car->setItem(i, 1, Price);
        ui->tableWidget_Car->setItem(i, 2, Type);
        ui->tableWidget_Car->setItem(i, 3, Power);
        ui->tableWidget_Car->setItem(i, 4, Brand);
        ui->tableWidget_Car->setItem(i, 5, Year);
        ui->tableWidget_Car->setItem(i, 6, Name);

        i++;
    }
}

