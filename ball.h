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
    void border_height_check(int dir);
    void border_width_check(int dir);
    void just_move();
    void update_me(int dir);
    QPoint get_points();

private:
    QPoint center_point;
    int px, py;
    int rx, ry;
    int move_x, move_y;
    bool move_down, move_up, move_right, move_left;
};


#endif // BALL_H

