/*
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include "mainboard.h"

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //set position
    int random_number = rand() % 700;
    setPos(random_number, 0);

    //drew a rect
    //setRect(0,0,100,100);
    setPixmap(QPixmap(":/images/navy_ghost.png"));

    //connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    //move enemy down
    setPos(x(), y()+2);
    if (pos().y() > 600){
        scene()->removeItem(this);
        delete this;

    }
}
*/
