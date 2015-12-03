#include "game_engine.h"
#include <QDebug>
#include <QTimer>


game_engine::game_engine(std::mutex &x) : game_safety(x)
{
    use_ball = new ball;
    use_pong = new pongview;
    timer = new QTimer;
    bounced_r = false;
    bounced_l = false;
    left_racket = use_pong->get_left_racket();
    right_racket = use_pong->get_right_racket();
    cur_r_score = 0;
    cur_l_score = 0;

    //***********************
    px = 550;
    py = rand()%(853-20 + 1) + 20;
    ball_speed = rand()%(10-7+1)+7;
    move_left = false;
    move_right = false;
    move_up = false;
    move_down = false;
    start = false;

    //QTimer::singleShot(3000, g_engine, SLOT(delay()));

    //connect(timer, SIGNAL(timeout()), this , SLOT(update_me()));
    //timer->start(17);
}


//0 = hit the top
//1 = hit the botom
//2 = move right
//3 = move left
//4 = bounce off racket
//5 = bounce off racket
//6 = just move it
void game_engine::update_me() //main logic
{
    //my saftey mech
    std::lock_guard<std::mutex> lock(game_safety);
    right_racket = use_pong->get_right_racket();
    left_racket = use_pong->get_left_racket();
    use_ball->set_points(px,py);
    if(start)
    {
        if(py <= 5) //this is the case for when the ball hits the top border
            new_update(0);
        else if(py+30 >= 920) //case for when ball hits bottom border
            new_update(1);

        else if(!bounced_r && px+20 >= right_racket.rx()) //case for right border/racket
            right_bounce(px, py, right_racket);

        else if(!bounced_l && px-20 <= left_racket.rx() + 30) //case for left border/racket
            left_bounce(px,py, left_racket);
        else
            just_move();
    }
}

void game_engine::new_update(int dir)
{
    if(dir == 0 && !move_down)
        border_height_check(dir);

    else  if(dir == 1 && !move_up)
        border_height_check(dir);

    else if(dir == 2 || dir == 3 || dir == 4 || dir == 5)
        border_width_check(dir);
}

void game_engine::border_height_check(int dir)
{
    if(dir == 0)
    {
        move_down = true;
        move_up = false;
        py = py + ball_speed; //moving down
    }

    if(dir == 1)
    {
        move_up = true;
        move_down = false;
        py = py - ball_speed;
    }
}

void game_engine::border_width_check(int dir)
{
    if(dir == 2)
    {
        move_left = true;
        move_right = false;
    }

    if(dir == 3)
    {
        move_right = true;
        move_left = false;
    }

    if(dir == 4)
    {
        px = px + ball_speed;
    }

    if(dir == 5)
    {
        px = px - ball_speed;
    }

    if(move_up)
        border_height_check(1);
    else if(move_down)
        border_height_check(0);
}

//function for right border
void game_engine::right_bounce(int x, int y, QPoint r_point)
{
    //if the ball hits the righ racket
    if(y <= r_point.ry()+150 && y >= r_point.ry() && x+10 <= r_point.rx()+15)
    {
        new_update(2); //hit right racket
        bounced_r = true;
        bounced_l = false;
    }
    //else keep it moving until it reaches the end
    else
    {
        if(x+30 >= 1100)
        {
            reset();
            use_pong->set_ls(++cur_l_score);
            bounced_l = false;
            bounced_r = false;
        }

        else
        {
            new_update(4);
        }
        //its going off the border
    }
}

void game_engine::left_bounce(int x, int y, QPoint l_point)
{
    //if the ball hits the left racket
    if(y <= l_point.ry()+150 && y >= l_point.ry() && x-10 >= l_point.rx()+15)
    {
        new_update(3);
        bounced_l = true;
        bounced_r = false;
    }
    //else keep it moving till it hits the end
    else
    {
        if(x+30 <= 0)
        {
            reset();
            use_pong->set_rs(++cur_r_score);
            bounced_l = false;
            bounced_r = false;
        }
        else
            new_update(5);
    }
}

void game_engine::just_move()
{
    if(move_down)
    {
        if(move_right)
        {
            py = py + ball_speed;
            px = px + ball_speed;
        }

        if(move_left)
        {
            py = py + ball_speed;
            px = px - ball_speed;
        }
    }

    else if(move_up)
    {
        if(move_right)
        {
            py = py - ball_speed;
            px = px + ball_speed;
        }

        if(move_left)
        {
            py = py - ball_speed;
            px = px - ball_speed;
        }
    }
    else
        pick_rand();
}

void game_engine::pick_rand()
{
    int rand_me = rand()%10;
    int rand_2 = rand()%20;
    if(rand_me%2 == 0)
    {
        move_up = true;
        move_down = false;
    }
    else
    {
        move_down = true;
        move_up = false;
    }

    if(rand_2%5 == 0)
    {
        move_left = false;
        move_right = true;
    }
    else
    {
        move_right =false;
        move_left = true;
    }
}

void game_engine::delay()
{
    start = true;
}

void game_engine::get_object(ball *ball_me, pongview* view_me)
{
    use_pong = view_me;
    use_ball = ball_me;
}

void game_engine::reset()
{
    px = 550;
    py = rand()%(853-20 + 1) + 20;
    ball_speed = rand()%(10-7+1)+7;
    move_left = false;
    move_right = false;
    move_up = false;
    move_down = false;
    start = false;
    QTimer::singleShot(3000, this, SLOT(delay()));
}

void game_engine::set_start()
{
    start = true;
}
