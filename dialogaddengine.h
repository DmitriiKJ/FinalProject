#ifndef DIALOGADDENGINE_H
#define DIALOGADDENGINE_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlDatabase>

namespace Ui {
class DialogAddEngine;
}

class DialogAddEngine : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddEngine(QSqlDatabase &db, QWidget *parent = nullptr);
    ~DialogAddEngine();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogAddEngine *ui;
    QSqlQuery *query;
};

#endif // DIALOGADDENGINE_H
