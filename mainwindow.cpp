#include <QWidget>
#include "mainwindow.h"


mainwindow::mainwindow(QWidget *parent) : QWidget(parent)
{
    my_pong = new pongview(this);
    QHBoxLayout *layoutH = new QHBoxLayout;

    layoutH->addWidget(my_pong);
    setLayout(layoutH);
}
