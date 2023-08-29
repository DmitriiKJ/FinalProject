#ifndef BUY_H
#define BUY_H
#include "client.h"
#include "car.h"
#include <QDate>

class Buy
{
    Client client;
    Car car;
    QDate date_buy;

public:
    Buy(Client client, Car car, QDate date);

    void set_client(Client c);
    void set_car(Car c);
    void set_date(QDate d);

    Client get_client()const;
    Car get_car()const;
    QDate get_date()const;
};

#endif // BUY_H
