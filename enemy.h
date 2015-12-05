/**@file enemy.h
  *@brief class that implements the ghosts.
  *       ghosts drop randomly
*/
#ifndef ENEMY
#define ENEMY

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QList>
#include "mainboard.h"
#include "mainboard2.h"
#include "mainboard3.h"
#include "mainwindow.h"
#include <QCloseEvent>
#include <QtWidgets>
#include <QMessageBox>
#include <QMainWindow>


class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    /**Constructing the ghost */
    Enemy(QGraphicsItem * parent=0){
        /**set position of the ghost to be random*/
        int random_number = rand() % 700;
        setPos(random_number, 0);

        /**draw a rectangle and loads the image of the ghost*/
        setPixmap(QPixmap(":/images/navy_ghost.png"));

        /**sets the time interval in between each ghost */
        QTimer * timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(move()));

        timer->start(50);
    }

public slots:
    void move(){
        /**if enemy collides with pacman, both get destroyed*/
        QList<QGraphicsItem *> colliding_items2 = collidingItems();
        for (size_t i = 0, n = colliding_items2.size(); i < n; ++i){
            if (typeid(*(colliding_items2[i])) == typeid(Pacman)){

                /**remove them both*/
                scene()->removeItem(colliding_items2[i]);
                scene()->removeItem(this);

                QMessageBox msgBox;
                msgBox.setText("GAME OVER! Exit out.");
                msgBox.exec();

                /**delete them both to save memory*/
                delete colliding_items2[i];
                delete this;

                return;
            }
        }

        /**move enemy down*/
        setPos(x(), y()+2);
        if (pos().y() > 600){
            scene()->removeItem(this);
            delete this;

        }
    }
};


#endif // ENEMY

