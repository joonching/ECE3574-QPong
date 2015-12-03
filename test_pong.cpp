#include "mainwindow.h"
#include <QTest>
#include <QDebug>
#include <QIODevice>
#include <QPainter>
#include <QString>
#include "ball.h"
#include "pongview.h"
#include "game_engine.h"
#include <mutex>


class test_pong : public QObject
{
    Q_OBJECT
public:

private slots:
    void integration_test()
    {
        std::mutex check;
        mainwindow *show_all = new mainwindow();
        QString format = "png";
        int j = 1;
        game_engine *test_gEngine = new game_engine(check);
        test_gEngine->set_start();

        show_all->show();
        for(int i = 0; i < 30; i++)
        {
            if(i%3 == 0 || i%5 == 0)
            {
                 QTest::keyPress(show_all, Qt::Key_S, Qt::NoModifier, 10*i);
                 QTest::keyRelease(show_all, Qt::Key_S, Qt::NoModifier, 15*i);
            }

            else
            {
                 QTest::keyPress(show_all, Qt::Key_A, Qt::NoModifier, 10*i);
                 QTest::keyRelease(show_all, Qt::Key_A, Qt::NoModifier, 15*i);
            }

            if(i%4 == 0 || i%6 == 0)
            {
                QTest::keyPress(show_all, Qt::Key_K, Qt::NoModifier, 10*i);
                QTest::keyRelease(show_all, Qt::Key_K, Qt::NoModifier, 15*i);
            }

            else
            {
                QTest::keyPress(show_all, Qt::Key_L, Qt::NoModifier, 10*i);
                QTest::keyRelease(show_all, Qt::Key_L, Qt::NoModifier, 15*i);
            }


            if(i%2 == 0 || i%3 == 0)
            {
                char buf[20];
                QPixmap mypixmap = QPixmap::grabWidget(show_all);
                sprintf(buf, "testpic_%d.png", j);
                QString name = QString::fromAscii(buf);
                mypixmap.save(name, format.toAscii());
                j++;
            }

        }
    }

};

QTEST_MAIN(test_pong)
#include "test_pong.moc"
