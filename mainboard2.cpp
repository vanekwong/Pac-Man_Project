/**@file mainboard2.cpp
 * @brief Declaration and definition of the medium-level board
 * Sets up the background, the player, and the dropping of the enemy.
*/

#include "mainboard2.h"
#include "ui_mainboard2.h"
#include "mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QKeyEvent>
#include "pacman.h"
#include <QTimer>
#include <QBrush>
#include <QImage>

mainboard2::mainboard2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainboard2)
{
    ui->setupUi(this);

    //create a scene and upload the background picture
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(QImage(":/images/background.jpg")));

    //create teh player(pacman) to add to scene
    player = new Pacman();
    player->setPos(400,550);

    //make player(pacman) focusable
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

    //moving enemy
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(moving_ghosts()));
    timer->start(900);
}

mainboard2::~mainboard2()
{
    delete ui;
}
