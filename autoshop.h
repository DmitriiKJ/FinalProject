#ifndef AUTOSHOP_H
#define AUTOSHOP_H
#include "brand.h"
#include "car.h"
#include "buy.h"
#include "client.h"
#include "manager.h"
#include <QVector>

class AutoShop
{
    QVector<Manager*> managers;
    QVector<Client*> clients;
    QVector<Car*> cars;
    QVector<Brand*> brands;
    QVector<Buy*> buys;

public:
    AutoShop(); // позже будет загрузка из баззы данных

    // в будущем
    // через интерфейс будет возможность покупки машины(машина удаляется из массива машин и добавляется в покупки) и завоза новых машин
    // добавление клиентов и менеджеров
    // добавление брендов

    QVector<Manager*> get_managers()const;
    QVector<Client*> get_clients()const;
    QVector<Car*> get_cars()const;
    QVector<Brand*> get_brands()const;
    QVector<Buy*> get_buys()const;

    void add_manager(QString f, QString m, QString l, QString p, QDate d, int e);
    void add_client(QString f, QString m, QString l, QString p, QString a);
    void add_car(QString m, QString b, double p, QString em, QString et, int power, Brand br, int year, Manager ma);
    void add_brand(QString n, QString i);
    void add_buy_from_database(Client c, Car ca, QDate d);

    ~AutoShop();
};

#endif // AUTOSHOP_H
