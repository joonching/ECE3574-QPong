#include <QApplication>

#include "mainwindow.h"
#include <QKeyEvent>
int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    mainwindow view;
    view.show();

    return application.exec();
}
