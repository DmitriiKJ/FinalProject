#ifndef DIALOGADDBUY_H
#define DIALOGADDBUY_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlDatabase>

namespace Ui {
class DialogAddBuy;
}

class DialogAddBuy : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddBuy(QSqlDatabase &db, QWidget *parent = nullptr);
    ~DialogAddBuy();

private slots:
    void on_pushButton_add_clicked();

private:
    Ui::DialogAddBuy *ui;
    QSqlQuery *query;
};

#endif // DIALOGADDBUY_H
