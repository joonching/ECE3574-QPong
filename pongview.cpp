#include "pongview.h"
#include <QPainter>
#include <QDebug>


pongview::pongview(QWidget *parent):QWidget(parent)
{
    inter = new intermediate();
    QSize size(900,700);
    setMinimumSize(size);
    setMaximumSize(size);
    setSizePolicy(QSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum));
}

void pongview::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    inter->int_draw(painter);
    update();
}

