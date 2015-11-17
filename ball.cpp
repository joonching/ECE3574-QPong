#include "ball.h"
#include <QDebug>
#include <QTimer>

ball::ball(QWidget *parent) : QWidget(parent)
{
    px = 550;
    int p_y = rand()%(850-20 + 1) + 20;
    py = p_y;
    center_point = QPoint(px,py);
    rx = 15;
    ry = 15;
    move_up = false;
    move_down = false;
    move_right = false;
    move_left = false;
    start = false;
    int bs = rand()%(40-5 + 1) + 5;
    ball_speed = bs;
}

void ball::draw_me(QPainter *painter)
{
    center_point= QPoint(px,py);
    painter->setBrush(Qt::white);
    painter->drawEllipse(center_point, rx, ry);
}

//0 = hit the top
//1 = hit the botom
//2 = move right
//3 = move left
//4 = bounce off racket
//5 = bounce off racket
//6 = just move it
void ball::update_me(int dir)
{
   if(start)
   {
        if(dir == 0 && !move_down)
            border_height_check(dir);

        else  if(dir == 1 && !move_up)
            border_height_check(dir);

        else if(dir == 2 || dir == 3 || dir == 4 || dir == 5)
            border_width_check(dir);

        else
            just_move();
    }
}

void ball::just_move()
{

    if(move_down)
    {
        if(move_right)
        {
            py = py + ball_speed;
            px = px + ball_speed;
        }

        if(move_left)
        {
            py = py + ball_speed;
            px = px - ball_speed;
        }
    }

    else if(move_up)
    {
        if(move_right)
        {
            py = py - ball_speed;
            px = px + ball_speed;
        }

        if(move_left)
        {
            py = py - ball_speed;
            px = px - ball_speed;
        }
    }

    else
        pick_rand();
}

//check for top hit
void ball::border_height_check(int dir)
{
    if(dir == 0)
    {
        move_down = true;
        move_up = false;
        py = py + ball_speed; //moving down
    }

    if(dir == 1)
    {
        move_up = true;
        move_down = false;
        py = py - ball_speed;
    }

}

//check for side hit
void ball::border_width_check(int dir)
{
    if(dir == 2)
    {
        move_left = true;
        move_right = false;
    }

    if(dir == 3)
    {
        move_right = true;
        move_left = false;
    }

    if(dir == 4)
    {
        px = px + ball_speed;
    }

    if(dir == 5)
    {
        px = px - ball_speed;
    }

    if(move_up)
        border_height_check(1);
    else if(move_down)
        border_height_check(0);
}

void ball::pick_rand()
{
    int rand_me = rand()%10;
    int rand_2 = rand()%20;
    qDebug() << "here\n";
    if(rand_me%2 == 0)
    {
        move_up = true;
        move_down = false;
    }
    else
    {
        move_down = true;
        move_up = false;
    }

    if(rand_2%5 == 0)
    {
        move_left = true;
        move_right = false;
    }
    else
    {
        move_right = true;
        move_left = false;
    }
}

QPoint ball::get_points()
{
    QPoint temp = QPoint(px,py);
    return temp;
}

void ball::delay()
{
    start = true;
}

bool ball::set_start()
{
    start = true;
}

void ball::reset()
{
    px = 550;
    int p_y = rand()%(850-20 + 1) + 20;
    py = p_y;
    int bs = rand()%(40-5 + 1) + 5;
    ball_speed = bs;
    start = false;
    move_up = false;
    move_down = false;
    move_right = false;
    move_left = false;
    center_point = QPoint(px,py);
    QTimer::singleShot(3000, this, SLOT(delay()));
}
