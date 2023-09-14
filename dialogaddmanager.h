#ifndef DIALOGADDMANAGER_H
#define DIALOGADDMANAGER_H

#include <QDialog>

namespace Ui {
class DialogAddManager;
}

class DialogAddManager : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddManager(QWidget *parent = nullptr);
    ~DialogAddManager();

private:
    Ui::DialogAddManager *ui;
};

#endif // DIALOGADDMANAGER_H
