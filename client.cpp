#include "client.h"

Client::Client()
{
    address = "Empty";
}

Client::Client(QString f, QString m, QString l, QString p, QString a):Human(f, m, l, p)
{
    address= a;
}

void Client::set_address(QString a)
{
    if(a.size()==0) throw ("Address is empty!");
    address = a;
}

QString Client::get_address() const
{
    return address;
}

QString Client::type() const
{
    return "Client";
}
