#include <QWidget>
#include "mainwindow.h"
#include <QApplication>


mainwindow::mainwindow(QWidget *parent) :
    QWidget(parent),
    create_thread(this)
{
    my_pong = new pongview(this);
    my_ball = new ball(this);
    timer = new QTimer(this);
    //my safety mech
    g_engine = new game_engine(safety);


    QHBoxLayout *layoutH = new QHBoxLayout;
    installEventFilter(my_pong);

    QTimer::singleShot(3000, g_engine, SLOT(delay()));
    connect(timer, SIGNAL(timeout()), g_engine , SLOT(update_me()));
    timer->start(17);
    connect(&create_thread, SIGNAL(finished()), g_engine, SLOT(deleteLater()));

    layoutH->addWidget(my_pong);
    layoutH->setAlignment(Qt::AlignHCenter);
    setLayout(layoutH);
}

void mainwindow::paintEvent(QPaintEvent *event)
{
    //my safety mech

    QPainter *painter = new QPainter(this);
    my_pong->paint_me(painter);
    my_ball->draw_me(painter);

    update();
}

void mainwindow::quit()
{
    this->quit();
}

