/**@file mainboard2.h
 * @brief implements the medium-level board
  */

#ifndef MAINBOARD2_H
#define MAINBOARD2_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "pacman.h"

namespace Ui {
class mainboard2;
}

class mainboard2 : public QWidget
{
    Q_OBJECT

public:
    explicit mainboard2(QWidget *parent = 0);
    ~mainboard2();

    QGraphicsScene * scene;
    Pacman * player;

private:
    Ui::mainboard2 *ui;
};

#endif // MAINBOARD2_H
