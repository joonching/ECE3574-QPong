#ifndef BASE_H
#define BASE_H

#include <QPainter>

class base
{
public:
    base(){}
    virtual void draw(QPainter* painter) = 0;

};

#endif // BASE_H

