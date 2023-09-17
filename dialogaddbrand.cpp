#include "dialogaddbrand.h"
#include "ui_dialogaddbrand.h"

DialogAddBrand::DialogAddBrand(QSqlDatabase &db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddBrand)
{
    ui->setupUi(this);
    query = new QSqlQuery(db);
}

DialogAddBrand::~DialogAddBrand()
{
    delete ui;
    delete query;
}

void DialogAddBrand::on_pushButton_add_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString info = ui->lineEdit_info->text();

    query->prepare("EXEC addBrand :n, :i");
    query->bindValue(":n", name);
    query->bindValue(":i", info);

    if (query->exec()) {
        qDebug() << "Бренд успешно добавлен.";
    }

    ui->lineEdit_name->setText("");
    ui->lineEdit_info->setText("");

    this->close();
}

