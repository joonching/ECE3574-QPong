#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <QWidget>
#include "pongview.h"
#include "ball.h"

class game_engine: public QWidget
{
    Q_OBJECT

public:
    game_engine(QWidget *parent = 0);
    void get_object(ball* ball_me, pongview* view_me);
    void right_bounce(int x, int y, QPoint r_point);
    void left_bounce(int x, int y, QPoint l_point);
    void border_height_check(int dir);
    void border_width_check(int dir);
    void just_move();
    void new_update(int dir);
    void reset();
    void pick_rand();


public slots:
    void update_me();
    void delay();

private:
    ball* use_ball;
    pongview *use_pong;
    bool bounced_r, bounced_l;
    QPoint ball_point;
    QPoint left_racket, right_racket;
    int cur_r_score, cur_l_score;
    int px, py;
    int ball_speed;
    bool move_left, move_right, move_down, move_up;
    bool start;

};

#endif // GAME_ENGINE_H

