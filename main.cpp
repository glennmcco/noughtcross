//Version: 0.7
//Title: noughtscross
//Author: Glenn McConnell
//Last Update: 11/02/2020
//Description: Runs a QWidget extension which initialises itself to a splash Screen
//        where the player can choose to start a game of noughts and crosses allowing
//        them to play games while retaining the match score.
//Change Log:
//        V0.1: Lables and Layouts
//        V0.2: Stylesheets and Pixmaps
//        V0.3: Spacing the Layouts & scaling picture labels
//        V0.4: Home Screen with button importing fonts
//        V0.5: Added Gamescreen, encapsulated functionality in QWidget subclass gameon
//        V0.6: Implemented Clickable Labels and gamescreen borders
//        V0.7: Game Logic class

#include "gameon.h"
//#include "gamelogic.h"

#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Add Roboto Condensed Fonts to the Database
    QFontDatabase::addApplicationFont("D:\\Metix\\noughcross\\RobotoCondensed-Regular.ttf");
    QFontDatabase::addApplicationFont("D:\\Metix\\noughcross\\RobotoCondensed-Bold.ttf");

    //Create an instance of the GameOn Window and show it
    //static GameLogic *GL = new GameLogic;
    GameOn w;
    w.show();
    return a.exec();
}
