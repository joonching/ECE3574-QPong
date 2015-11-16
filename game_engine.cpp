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

    if(ball_point.ry() <= 5) //this is the case for when the ball hits the top border
        use_ball->update_me(0);
    else if(ball_point.ry()+30 >= 920) //case for when ball hits bottom border
        use_ball->update_me(1);

    else if(!bounced_r && ball_point.rx()+20 >= right_racket.rx()) //case for right border/racket
        right_bounce(ball_point, right_racket);

    else if(!bounced_l && ball_point.rx()-20 <= left_racket.rx() + 30) //case for left border/racket
        left_bounce(ball_point, left_racket);
    else
        use_ball->update_me(6);
}

void game_engine::get_object(ball *ball_me, pongview* view_me)
{
    use_pong = view_me;
    use_ball = ball_me;
}

//function for right border
void game_engine::right_bounce(QPoint b_point, QPoint r_point)
{
    //if the ball hits the righ racket
    if(b_point.ry() <= r_point.ry()+150 && b_point.ry() >= r_point.ry())
    {
        qDebug() << "hit -- " << b_point.rx()+10 << "=" << r_point.rx() << "\n";
        use_ball->update_me(2); //hit right racket
        bounced_r = true;
        bounced_l = false;
    }
    //else keep it moving until it reaches the end
    else
    {
        if(b_point.rx()+30 >= 1100)
        {
            use_ball->reset();
            use_pong->set_rs(++cur_l_score);
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
    //if the ball hits the left racket
    if(b_point.ry() <= l_point.ry()+150 && b_point.ry() >= l_point.ry())
    {
        use_ball->update_me(3);
        bounced_l = true;
        bounced_r = false;
    }
    //else keep it moving till it hits the end
    else
    {
        if(b_point.rx()+30 <= 0)
        {
            use_ball->reset();
            use_pong->set_ls(++cur_r_score);
            bounced_l = false;
            bounced_r = false;
        }
        else
            use_ball->update_me(5);
    }

}
