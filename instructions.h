/**@file instructions.h
 * @brief Class that sets up the new popup window
 * that shows the intructions on how to play the game.
*/

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <QDialog>

namespace Ui {
class instructions;
}

class instructions : public QDialog
{
    Q_OBJECT

public:
    explicit instructions(QWidget *parent = 0);
    ~instructions();

private:
    Ui::instructions *ui;
};

#endif // INSTRUCTIONS_H
