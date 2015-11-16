#ifndef INTERMEDIATE_H
#define INTERMEDIATE_H

#include <QVector>
#include <QPainter>
#include <QPoint>
#include "base.h"
#include "racket.h"
#include "background.h"
#include "ball.h"

class intermediate
{
public:
    intermediate();
    void int_draw(QPainter *painter);
    void int_move(int dir);
    QPoint get_left_racket();
    QPoint get_right_racket();


private:
    QVector <base *> my_vector;
};


#endif // INTERMEDIATE_H

