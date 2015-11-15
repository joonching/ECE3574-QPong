#include "intermediate.h"
#include <QDebug>
#include <iostream>
intermediate::intermediate()
{
    my_vector.push_back(new background);
}

void intermediate::int_draw(QPainter *painter)
{
    for(int i = 0; i < my_vector.size(); i++)
        my_vector[i]->draw(painter);

}
