#include "buy.h"

Buy::Buy(Client client, Car car, QDate date)
{
    this->client = client;
    this->car = car;
    set_date(date);
}

void Buy::set_client(Client c)
{
    client = c;
}

void Buy::set_car(Car c)
{
    car = c;
}

void Buy::set_date(QDate d)
{
    if(d > QDate::currentDate()) throw ("Error: date!"); // дата из будущего
    date_buy = d;
}

Client Buy::get_client() const
{
    return client;
}

Car Buy::get_car() const
{
    return car;
}

QDate Buy::get_date() const
{
    return date_buy;
}
