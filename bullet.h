/**@file bullet.h
  *@brief Contains the class that implements the bullets coming from pacman
*/

#ifndef BULLET
#define BULLET

#include <QGraphicsPixmapItem>
#include <QObject>
#include "mainboard.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"

//extern Mainboard * game;

class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(QGraphicsItem *parent=0){

        /**draws a rectangle
          *loads up the bullet that comes out of pacman */
        setPixmap(QPixmap(":/images/dot.png"));

        /**timer sets up the time in between each bullet */
        QTimer * timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(move()));

        timer->start(50);
    }


public slots:
    void move(){
        /**if bullet collides enemy destroy both */
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (size_t i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Enemy)){

                /**remove them both */
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);

                /**delete them both to save memory */
                delete colliding_items[i];
                delete this;
                return;
            }
        }


        /**move bullet up */
        setPos(x(), y()-10);
        if (pos().y() < 0){
            scene()->removeItem(this);
            delete this;
        }
    }

};

#endif // BULLET

