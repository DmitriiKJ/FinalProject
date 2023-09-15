#ifndef DIALOGADDCLIENTS_H
#define DIALOGADDCLIENTS_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlDatabase>

namespace Ui {
class DialogAddClients;
}

class DialogAddClients : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddClients(QSqlDatabase &db, QWidget *parent = nullptr);
    ~DialogAddClients();

private slots:
    void on_pushButto_add_clicked();

private:
    Ui::DialogAddClients *ui;
    QSqlQuery* query;
};

#endif // DIALOGADDCLIENTS_H
