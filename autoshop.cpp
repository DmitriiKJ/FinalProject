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

void AutoShop::add_manager(int i, QString f, QString m, QString l, QString p, QDate d, int e)
{
    Manager* tmp = new Manager(i, f,m,l,p,d,e);
    managers.push_back(tmp);
}

void AutoShop::add_client(int i, QString f, QString m, QString l, QString p, QString a)
{
    Client* tmp = new Client(i, f,m,l,p,a);
    clients.push_back(tmp);
}

void AutoShop::add_car(int i, QString m, QString b, double p, QString em, QString et, int power, Brand br, int year, Manager ma)
{
    Car* tmp = new Car(i, m,b,p,em,et,power,br,year,ma);
    cars.push_back(tmp);
}

void AutoShop::add_brand(QString n, QString i)
{
    Brand* tmp = new Brand(n,i);
    brands.push_back(tmp);
}

void AutoShop::add_buy_from_database(Client c, Car ca, QDate d)
{
    Buy*tmp = new Buy(c, ca, d);
    buys.push_back(tmp);
}

void AutoShop::sort_managers()
{
    std::sort(managers.begin(), managers.end(), sort_manager);
}

void AutoShop::sort_clients()
{
    std::sort(clients.begin(), clients.end(), sort_client);
}

void AutoShop::sort_cars()
{
    std::sort(cars.begin(), cars.end(), sort_car);
}

void AutoShop::sort_brands()
{
    std::sort(brands.begin(), brands.end(), sort_brand);
}

void AutoShop::sort_buys()
{
    std::sort(buys.begin(), buys.end(), sort_buy);
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

bool sort_manager(Manager *left, Manager *right) //сортировка от болешего опыта к меньшему
{
    return left->get_experience() > right->get_experience();
}

bool sort_client(Client *left, Client *right) //сортировка по алфавиту фамилий
{
    return left->get_last_name() < right->get_last_name();
}

bool sort_car(Car *left, Car *right) // сортировка по алфавиту моделей
{
    return left->get_model() < right->get_model();
}

bool sort_brand(Brand *left, Brand *right) // сортировка по алфавиту имени брендов
{
    return left->get_name() < right->get_name();
}

bool sort_buy(Buy *left, Buy *right) // сортировка по дате покупки
{
    return left->get_date() < right->get_date();
}
