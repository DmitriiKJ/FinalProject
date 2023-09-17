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
        showManager = new DialogManager(db);
        showClient = new DialogClient(db);
        showBrand = new DialogBrand(db);
        start();
    }
    else
    {
        ui->statusbar->showMessage("ERROR CONECT");
    }

}

MainWindow::~MainWindow()
{
    delete query;
    delete ui;
    delete showManager;
    delete showClient;
}

void MainWindow::start()
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

    //заполняем класс AutoShop
    query->clear();
    query->exec("SELECT * FROM Brand");
    while(query->next())
    {
        shop.add_brand(query->value(0).toString(), query->value(1).toString());
    }

    query->clear();
    query->exec("SELECT * FROM Manager");
    while(query->next())
    {
        shop.add_manager(query->value(0).toInt(), query->value(1).toString(), query->value(2).toString(), query->value(3).toString(), query->value(4).toString(), query->value(5).toDate(), query->value(6).toInt());
    }

    query->clear();
    query->exec("SELECT * FROM Client");
    while(query->next())
    {
        shop.add_client(query->value(0).toInt(), query->value(1).toString(), query->value(2).toString(), query->value(3).toString(), query->value(4).toString(), query->value(5).toString());
    }

    query->clear();
    query->exec("SELECT * FROM GetCar");
    while(query->next())
    {
        shop.add_car(query->value(0).toInt(), query->value(1).toString(), query->value(2).toString(), query->value(3).toDouble(), query->value(4).toString(), query->value(5).toString(), query->value(6).toInt(), Brand(query->value(7).toString(), query->value(8).toString()), query->value(9).toInt(), Manager(query->value(10).toInt(), query->value(11).toString(), query->value(12).toString(), query->value(13).toString(), query->value(14).toString(), query->value(15).toDate(), query->value(16).toInt()));
    }

    query->clear();
    query->exec("SELECT * FROM GetBuy");
    while(query->next())
    {
        shop.add_buy_from_database(Client(query->value(0).toInt(), query->value(1).toString(), query->value(2).toString(), query->value(3).toString(), query->value(4).toString(), query->value(5).toString()), Car(query->value(6).toInt(), query->value(7).toString(), query->value(8).toString(), query->value(9).toDouble(), query->value(10).toString(), query->value(11).toString(), query->value(12).toInt(), Brand(query->value(13).toString(), query->value(14).toString()), query->value(15).toInt(), Manager(query->value(16).toInt(), query->value(17).toString(), query->value(18).toString(), query->value(19).toString(), query->value(20).toString(), query->value(21).toDate(), query->value(22).toInt())), query->value(23).toDate());
    }
}


void MainWindow::on_actionManagers_triggered()
{
    showManager->show();
    showManager->showMan();
}


void MainWindow::on_actionClients_triggered()
{
    showClient->show();
    showClient->showClient();
}


void MainWindow::on_actionBrands_triggered()
{
    showBrand->show();
    showBrand->showBrands();
}

