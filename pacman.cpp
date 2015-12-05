/**@file pacman.cpp
 * @brief Declaration and definition of pacman functions.
 */

#include "pacman.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"
#include "enemy.h"

#include <QDebug>

Pacman::Pacman(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    //set graphic
    setPixmap(QPixmap(":/images/pac_man.jpeg"));
}

void Pacman::keyPressEvent(QKeyEvent *event)
{
    //Left key pressed: moves pacman to the left
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-25, y());
    }
    //Right key pressed: moves pacman to the right
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+25, y());
    }
    //Space bar key pressed: pacman shoots
    else if (event->key() == Qt::Key_Space){
        //create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
    }

}


void Pacman::moving_ghosts()
{
    //create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

