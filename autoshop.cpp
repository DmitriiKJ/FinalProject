#include "autoshop.h"

AutoShop::AutoShop()
{

}

QVector<Manager *> AutoShop::get_managers() const
{
    return managers;
}

QVector<Client *> AutoShop::get_clients() const
{
    return clients;
}

QVector<Car *> AutoShop::get_cars() const
{
    return cars;
}

QVector<Brand *> AutoShop::get_brands() const
{
    return brands;
}

QVector<Buy *> AutoShop::get_buys() const
{
    return buys;
}
