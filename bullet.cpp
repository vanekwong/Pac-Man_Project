/*
#include "bullet.h"
#include "mainboard.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include "score.h"

Mainboard *game;
Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //drew a rect
    //setRect(0,0,10,50);
    setPixmap(QPixmap(":/images/dot.png"));

    //connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    //if bullet collides enemy destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (size_t i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){

            //increase score

            //game->score->increase();

            //remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //delete them both to save memory
            delete colliding_items[i];
            delete this;
            return;
        }
    }


    //move bullet up
    setPos(x(), y()-10);
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
*/
