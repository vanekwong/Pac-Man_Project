/**@file mainwindow.cpp
 * @brief Displays the mainwindow with the title, push buttons indicating the levels and the intructions.
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainboard.h"
#include "mainboard2.h"
#include "mainboard3.h"
#include "instructions.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->instructions_button, SIGNAL(click()), this, SLOT(instructionsWindow()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Easy level push button opens the easy-level gameboard
void MainWindow::on_easy_button_clicked()
{
    board = new Mainboard(this);
}

//Medium level push button opens the medium-level gameboard
void MainWindow::on_medium_button_clicked()
{
    board2 = new mainboard2(this);
}

//Hard level push button opens the hard-level gameboard
void MainWindow::on_hard_button_clicked()
{
    board3 = new mainboard3(this);
}

void MainWindow::on_instructions_button_clicked()
{
    inst = new instructions(this);
    inst->show();
}
