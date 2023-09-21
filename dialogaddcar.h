#ifndef DIALOGADDCAR_H
#define DIALOGADDCAR_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlDatabase>

namespace Ui {
class DialogAddCar;
}

class DialogAddCar : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddCar(QSqlDatabase &db, QWidget *parent = nullptr);
    ~DialogAddCar();

private slots:
    void on_pushButton_add_clicked();

private:
    Ui::DialogAddCar *ui;
    QSqlQuery *query;
};

#endif // DIALOGADDCAR_H
