#ifndef PONGVIEW_H
#define PONGVIEW_H


#include <QWidget>
#include <QSize>
#include <QPointF>
#include <QPoint>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QString>
#include <QLineF>

#include "intermediate.h"

class pongview : public QWidget
{
    Q_OBJECT
public:
    pongview(QWidget *parent = 0);
    void paintEvent(QPaintEvent * event);

private:
    intermediate *inter;
};


#endif // PONGVIEW_H

