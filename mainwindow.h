#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "autoshop.h"
#include "dialogmanager.h"
#include "dialogclient.h"
#include "dialogbrand.h"
#include "dialogengine.h"
#include "dialogmodel.h"
#include "dialogcar.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void start();

private slots:
    void on_actionManagers_triggered();

    void on_actionClients_triggered();

    void on_actionBrands_triggered();

    void on_actionEngines_triggered();

    void on_actionModels_triggered();

    void on_actionCars_triggered();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQuery* query;
    AutoShop shop;
    DialogManager* showManager;
    DialogClient* showClient;
    DialogBrand* showBrand;
    DialogEngine* showEngine;
    DialogModel* showModel;
    DialogCar* showCar;
};
#endif // MAINWINDOW_H
