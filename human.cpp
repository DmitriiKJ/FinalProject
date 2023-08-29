#include "human.h"

Human::Human()
{
    first_name = "Empty";
    middle_name = "Empty";
    last_name = "Empty";
    phone_number = "Empty";
}

Human::Human(QString f, QString m, QString l, QString p)
{
    set_first_name(f);
    set_middle_name(m);
    set_last_name(l);
    set_phone_number(p);
}

void Human::set_first_name(QString n)
{
    if(n.size() == 0) throw ("First name is empty!");
    first_name = n;
}

void Human::set_middle_name(QString n)
{
    if(n.size() == 0) throw ("Middle name is empty!");
    middle_name = n;
}

void Human::set_last_name(QString n)
{
    if(n.size() == 0) throw ("Last name is empty!");
    last_name = n;
}

void Human::set_phone_number(QString n)
{
    if(n.size() == 0) throw ("Phone number is empty!");
    phone_number= n;
}

QString Human::get_first_name() const
{
    return first_name;
}

QString Human::get_middle_name() const
{
    return middle_name;
}
QString Human::get_last_name() const
{
    return last_name;
}

QString Human::get_phone_number() const
{
    return phone_number;
}
