#ifndef MANAGER_H
#define MANAGER_H

#include "human.h"
#include <QDate>

class Manager : public Human
{
    QDate birthday;
    int experience; //опыт работы в годах

public:
    Manager();
    Manager(int i, QString f, QString m, QString l, QString p, QDate d, int e);

    void set_birthday(QDate d);
    void set_experience(int y);

    QDate get_birthday()const;
    int get_experience()const;

    virtual QString type()const override;
};

#endif // MANAGER_H
