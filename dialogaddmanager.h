#ifndef DIALOGADDMANAGER_H
#define DIALOGADDMANAGER_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>

namespace Ui {
class DialogAddManager;
}

class DialogAddManager : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddManager(QSqlDatabase &db, QWidget *parent = nullptr);
    ~DialogAddManager();

private slots:
    void on_pushButton_addManager_clicked();

private:
    Ui::DialogAddManager *ui;
    QSqlQuery* query;
};

#endif // DIALOGADDMANAGER_H
