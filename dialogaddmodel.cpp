#include "dialogaddmodel.h"
#include "ui_dialogaddmodel.h"

DialogAddModel::DialogAddModel(QSqlDatabase &db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddModel)
{
    ui->setupUi(this);
    query = new QSqlQuery(db);

    query->exec("SELECT Engine_model FROM Engine");
    while(query->next())
    {
        ui->comboBox_engine->addItem(query->value(0).toString());
    }
}

DialogAddModel::~DialogAddModel()
{
    delete ui;
    delete query;
}

void DialogAddModel::on_pushButton_clicked()
{
    QString model = ui->lineEdit_model->text();
    QString body = ui->lineEdit_body->text();
    QString price = ui->doubleSpinBox_price->text();
    QString engine = ui->comboBox_engine->currentText();

    query->clear();
    query->prepare("EXEC addModel :m, :b, :p, :e");
    query->bindValue(":m", model);
    query->bindValue(":b", body);
    query->bindValue(":p", price);
    query->bindValue(":e", engine);

    if(query->exec())
    {
        qDebug() << "Модель успешно добавлена.";
    }

    ui->doubleSpinBox_price->setValue(0);
    ui->lineEdit_model->setText("");
    ui->lineEdit_body->setText("");
    this->close();
}

