#ifndef DIALOGENGINE_H
#define DIALOGENGINE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "dialogaddengine.h"

namespace Ui {
class DialogEngine;
}

class DialogEngine : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEngine(QSqlDatabase &db, QWidget *parent = nullptr);
    ~DialogEngine();

    void showEngine()const;

private slots:
    void on_pushButton_add_clicked();

private:
    Ui::DialogEngine *ui;
    QSqlQuery *query;
    DialogAddEngine *addEngine;
};

#endif // DIALOGENGINE_H
