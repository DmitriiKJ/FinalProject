#include "dialogaddmanager.h"
#include "ui_dialogaddmanager.h"

DialogAddManager::DialogAddManager(QSqlDatabase &db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddManager)
{

    ui->setupUi(this);
    ui->dateEdit_birthday->setMaximumDate(QDate::currentDate().addYears(-18)); // с полнолетия
    query = new QSqlQuery(db);
}

DialogAddManager::~DialogAddManager()
{
    delete ui;
}

void DialogAddManager::on_pushButton_addManager_clicked()
{
    QString first = ui->lineEdit_First->text();
    QString middle = ui->lineEdit_Middle->text();
    QString last = ui->lineEdit_Last->text();
    QString date = ui->dateEdit_birthday->date().toString("yyyy-MM-dd");
    QString phone = ui->lineEdit_Number->text();

    QSqlQuery query;
    query.prepare("EXEC addManager :f, :m, :l, :d, :p");
    query.bindValue(":f", first);
    query.bindValue(":m", middle);
    query.bindValue(":l", last);
    query.bindValue(":d", date);
    query.bindValue(":p", phone);

    if (query.exec()) {
        qDebug() << "Менеджер успешно добавлен.";
    } else {
        qDebug() << "Ошибка SQL: " << query.lastError().text();
                                            qDebug() << "Код ошибки: " << query.lastError().nativeErrorCode();
    }

    this->close();
}

