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

}

void game_engine::update_me()
{
    ball_point = use_ball->get_points();
    right_racket = use_pong->get_right_racket();
    left_racket = use_pong->get_left_racket();


    if(ball_point.ry() <= 0)
        use_ball->update_me(0);
    else if(ball_point.ry()+30 >= 900)
        use_ball->update_me(1);
    else if(!bounced_r && ball_point.rx()+30 >= right_racket.rx())
    {
        if(ball_point.ry() <= right_racket.ry()+150 && ball_point.ry() >= right_racket.ry())
        {
            use_ball->update_me(2); //hit right racket
            bounced_r = true;
            bounced_l = false;
        }
        else
        {
            //its going off the border
        }
    }

    else if(!bounced_l && ball_point.rx()-30 <= left_racket.rx() + 30)
    {
        qDebug() << "1\n";
        if(ball_point.ry() <= left_racket.ry()+150 && ball_point.ry() >= left_racket.ry())
        {
            qDebug() << "2\n";
            use_ball->update_me(3);
            bounced_l = true;
            bounced_r = false;
        }
    }
    else
        use_ball->update_me(5);
}

void game_engine::get_object(ball *ball_me, pongview* view_me)
{
    use_pong = view_me;
    use_ball = ball_me;
}
