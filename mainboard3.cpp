/**@fiel mainboard3.cpp
 * @brief Declaration and definition of the hard-level board.
 * Sets up the background, the player, and the dropping of the enemy.
*/

#include "mainboard3.h"
#include "ui_mainboard3.h"
#include "mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QKeyEvent>
#include "pacman.h"
#include <QTimer>
#include "bullet.h"
#include <QBrush>
#include <QImage>

mainboard3::mainboard3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainboard3)
{
    ui->setupUi(this);

    //create a scene and upload background picture
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(QImage(":/images/background.jpg")));

    //create player(pacman) to add to scene
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
    timer->start(600);
}

mainboard3::~mainboard3()
{
    delete ui;
}
