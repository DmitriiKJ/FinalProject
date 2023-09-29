#ifndef DIALOGBUY_H
#define DIALOGBUY_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDate>
#include "dialogaddbuy.h"

namespace Ui {
class DialogBuy;
}

class DialogBuy : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBuy(QSqlDatabase &db, QWidget *parent = nullptr);
    ~DialogBuy();

    void showBuy()const;
private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_sort_clicked();

    void on_pushButton_search_clicked();

private:
    Ui::DialogBuy *ui;
    QSqlQuery *query;
    DialogAddBuy *addBuy;
};

#endif // DIALOGBUY_H
