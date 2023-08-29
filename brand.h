#ifndef BRAND_H
#define BRAND_H
#include <QString>

class Brand
{
    QString name;
    QString info;
public:
    Brand();
    Brand(QString n, QString i);

    void set_name(QString n);
    void set_info(QString i);

    QString get_name()const;
    QString get_info()const;
};

#endif // BRAND_H
