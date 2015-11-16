#include "pongview.h"

#include <QDebug>


pongview::pongview(QWidget *parent):QWidget(parent)
{
    this->installEventFilter(this);
    inter = new intermediate();
    QSize size(1100,900);
    setMinimumSize(size);
    setMaximumSize(size);
    setSizePolicy(QSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum));
}

void pongview::paint_me(QPainter *painter)
{
    inter->int_draw(painter);
    update();
}

bool pongview::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        pressedKey += ((QKeyEvent*)event)->key();
        choose_dir();
    }

    else if(event->type()==QEvent::KeyRelease)
    {
        pressedKey -= ((QKeyEvent*)event)->key();
    }
    return false;
}

void pongview::choose_dir()
{
    if(pressedKey.contains(Qt::Key_S)&&pressedKey.contains(Qt::Key_K))
        inter->int_move(7);

    else if(pressedKey.contains(Qt::Key_A)&&pressedKey.contains(Qt::Key_L))
        inter->int_move(6);

    else if(pressedKey.contains(Qt::Key_L)&&pressedKey.contains(Qt::Key_S))
        inter->int_move(5);//player 1 & 2 up

    else if(pressedKey.contains(Qt::Key_K)&&pressedKey.contains(Qt::Key_A))
        inter->int_move(4);//player 1 & 2 down

    else if(pressedKey.contains(Qt::Key_L)) //player 2 up
        inter->int_move(3);

    else if(pressedKey.contains(Qt::Key_K)) //player 2 down
        inter->int_move(2);

    else if(pressedKey.contains(Qt::Key_S)) //player 1 up
        inter->int_move(1);

    else if(pressedKey.contains(Qt::Key_A)) //player 1 down
        inter->int_move(0);
    //have a key_Q so that you can exit..probably create a reset function
}

QPoint pongview::get_left_racket()
{
    return inter->get_left_racket();
}

QPoint pongview::get_right_racket()
{
    return inter->get_right_racket();
}
