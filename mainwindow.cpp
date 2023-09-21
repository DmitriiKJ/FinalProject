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
        showEngine = new DialogEngine(db);
        showModel = new DialogModel(db);
        showCar = new DialogCar(db);
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
    delete showBrand;
    delete showEngine;
    delete showModel;
    delete showCar;
}

void MainWindow::start()
{
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


void MainWindow::on_actionEngines_triggered()
{
    showEngine->show();
    showEngine->showEngine();
}


void MainWindow::on_actionModels_triggered()
{
    showModel->show();
    showModel->showModel();
}


void MainWindow::on_actionCars_triggered()
{
    showCar->show();
    showCar->showCar();
}

