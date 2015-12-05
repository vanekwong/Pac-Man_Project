/**@file mainboard.h
 * @brief implements the easy-level board
  */

#ifndef MAINBOARD_H
#define MAINBOARD_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "pacman.h"
#include <QLabel>

namespace Ui {
class Mainboard;
}

class Mainboard : public QWidget
{
    Q_OBJECT

public:
    explicit Mainboard(QWidget *parent = 0);
    ~Mainboard();

    QGraphicsScene * scene;
    Pacman * player;

private:
    Ui::Mainboard *ui;

};

#endif // MAINBOARD_H
