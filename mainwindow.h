#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "autoshop.h"
#include "dialogmanager.h"

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

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQuery* query;
    AutoShop shop;
    DialogManager* showManager;
};
#endif // MAINWINDOW_H
