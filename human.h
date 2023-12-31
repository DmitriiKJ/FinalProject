#ifndef HUMAN_H
#define HUMAN_H
#include <QString>

class Human
{
protected:
    //Общие поля для наследников этого класса (Менеджер, Клиент)
    int ID;
    QString first_name;
    QString middle_name;
    QString last_name;
    QString phone_number;
public:
    Human();
    Human(int i,QString f, QString m, QString l, QString p);

    void set_first_name(QString n);
    void set_middle_name(QString n);
    void set_last_name(QString n);
    void set_phone_number(QString n);

    int get_ID()const;
    QString get_first_name()const;
    QString get_middle_name()const;
    QString get_last_name()const;
    QString get_phone_number()const;

    //Чисто виртуальный метод
    virtual QString type()const = 0;
    virtual ~Human();
};

#endif // HUMAN_H
