/**@file pacman.h
 * @brief declaration of the functions of pacman
  */

#ifndef PACMAN
#define PACMAN

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Pacman: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Pacman(QGraphicsItem *parent = 0);
    void keyPressEvent(QKeyEvent * event);
    void movePlayer();
public slots:
    void moving_ghosts();

};

#endif

