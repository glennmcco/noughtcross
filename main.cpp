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
