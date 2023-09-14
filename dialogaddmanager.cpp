#include "dialogaddmanager.h"
#include "ui_dialogaddmanager.h"

DialogAddManager::DialogAddManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddManager)
{
    ui->setupUi(this);
}

DialogAddManager::~DialogAddManager()
{
    delete ui;
}
