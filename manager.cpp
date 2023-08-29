#include "manager.h"

Manager::Manager()
{
    birthday = QDate::currentDate().addYears(-18); // возвращает текущюю дату -18 лет (Учитывается работа с полнолетия)
    experience = 0;
}

Manager::Manager(QString f, QString m, QString l, QString p, QDate d, int e):Human(f, m, l, p)
{

}

void Manager::set_birthday(QDate d)
{
    if(d > QDate::currentDate().addYears(-18)) throw ("You are too young!");
    birthday = d;
    experience = QDate::currentDate().addYears(-18).year(); // если все написано правильно, то устанавливается максимальный возможный опыт учитывая полнолетие
}

void Manager::set_experience(int y)
{
    if(y > QDate::currentDate().year() - birthday.year() - 18) throw ("Too much experience for that age!"); // проверка на количество опыта для возраста (работа с полнолетия)
    experience = y;
}

QDate Manager::get_birthday() const
{
    return birthday;
}

int Manager::get_experience() const
{
    return experience;
}

QString Manager::type() const
{
    return "Manager";
}
