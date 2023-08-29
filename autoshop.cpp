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

AutoShop::~AutoShop()
{
    for(int i = 0; i < buys.size(); i++)
    {
        delete buys[i];
    }

    for(int i = 0; i < cars.size(); i++)
    {
        delete cars[i];
    }

    for(int i = 0; i < brands.size(); i++)
    {
        delete brands[i];
    }

    for(int i = 0; i < managers.size(); i++)
    {
        delete managers[i];
    }

    for(int i = 0; i < clients.size(); i++)
    {
        delete clients[i];
    }
}
