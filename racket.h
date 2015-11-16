#ifndef RACKET_H
#define RACKET_H

#include "base.h"
#include <QPainter>
#include <QPoint>
class racket : public base
{
public:
    racket();
    virtual void draw(QPainter *painter);
    virtual void move_rackets(int dir);
    virtual QPoint get_left_racket();
    virtual QPoint get_right_racket();

    void move_r(int sign);
    void move_l(int sign);
    void move_both_ud(int sign);
    void move_opposite(int sign);

public slots:
    void move_racket(int dir_play);

private:
    int width, height;
    int left_x, left_y, right_x,right_y;
    int y_range, y_range2;


};

#endif // RACKET_H

