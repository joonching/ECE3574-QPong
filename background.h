#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "base.h"
#include <QBrush>
#include <QPointF>
#include <QString>
#include <QPoint>


class background : public base
{
public:
    background();
    virtual void draw(QPainter *painter);
    virtual void move_rackets(int dir){}
    virtual QPoint get_left_racket(){}
    virtual QPoint get_right_racket(){}

private:
    int width, height;
    int left_score, right_score;
    QString left, right;
    QPointF text_left, text_right;
};

#endif // BACKGROUND_H

