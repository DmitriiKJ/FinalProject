#ifndef DIALOGMANAGER_H
#define DIALOGMANAGER_H

#include "dialogaddmanager.h"
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDate>

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
    void on_pushButton_clicked();

private:
    Ui::DialogManager *ui;
    DialogAddManager* addManager;
    QSqlQuery* query;
};

#endif // DIALOGMANAGER_H
