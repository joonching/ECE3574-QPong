#include "ball.h"
#include <QDebug>
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
//5 = just move it
void ball::update_me(int dir)
{
    if(dir == 0 && !move_down)
        border_height_check(dir);

    else  if(dir == 1 && !move_up)
        border_height_check(dir);

    else if(dir == 2)
        border_width_check(dir);

    else if(dir == 3)
        border_width_check(dir);
    else
        just_move();
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
        qDebug() << "inside\n";
        move_right = true;
        move_left = false;
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
