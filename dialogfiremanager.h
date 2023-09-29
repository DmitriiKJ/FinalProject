#ifndef DIALOGFIREMANAGER_H
#define DIALOGFIREMANAGER_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlDatabase>

namespace Ui {
class DialogFireManager;
}

class DialogFireManager : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFireManager(QSqlDatabase &db, QWidget *parent = nullptr);
    ~DialogFireManager();

    void update_info();

private slots:
    void on_pushButton_fire_clicked();

private:
    Ui::DialogFireManager *ui;
    QSqlQuery *query;
};

#endif // DIALOGFIREMANAGER_H
