#include "car.h"

Car::Car()
{
    ID = 0;
    model = "Empty";
    body = "Empty";
    price = 0;
    engine_model = "Empty";
    engine_type = "Empty";
    power = 0;
    year = 1;
}

Car::Car(int i, QString m, QString b, double p, QString em, QString et, int power, Brand br, int year, Manager ma)
{
    ID = i;
    set_model(m);
    set_body(b);
    set_price(p);
    set_engine_model(em);
    set_engine_type(et);
    set_power(power);
    set_brand(br);
    set_year(year);
    set_manager(ma);
}

void Car::set_model(QString m)
{
    if(m.isEmpty()) throw ("Model is empty!");
    model = m;
}

void Car::set_body(QString b)
{
    if(b.isEmpty()) throw ("Body type is empty!");
    body = b;
}

void Car::set_price(double p)
{
    if(p < 0) throw ("Error: price!");
    price = p;
}

void Car::set_engine_model(QString em)
{
    if(em.isEmpty()) throw ("Engine model is empty!");
    engine_model = em;
}

void Car::set_engine_type(QString et)
{
    if(et.isEmpty()) throw ("Engine type is empty!");
}

void Car::set_power(int p)
{
    if(p < 0) throw ("Error: power!");
    power = p;
}

void Car::set_brand(Brand b)
{
    brand = b;
}

void Car::set_year(int y)
{
    if(y <= 0) throw ("Error: year!");
}

void Car::set_manager(Manager m)
{
    manager = m;
}

int Car::get_ID() const
{
    return ID;
}

QString Car::get_model() const
{
    return model;
}

QString Car::get_body() const
{
    return body;
}

double Car::get_price() const
{
    return price;
}

QString Car::get_engine_model() const
{
    return engine_model;
}

QString Car::get_engine_type() const
{
    return engine_type;
}

int Car::get_power() const
{
    return power;
}

Brand Car::get_brand() const
{
    return brand;
}

int Car::get_year() const
{
    return year;
}

Manager Car::get_manager() const
{
    return manager;
}
