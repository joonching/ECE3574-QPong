#ifndef BASE_H
#define BASE_H

#include <QPainter>
#include <QPoint>
class base
{
public:
    base(){}
    virtual void draw(QPainter* painter) = 0;
    virtual void move_rackets(int dir) = 0;
    virtual QPoint get_left_racket() = 0;
    virtual QPoint get_right_racket() = 0;
};

#endif // BASE_H

