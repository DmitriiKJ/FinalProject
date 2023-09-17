#include "dialogaddengine.h"
#include "ui_dialogaddengine.h"

DialogAddEngine::DialogAddEngine(QSqlDatabase &db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddEngine)
{
    ui->setupUi(this);
    query = new QSqlQuery(db);
}

DialogAddEngine::~DialogAddEngine()
{
    delete ui;
    delete query;
}

void DialogAddEngine::on_pushButton_clicked()
{
    QString model = ui->lineEdit_model->text();
    QString type = ui->lineEdit_type->text();
    QString power = ui->spinBox_power->text();

    query->prepare("EXEC addEngine :m, :t, :p");
    query->bindValue(":m", model);
    query->bindValue(":t", type);
    query->bindValue(":p", power);

    if (query->exec()) {
        qDebug() << "Двигатель успешно добавлен.";
    }

    ui->lineEdit_model->setText("");
    ui->lineEdit_type->setText("");
    ui->spinBox_power->setValue(1);

    this->close();
}

