#ifndef DIALOGCLIENT_H
#define DIALOGCLIENT_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "dialogaddclients.h"

namespace Ui {
class DialogClient;
}

class DialogClient : public QDialog
{
    Q_OBJECT

public:
    explicit DialogClient(QSqlDatabase &db, QWidget *parent = nullptr);
    ~DialogClient();

    void showClient()const;

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogClient *ui;
    QSqlQuery* query;
    DialogAddClients *addClient;
};

#endif // DIALOGCLIENT_H
