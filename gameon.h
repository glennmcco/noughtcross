#ifndef GAMEON_H
#define GAMEON_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPixmap>

//#include "gamelogic.h"

class ClickableLabel;

enum Turn {n_t= 0, c_t = 1};
enum WinCon {n_w=1, d_w=0, c_w=2};

QT_BEGIN_NAMESPACE
namespace Ui { class GameOn; }
QT_END_NAMESPACE

class GameOn : public QWidget
{
    Q_OBJECT

public:
    GameOn(QWidget *parent = nullptr);
    ~GameOn();
    void updateturn(QString s);

private:
    Ui::GameOn *ui;

    //variables to track game state
    int noughtwin;
    int crosswin;
    Turn t;
    int won;

    //Win Condition Check values
    uint16_t bit[9] = {0x8000,0x4000,0x2000,0x1000,0x0800,0x0400,0x0200,0x0100,0x0080};

    //gamestate flags
    uint16_t nstate=0;
    uint16_t cstate=0;
//    GameLogic *GL;

    //variables for title screen
    QWidget *mainscreen;
    QLabel *noughts;
    QLabel *plus;
    QLabel *crosses;
    QLabel *nought;
    QLabel *cross;

    //variables for game screen
    QWidget *gamescreen;
    QLabel *nscore;
    QLabel *cscore;
    QLabel *turn;
    QPixmap n;
    QPixmap c;
    ClickableLabel *grid[3][3];

    //Layouts for home screen and game screen
    QVBoxLayout *home;
    QVBoxLayout *game;
    QGridLayout *gamegrid;

    //button variables
    QPushButton *start;
    QPushButton *back;
    QPushButton *newg;

    //game methods
    int checkWin(int p);
    void buildGameLayout();
    void updateTurn();
    void showHome();

private slots:
    void startgame();
    void back_click();
    void newg_click();
    void gridClick(int p);

};
#endif // GAMEON_H
