#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QSize>
#include <iostream>
#include <QtGui>
#include <QTextEdit>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "pongview.h"
class mainwindow:public QWidget
{
    Q_OBJECT
public:
    mainwindow(QWidget *parent = 0);
private:
    pongview *my_pong;

};

#endif // MAINWINDOW_H

