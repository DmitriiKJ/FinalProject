#ifndef DIALOGCAR_H
#define DIALOGCAR_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "dialogaddcar.h"

namespace Ui {
class DialogCar;
}

class DialogCar : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCar(QSqlDatabase &db, QWidget *parent = nullptr);
    ~DialogCar();

    void showCar()const;

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_sort_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_year_clicked();

private:
    Ui::DialogCar *ui;
    QSqlQuery *query;
    DialogAddCar *addCar;
};

#endif // DIALOGCAR_H
