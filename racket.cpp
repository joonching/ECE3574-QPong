#include "racket.h"
#include <QDebug>

racket::racket()
{
    width = 30;
    height = 150;
    left_x = 10;
    left_y = 300;
    right_x = 1065;
    right_y = 300;
    y_range = 735;
    y_range2 = 10;
}

void racket::draw(QPainter *painter)
{
    painter->setPen(Qt::white);
    painter->drawRect(left_x,left_y,width,height); //left
    painter->drawRect(right_x,right_y,width,height); //right
}

//0 = player 1 down
//1 = player 1 up
//2 = player 2 down
//3 = player 2 up
//4 = player 1 & 2 down
//5 = player 1 & 2 up
//6 = player 1 down & player 2 up
//7 = player 1 up & player 2 down
void racket::move_rackets(int dir_play)
{
    if(dir_play == 0)
        move_l(0);

    if(dir_play == 1) //up player 1
        move_l(1);

    if(dir_play == 2)
        move_r(0);

    if(dir_play == 3) //up player 2
        move_r(1);

    if(dir_play == 4)
        move_both_ud(0); //move it down

    if(dir_play == 5)
        move_both_ud(1); //move both up

    if(dir_play == 6)
        move_opposite(1); //p1 down p2 up

    if(dir_play == 7)
        move_opposite(0); //p1 up p2 down
}

//0 = +
//1 = -
void racket::move_r(int sign) //player 2
{
    if(sign == 0 && right_y < y_range)
    {
        right_y = right_y + 10;
    }

    else if(sign == 1 && right_y > y_range2)
    {
        right_y = right_y - 10;
    }
}

//0 = +
//1 = -
void racket::move_l(int sign) //player 1
{
    //qDebug() << "movel\n";
    if(sign == 0 && left_y < y_range)
    {
        left_y = left_y + 10;
    }

    else if(sign == 1 && left_y > y_range2)
    {
        left_y = left_y - 10;
    }
}


void racket::move_both_ud(int sign)
{
    //qDebug() << "moveboth\n";
    if(sign == 0)
    {
        if(right_y < y_range && left_y < y_range)
        {
            right_y = right_y + 10;
            left_y = left_y + 10;
        }
        else if(right_y < y_range)
        {
            right_y = right_y + 10;
        }

        else if(left_y < y_range)
            left_y = left_y + 10;
    }

    else if(sign == 1)
    {
        if(right_y > y_range2 && left_y > y_range2)
        {
            right_y = right_y - 10;
            left_y = left_y - 10;
        }
        else if(right_y > y_range2)
        {
            right_y = right_y - 10;
        }

        else if(left_y > y_range2)
            left_y = left_y - 10;
    }
}

//0 = p1 up p2 down
//1 = p1 down p2 up
void racket::move_opposite(int sign)
{
    if(sign == 0)
    {
        //qDebug() << "here\n";
        if(left_y > y_range2 && right_y < y_range)
        {
            left_y = left_y - 10;
            right_y = right_y + 10;
        }

        else if(left_y > y_range2)
            left_y = left_y - 10;

        else if(right_y < y_range)
            right_y = right_y + 10;
    }

    else if(sign == 1)
    {
        if(right_y > y_range2 && left_y < y_range)
        {
            right_y = right_y - 10;
            left_y = left_y + 10;
        }

        else if(right_y > y_range2)
            right_y = right_y - 10;

        else if(left_y < y_range)
            left_y = left_y + 10;
    }

}

QPoint racket::get_left_racket()
{
    return QPoint(left_x, left_y);
}

QPoint racket::get_right_racket()
{
    return QPoint(right_x, right_y);
}
