#ifndef CLIENT_H
#define CLIENT_H

#include "human.h"

class Client : public Human
{
    QString address;
public:
    Client();
    Client(QString f, QString m, QString l, QString p, QString a);

    void set_address(QString a);

    QString get_address()const;

    virtual QString type()const override;
};

#endif // CLIENT_H
