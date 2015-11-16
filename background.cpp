#include "background.h"

background::background()
{
    width = 1100;
    height = 900;
    left_score = 0;
    left = QString::number(left_score);
    right_score = 0;
    right = QString::number(right_score);
    text_left = QPointF((width/2)- 40,30);
    text_right = QPointF((width/2)+ 20,30);
}

void background::draw(QPainter *painter)
{
    painter->fillRect(0,0,width, height, QBrush(Qt::black,Qt::SolidPattern));
    painter->drawRect(0,0,width,height);
    painter->setPen(Qt::white);
    painter->drawLine(width/2,0,width/2,height);
    painter->drawText(text_left, left);
    painter->drawText(text_right, right);
}

void background::set_left_score(int score)
{
    left_score = score;
    left = QString::number(left_score);
}

void background::set_right_score(int score)
{
    right_score = score;
    right = QString::number(right_score);
}
