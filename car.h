#ifndef CAR_H
#define CAR_H
#include "brand.h"
#include <QString>
#include "manager.h"

class Car
{
    int ID;
    QString model;
    QString body;
    double price;
    QString engine_model;
    QString engine_type;
    int power; // в лошадиных силах
    Brand brand;
    int year;
    Manager manager;

public:
    Car();
    Car(int i, QString m, QString b, double p, QString em, QString et, int power, Brand br, int year, Manager ma);

    void set_model(QString m);
    void set_body(QString b);
    void set_price(double p);
    void set_engine_model(QString em);
    void set_engine_type(QString et);
    void set_power(int p);
    void set_brand(Brand b);
    void set_year(int y);
    void set_manager(Manager m);

    int get_ID()const;
    QString get_model()const;
    QString get_body()const;
    double get_price()const;
    QString get_engine_model()const;
    QString get_engine_type()const;
    int get_power()const;
    Brand get_brand()const;
    int get_year()const;
    Manager get_manager()const;
};

#endif // CAR_H
