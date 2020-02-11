#ifndef GAMEON_H
#define GAMEON_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPixmap>

//#include "gamelogic.h"


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

    //static integers to track state
    int noughtwin;
    int crosswin;
    Turn t;
    int won;
    bool nstate[9]={0,0,0,0,0,0,0,0,0};
    bool cstate[9]={0,0,0,0,0,0,0,0,0};
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
