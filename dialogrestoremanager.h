#ifndef DIALOGRESTOREMANAGER_H
#define DIALOGRESTOREMANAGER_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlDatabase>

namespace Ui {
class DialogRestoreManager;
}

class DialogRestoreManager : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRestoreManager(QSqlDatabase &db, QWidget *parent = nullptr);
    ~DialogRestoreManager();

    void update_info();

private slots:
    void on_pushButton_restore_clicked();

private:
    Ui::DialogRestoreManager *ui;
    QSqlQuery *query;
};

#endif // DIALOGRESTOREMANAGER_H
