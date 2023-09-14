#ifndef DIALOGMANAGER_H
#define DIALOGMANAGER_H
#include <autoshop.h>

#include <QDialog>

namespace Ui {
class DialogManager;
}

class DialogManager : public QDialog
{
    Q_OBJECT

public:
    explicit DialogManager(QWidget *parent = nullptr);
    ~DialogManager();

    void showMan(AutoShop shop)const;

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogManager *ui;
};

#endif // DIALOGMANAGER_H
