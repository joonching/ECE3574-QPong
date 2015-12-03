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
#include <QTimer>
#include <QPainter>
#include <QThread>
#include <mutex>

#include "pongview.h"
#include "ball.h"
#include "game_engine.h"
class mainwindow:public QWidget
{
    Q_OBJECT
public:
    mainwindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    void quit();
    pongview* getMyPong();

private:
    pongview *my_pong;
    QTimer *timer;
    ball *my_ball;
    game_engine *g_engine;
    QThread create_thread;
    std::mutex safety;

};

#endif // MAINWINDOW_H

