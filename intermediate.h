#ifndef INTERMEDIATE_H
#define INTERMEDIATE_H

#include <QVector>
#include <QPainter>
#include "base.h"
#include "background.h"

class intermediate
{
public:
    intermediate();
    void int_draw(QPainter *painter);

private:
    QVector <base *> my_vector;
};


#endif // INTERMEDIATE_H

