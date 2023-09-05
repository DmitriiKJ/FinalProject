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
    //query->exec();
}

