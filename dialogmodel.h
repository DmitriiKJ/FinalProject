#ifndef DIALOGMODEL_H
#define DIALOGMODEL_H

#include <QDialog>
#include <QSqlQuery>>
#include <QSqlDatabase>
#include "dialogaddmodel.h"

namespace Ui {
class DialogModel;
}

class DialogModel : public QDialog
{
    Q_OBJECT

public:
    explicit DialogModel(QSqlDatabase &db, QWidget *parent = nullptr);
    ~DialogModel();

    void showModel()const;

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_sort_clicked();

    void on_pushButton_price_clicked();

    void on_pushButton_search_clicked();

private:
    Ui::DialogModel *ui;
    QSqlQuery *query;
    DialogAddModel *addModel;
};

#endif // DIALOGMODEL_H
