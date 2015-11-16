#include "ball.h"
#include <QDebug>
#include <QTimer>

ball::ball(QWidget *parent) : QWidget(parent)
{
    px = 550;
    py = 450;
    center_point = QPoint(px,py);
    rx = 30;
    ry = 30;
    move_up = false;
    move_down = false;
    move_right = true;
    move_left = false;
    start = false;
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
            py = py + 10;
            px = px + 10;
        }

        if(move_left)
        {
            py = py + 10;
            px = px - 10;
        }
    }

    else if(move_up)
    {
        if(move_right)
        {
            py = py - 10;
            px = px + 10;
        }

        if(move_left)
        {
            py = py - 10;
            px = px - 10;
        }
    }

    else
    {
        py = py + 10;
        px = px + 10;
    }
}

void ball::border_height_check(int dir)
{
    if(dir == 0)
    {
        move_down = true;
        move_up = false;
        py = py + 10; //moving down
    }

    if(dir == 1)
    {
        move_up = true;
        move_down = false;
        py = py - 10;
    }

}

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
        px = px + 10;
    }

    if(dir == 5)
    {
        px = px - 10;
    }

    if(move_up)
        border_height_check(1);
    else if(move_down)
        border_height_check(0);
}

QPoint ball::get_points()
{
    QPoint temp = QPoint(px,py);
    return temp;
}

void ball::delay()
{
    qDebug() << "hin";
    start = true;
}

bool ball::set_start()
{
    start = true;
}

void ball::reset()
{
    px = 550;
    py = 450;
    start = false;
    move_up = false;
    move_down = false;
    move_right = true;
    move_left = false;
    center_point = QPoint(px,py);
    QTimer::singleShot(3000, this, SLOT(delay()));
}