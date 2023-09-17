#ifndef DIALOGBRAND_H
#define DIALOGBRAND_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "dialogaddbrand.h"

namespace Ui {
class DialogBrand;
}

class DialogBrand : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBrand(QSqlDatabase &db, QWidget *parent = nullptr);
    ~DialogBrand();

    void showBrands()const;

private slots:
    void on_pushButton_add_clicked();

private:
    Ui::DialogBrand *ui;
    QSqlQuery *query;
    DialogAddBrand *addBrand;
};

#endif // DIALOGBRAND_H
