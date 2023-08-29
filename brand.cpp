#include "brand.h"

Brand::Brand()
{
    name = "Empty";
    info = "Empty";
}

Brand::Brand(QString n, QString i)
{
    set_name(n);
    set_info(i);
}

void Brand::set_name(QString n)
{
    if(n.isEmpty())  throw ("Name is empty!");
    name = n;
}

void Brand::set_info(QString i)
{
    if(i.isEmpty()) throw ("Info is empty");
    info = i;
}

QString Brand::get_name() const
{
    return name;
}

QString Brand::get_info() const
{
    return info;
}
