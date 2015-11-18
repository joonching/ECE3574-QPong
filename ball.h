#ifndef BALL_H
#define BALL_H

#include "base.h"
#include <QPainter>
#include <QPoint>
#include <QWidget>

class ball : public QWidget
{
    Q_OBJECT

public:
    ball(QWidget *parent = 0);
    void draw_me(QPainter *painter);
    void set_points(int x, int y);

private:
    QPoint center_point;
    int px, py;
    int rx, ry;
    bool start;
};


#endif // BALL_H

