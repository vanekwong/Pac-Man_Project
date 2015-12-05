/**@file mainwindow.h
 * @brief the mainwindow popup. Another window pop ups when trying to close.
  */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainboard.h"
#include <QtWidgets>
#include "mainboard2.h"
#include "mainboard3.h"
#include "instructions.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /**closes the window when the 'x' button is clicked*/
    void closeEvent (QCloseEvent *event){
        event->ignore();
        if(QMessageBox::Yes == QMessageBox::question(this, "Confirmation","Are you sure?",
                                                     QMessageBox::Yes|QMessageBox::No ))
        {
            event->accept();
        }
    }

private slots:
    /**push buttons declaration */
    void on_easy_button_clicked();
    void on_medium_button_clicked();
    void on_hard_button_clicked();

    void on_instructions_button_clicked();

private:
    Ui::MainWindow *ui;
    Mainboard* board;
    mainboard2* board2;
    mainboard3* board3;
    instructions* inst;

};

#endif // MAINWINDOW_H
