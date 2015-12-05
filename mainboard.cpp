/**@file mainboard.cpp
 * @brief Declaration and definition of the easy-level board.
 * Sets up the background, the player, and the dropping of the enemy.
*/

#include "mainboard.h"
#include "ui_mainboard.h"
#include "mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QKeyEvent>
#include "pacman.h"
#include <QTimer>
#include <QBrush>
#include <QImage>

Mainboard::Mainboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mainboard)
{
    ui->setupUi(this);

    //create a scene and upload the background picture onto it
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(QImage(":/images/background.jpg")));

    //create item to add to scene
    //The item will be the player(pacman)
    player = new Pacman();
    player->setPos(400,550);

    //make the player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //add player(pacman) to scene
    scene->addItem(player);

    //create a view to visualize scene
    QGraphicsView * view = new QGraphicsView(scene);

    //disable scroll bar
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //show the view
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    //move enemy
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(moving_ghosts()));
    timer->start(2000);


}

Mainboard::~Mainboard()
{
    delete ui;
}
