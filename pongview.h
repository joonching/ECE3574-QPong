#ifndef PONGVIEW_H
#define PONGVIEW_H


#include <QWidget>
#include <QSize>
#include <QPointF>
#include <QPoint>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QString>
#include <QSet>
#include <QEvent>
#include <QLineF>
#include <QPainter>

#include "intermediate.h"

class pongview : public QWidget
{
    Q_OBJECT
public:
    pongview(QWidget *parent = 0);
    void paint_me(QPainter *painter);
    bool eventFilter(QObject * obj, QEvent *event);
    void choose_dir();
    QPoint get_left_racket();
    QPoint get_right_racket();
    //void get_right_racket();

signals:
    void send_direction(int play_dir);

private:
    QSet<int> pressedKey;
    intermediate *inter;
};


#endif // PONGVIEW_H

