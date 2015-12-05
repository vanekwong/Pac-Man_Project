/**@file main.cpp
 * @author Vanessa Kwong
 * @date December 3, 2015
 * @brief This program imitates a spaceshooter game with pacman as the player and the ghosts as the enemy.
*/

#include "mainwindow.h"
#include "mainboard.h"
#include <QApplication>

//Mainboard *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //displays the mainwindow
    w.show();

    return a.exec();
}
