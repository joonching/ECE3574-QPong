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
    void right_bounce(QPoint b_point, QPoint r_point);
    void left_bounce(QPoint b_point, QPoint l_point);

public slots:
    void update_me();

private:
    ball* use_ball;
    pongview *use_pong;
    bool bounced_r, bounced_l;
    QPoint ball_point;
    QPoint left_racket, right_racket;
    int cur_r_score, cur_l_score;
};

#endif // GAME_ENGINE_H

