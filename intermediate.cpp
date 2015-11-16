#include "intermediate.h"
#include <QDebug>
#include <iostream>
intermediate::intermediate()
{
    my_vector.push_back(new background);
    my_vector.push_back(new racket);
}

void intermediate::int_draw(QPainter *painter)
{
    for(int i = 0; i < my_vector.size(); i++)
        my_vector[i]->draw(painter);

}
void intermediate::int_move(int dir)
{
    my_vector[1]->move_rackets(dir);
}

QPoint intermediate::get_left_racket()
{
    return my_vector[1]->get_left_racket();
}

QPoint intermediate::get_right_racket()
{
    return my_vector[1]->get_right_racket();
}

void intermediate::set_ls(int score)
{
    my_vector[0]->set_left_score(score);
}

void intermediate::set_rs(int score)
{
    my_vector[0]->set_right_score(score);
}
