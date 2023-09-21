#ifndef DIALOGADDMODEL_H
#define DIALOGADDMODEL_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlDatabase>

namespace Ui {
class DialogAddModel;
}

class DialogAddModel : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddModel(QSqlDatabase &db, QWidget *parent = nullptr);
    ~DialogAddModel();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogAddModel *ui;
    QSqlQuery *query;
};

#endif // DIALOGADDMODEL_H
