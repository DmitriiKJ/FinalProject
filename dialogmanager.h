#ifndef DIALOGMANAGER_H
#define DIALOGMANAGER_H

#include "dialogaddmanager.h"
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDate>
#include "dialogfiremanager.h"
#include "dialogrestoremanager.h"

namespace Ui {
class DialogManager;
}

class DialogManager : public QDialog
{
    Q_OBJECT

public:
    explicit DialogManager(QSqlDatabase &db, QWidget *parent = nullptr);
    ~DialogManager();

    void showMan()const;

private slots:
    void on_pushButton_sort_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_find_clicked();

    void on_pushButton_fire_clicked();

    void on_pushButton_restore_clicked();

    void on_pushButton_fired_clicked();

private:
    Ui::DialogManager *ui;
    DialogAddManager* addManager;
    QSqlQuery* query;
    DialogFireManager *fire;
    DialogRestoreManager *restore;
};

#endif // DIALOGMANAGER_H
