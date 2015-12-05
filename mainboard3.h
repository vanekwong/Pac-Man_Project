/**@file mainboard3.h
 * @brief implements the hard-level board
  */

#ifndef MAINBOARD3_H
#define MAINBOARD3_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "pacman.h"

namespace Ui {
class mainboard3;
}

class mainboard3 : public QWidget
{
    Q_OBJECT

public:
    explicit mainboard3(QWidget *parent = 0);
    ~mainboard3();

    QGraphicsScene * scene;
    Pacman * player;

private:
    Ui::mainboard3 *ui;
};

#endif // MAINBOARD3_H
