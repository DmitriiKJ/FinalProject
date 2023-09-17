#ifndef DIALOGADDBRAND_H
#define DIALOGADDBRAND_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlDatabase>

namespace Ui {
class DialogAddBrand;
}

class DialogAddBrand : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddBrand(QSqlDatabase &db, QWidget *parent = nullptr);
    ~DialogAddBrand();

private slots:
    void on_pushButton_add_clicked();

private:
    Ui::DialogAddBrand *ui;
    QSqlQuery *query;
};

#endif // DIALOGADDBRAND_H
