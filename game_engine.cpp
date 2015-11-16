#include "game_engine.h"
#include <QDebug>

game_engine::game_engine(QWidget *parent) : QWidget(parent)
{
    use_ball = new ball(this);
    use_pong = new pongview(this);
    bounced_r = false;
    bounced_l = false;
    ball_point = use_ball->get_points();
    left_racket = use_pong->get_left_racket();
    right_racket = use_pong->get_right_racket();
    cur_r_score = 0;
    cur_l_score = 0;

}

void game_engine::update_me() //main logic
{
    ball_point = use_ball->get_points();
    right_racket = use_pong->get_right_racket();
    left_racket = use_pong->get_left_racket();

    if(ball_point.ry() <= 0)
        use_ball->update_me(0);
    else if(ball_point.ry()+30 >= 900)
        use_ball->update_me(1);

    else if(!bounced_r && ball_point.rx()+30 >= right_racket.rx())
        right_bounce(ball_point, right_racket);

    else if(!bounced_l && ball_point.rx()-30 <= left_racket.rx() + 30)
        left_bounce(ball_point, left_racket);
    else
        use_ball->update_me(6);
}

void game_engine::get_object(ball *ball_me, pongview* view_me)
{
    use_pong = view_me;
    use_ball = ball_me;
}

void game_engine::right_bounce(QPoint b_point, QPoint r_point)
{
    if(b_point.ry() <= r_point.ry()+150 && b_point.ry() >= r_point.ry())
    {
        use_ball->update_me(2); //hit right racket
        bounced_r = true;
        bounced_l = false;
    }
    else
    {
        if(b_point.rx()+30 >= 1100)
        {
            use_ball->reset();
            use_pong->set_rs(++cur_r_score);
            bounced_l = false;
            bounced_r = false;
        }

        else
        {
            use_ball->update_me(4);
        }
        //its going off the border
    }
}

void game_engine::left_bounce(QPoint b_point, QPoint l_point)
{
    if(b_point.ry() <= l_point.ry()+150 && b_point.ry() >= l_point.ry())
    {
        use_ball->update_me(3);
        bounced_l = true;
        bounced_r = false;
    }

    else
    {
        if(b_point.rx()+30 <= 0)
        {
            use_ball->reset();
            use_pong->set_ls(++cur_l_score);
            bounced_l = false;
            bounced_r = false;
        }
        else
            use_ball->update_me(5);
    }

}
