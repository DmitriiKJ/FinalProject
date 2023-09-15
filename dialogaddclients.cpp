#include "dialogaddclients.h"
#include "ui_dialogaddclients.h"

DialogAddClients::DialogAddClients(QSqlDatabase &db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddClients)
{
    ui->setupUi(this);
    query = new QSqlQuery(db);
}

DialogAddClients::~DialogAddClients()
{
    delete ui;
    delete query;
}

void DialogAddClients::on_pushButto_add_clicked()
{
    QString first = ui->lineEdit_first->text();
    QString middle = ui->lineEdit_middle->text();
    QString last = ui->lineEdit_last->text();
    QString number = ui->lineEdit_number->text();
    QString address = ui->lineEdit_address->text();

    query->prepare("EXEC addClient :f, :m, :l, :n, :a");
    query->bindValue(":f", first);
    query->bindValue(":m", middle);
    query->bindValue(":l", last);
    query->bindValue(":n", number);
    query->bindValue(":a", address);

    if (query->exec()) {
        qDebug() << "Клиент успешно добавлен.";
    }

    ui->lineEdit_first->setText("");
    ui->lineEdit_middle->setText("");
    ui->lineEdit_last->setText("");
    ui->lineEdit_number->setText("");
    ui->lineEdit_address->setText("");
    this->close();
}

