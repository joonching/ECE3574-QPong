#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "base.h"
#include <QBrush>
#include <QPointF>
#include <QString>

class background : public base
{
public:
    background();
    virtual void draw(QPainter *painter);
private:
    int width, height;
    int left_score, right_score;
    QString left, right;
    QPointF text_left, text_right;
};

#endif // BACKGROUND_H

