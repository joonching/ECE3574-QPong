#include "ball.h"
#include <QDebug>
#include <QTimer>

ball::ball(QWidget *parent) : QWidget(parent)
{
    rx = 15;
    ry = 15;
    start = false;
}

void ball::draw_me(QPainter *painter)
{
    if(!start)
    {
        px = 550;
        py = rand()%(953-20 + 1) + 20;
        start = true;
    }
    center_point= QPoint(px,py);
    painter->setBrush(Qt::white);
    painter->drawEllipse(center_point, rx, ry);
}

void ball::set_points(int x, int y)
{
    px = x;
    py = y;
}
