#include "ClickableLabel.h"

#include "gameon.h"
#include "ui_gameon.h"

ClickableLabel *grid[3][3];

GameOn::GameOn(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameOn)
{
    ui->setupUi(this);
    showHome();
//    //Initialise 0 wins for both players
//    noughtwin = 0;
//    crosswin = 0;

//    //Loads nought and cross png files into Pixmap objects
//    n = QPixmap("D:\\Metix\\noughcross\\nought-01.png");
//    c = QPixmap("D:\\Metix\\noughcross\\cross-01.png");

//    //create widgets to contain main and game screen
//    mainscreen = new QWidget(this);
//    gamescreen = new QWidget(this);

//    //Set background colour using style sheet
//    setStyleSheet("QWidget {"
//                  "background-color : rgb(49,49,49);"
//                  "}");
////    gamescreen->setStyleSheet("QWidget {"
////                              "background-color : red;"
////                              "}");

//    //----initiate elements for the main screen-----

//    //Create and Stlye the noughts text label
//    noughts = new QLabel("noughts");
//    noughts->setStyleSheet("background-color: rgba(0,0,0,0%);"
//                           "color : rgb(240,129,19);"
//                           "font: 58pt \"Roboto Condensed\";"
//                           );

//     //Create and Stlye a + text label
//    plus = new QLabel("+");
//    plus->setStyleSheet("background-color: rgba(0,0,0,0%);"
//                        "color : rgb(255,255,255); "
//                        "font: 58pt \"Roboto Condensed\";"
//                        "padding: 17px;"
//                        );

//     //Create and Stlye the crossess text label
//    crosses = new QLabel("crosses");
//    crosses->setStyleSheet("background-color: rgba(0,0,0,0%);"
//                           "color : rgb(184,57,142); "
//                           "font: 58pt \"Roboto Condensed\";"
//                           );

//    //creates nought and cross icon by scaling pixmaps into labels.
//    nought= new QLabel();
//   // nought->setPixmap(GL->getnought().scaled(46,46,Qt::KeepAspectRatio,Qt::SmoothTransformation));
//    nought->setPixmap(n.scaled(46,46,Qt::KeepAspectRatio,Qt::SmoothTransformation));
//    nought->setStyleSheet("border-right: 1px solid white;"
//                          "padding: 17px;");

//    cross= new QLabel();
//    cross->setPixmap(c.scaled(46,46,Qt::KeepAspectRatio,Qt::SmoothTransformation));
//    cross->setStyleSheet("border-left: 1px solid white;"
//                         "padding: 17px;");

//    //Creates a white roundbox pushbutton using style sheet
//    start  = new QPushButton("Start game");
//    start->setStyleSheet("background-color : white;"
//                         "border-radius : 31px;"
//                         "color : rgb(49,49,49);"
//                         "font: 18pt \"Roboto Condensed\";"
//                         "font-weight : bold;"
//                         );

//    //set the height of the button to 62
//    start->setFixedHeight(62);

//    //Connect Startgame button click to start game method
//    QObject::connect(start,SIGNAL(clicked()),this,SLOT(startgame()));

//    //Sets a QWidget(title) to have QHBoxlayout(message) that will display the title
//    QWidget *title = new QWidget(this);
//    QHBoxLayout *message = new QHBoxLayout;
//    message->setAlignment(Qt::AlignJustify);
//    message->setSpacing(0);
//    message->addWidget(noughts);
//    message->addWidget(plus);
//    message->addWidget(crosses);
//    title->setLayout(message);


//    //Sets a QWidget(icon) to have a QHBoxlayout(o_x) that will display the x|o icon
//    QWidget *icon = new QWidget(this);
//    QHBoxLayout *o_x = new QHBoxLayout;
//    o_x->setAlignment(Qt::AlignJustify);
//    o_x->setSpacing(0);
//    o_x->addWidget(nought);
//    o_x->addWidget(cross);
//    icon->setLayout(o_x);


//    //Creates a QVBoxlayout using the title and icon QWidgets and the Start button
//    home = new QVBoxLayout;
//    home->setAlignment(Qt::AlignCenter);
//    home->addSpacing(270);
//    home->addWidget(title);
//    home->addSpacing(85);
//    home->addWidget(icon);
//    home->addSpacing(301);
//    home->addWidget(start);
//    home->addSpacing(78);

//    //Set's the homescreen QVBoxlayout
//    mainscreen->setLayout(home);
//    gamescreen->hide();
}



GameOn::~GameOn()
{
    delete ui;
}

void GameOn::showHome()
{
    //Initialise 0 wins for both players
    noughtwin = 0;
    crosswin = 0;

    //Loads nought and cross png files into Pixmap objects
    n = QPixmap("D:\\Metix\\noughcross\\nought-01.png");
    c = QPixmap("D:\\Metix\\noughcross\\cross-01.png");

    //create widgets to contain main and game screen
    mainscreen = new QWidget(this);
    gamescreen = new QWidget(this);

    //Set background colour using style sheet
    setStyleSheet("QWidget {"
                  "background-color : rgb(49,49,49);"
                  "}");
//    gamescreen->setStyleSheet("QWidget {"
//                              "background-color : red;"
//                              "}");

    //----initiate elements for the main screen-----

    //Create and Stlye the noughts text label
    noughts = new QLabel("noughts");
    noughts->setStyleSheet("background-color: rgba(0,0,0,0%);"
                           "color : rgb(240,129,19);"
                           "font: 58pt \"Roboto Condensed\";"
                           );

     //Create and Stlye a + text label
    plus = new QLabel("+");
    plus->setStyleSheet("background-color: rgba(0,0,0,0%);"
                        "color : rgb(255,255,255); "
                        "font: 58pt \"Roboto Condensed\";"
                        "padding: 17px;"
                        );

     //Create and Stlye the crossess text label
    crosses = new QLabel("crosses");
    crosses->setStyleSheet("background-color: rgba(0,0,0,0%);"
                           "color : rgb(184,57,142); "
                           "font: 58pt \"Roboto Condensed\";"
                           );

    //creates nought and cross icon by scaling pixmaps into labels.
    nought= new QLabel();
   // nought->setPixmap(GL->getnought().scaled(46,46,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    nought->setPixmap(n.scaled(46,46,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    nought->setStyleSheet("border-right: 1px solid white;"
                          "padding: 17px;");

    cross= new QLabel();
    cross->setPixmap(c.scaled(46,46,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    cross->setStyleSheet("border-left: 1px solid white;"
                         "padding: 17px;");

    //Creates a white roundbox pushbutton using style sheet
    start  = new QPushButton("Start game");
    start->setStyleSheet("background-color : white;"
                         "border-radius : 31px;"
                         "color : rgb(49,49,49);"
                         "font: 18pt \"Roboto Condensed\";"
                         "font-weight : bold;"
                         );

    //set the height of the button to 62
    start->setFixedHeight(62);

    //Connect Startgame button click to start game method
    QObject::connect(start,SIGNAL(clicked()),this,SLOT(startgame()));

    //Sets a QWidget(title) to have QHBoxlayout(message) that will display the title
    QWidget *title = new QWidget(this);
    QHBoxLayout *message = new QHBoxLayout;
    message->setAlignment(Qt::AlignJustify);
    message->setSpacing(0);
    message->addWidget(noughts);
    message->addWidget(plus);
    message->addWidget(crosses);
    title->setLayout(message);


    //Sets a QWidget(icon) to have a QHBoxlayout(o_x) that will display the x|o icon
    QWidget *icon = new QWidget(this);
    QHBoxLayout *o_x = new QHBoxLayout;
    o_x->setAlignment(Qt::AlignJustify);
    o_x->setSpacing(0);
    o_x->addWidget(nought);
    o_x->addWidget(cross);
    icon->setLayout(o_x);


    //Creates a QVBoxlayout using the title and icon QWidgets and the Start button
    home = new QVBoxLayout;
    home->setAlignment(Qt::AlignCenter);
    home->addSpacing(270);
    home->addWidget(title);
    home->addSpacing(85);
    home->addWidget(icon);
    home->addSpacing(301);
    home->addWidget(start);
    home->addSpacing(78);

    //Set's the homescreen QVBoxlayout
    mainscreen->setLayout(home);
    gamescreen->hide();
}
void GameOn::startgame()
{
    mainscreen->hide();
    //GL = new GameLogic();
    //GL->setWindow(this);
    buildGameLayout();
    t=n_t;
    while(won<0)
    {

    }
    switch(won)
    {
        case 0:
            turn->setText("it's a draw!");
            break;
        case 1:
            turn->setText("noughts won!");
            break;
        case 2:
            turn->setText("crosses won!");
            break;
    }

//    Turn T = n_t;
//    int winner = 0;
//    while(winner!=2)
//    {
//        int winner = takeTurn(T);

//        switch (winner)
//        {
//        case -1:
//            noughtwin++;
//            break;
//        case 0:
//            break;
//        case 1:
//            crosswin++;
//        break;
//        }
//    }
}

void GameOn::buildGameLayout()
{
    //
    QLabel *smalln = new QLabel();
    //smalln->setPixmap(GL->getnought().scaled(23,23,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    smalln->setPixmap(n.scaled(23,23,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    nscore = new QLabel("Noughts score: " + QString::number(noughtwin));

    nscore->setStyleSheet("background-color: rgba(0,0,0,0%);"
                          "color : rgb(255,255,255); "
                          "font: 21pt \"Roboto Condensed\";"
                          "font-weight : bold;"
                          "border-color: rgba(0,0,0,0%)"
                           );



    QLabel *smallc = new QLabel();
    //smallc->setPixmap(GL->getcross().scaled(23,23,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    smallc->setPixmap(c.scaled(23,23,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    cscore = new QLabel("Crosses score: "+ QString::number(crosswin));

    cscore->setStyleSheet("background-color: rgba(0,0,0,0%);"
                          "color : rgb(255,255,255); "
                          "font: 21pt \"Roboto Condensed\";"
                          "font-weight : bold;"
                          "border-color: rgba(0,0,0,0%)"
                          );

    turn = new QLabel("noughts turn!");
    turn->setStyleSheet("background-color: rgba(0,0,0,0%);"
                        "color : rgb(255,255,255); "
                        "font: 31pt \"Roboto Condensed\";"
                        "border-color: rgba(0,0,0,0%)"
                        );
    turn->setAlignment(Qt::AlignCenter);

    //widgets for gamescreen layouts
    //QWidget *gamescreen = new QWidget();
    QWidget *scores = new QWidget(gamescreen);
    QWidget *scoren = new QWidget(scores);
    QWidget *scorec = new QWidget(scores);
    QWidget *gamebox = new QWidget(gamescreen);
    QWidget *gridwid = new QWidget(gamebox);
    QWidget *buttons = new QWidget(gamescreen);

    //Horizontal Box Layout for noughts score
    QHBoxLayout *nl = new QHBoxLayout;
    nl->addWidget(smalln);
    nl->addWidget(nscore);
    scoren->setLayout(nl);
    scoren->setStyleSheet("border-color: rbga(0,0,0,0%);");

    //Horizontal Box Layout for crosses score
    QHBoxLayout *cl = new QHBoxLayout;
    cl->addWidget(smallc);
    cl->addWidget(cscore);
    scorec->setLayout(cl);
    scorec->setStyleSheet("border-color: rbga(0,0,0,0%);");

    //Horizontal layout for whole score board
    QHBoxLayout *sl = new QHBoxLayout;
    sl->addWidget(scoren);
    sl->addWidget(scorec);
    scores->setLayout(sl);
    scores->setStyleSheet("border-color: rgba(0,0,0,0%);"
                          "border-bottom: 1px solid white;"
                          "border-radius: 0px");

    //initialise empty QPixmap labels and add to gamegrid
    gamegrid = new QGridLayout(gridwid);
    gamegrid->setAlignment(Qt::AlignCenter);
    gamegrid->setSpacing(0);

    QString bottom_border = QString("border-bottom: 1px solid white;");
    QString left_border = QString("border-left: 1px solid white;");
    QString right_border = QString("border-right: 1px solid white;");
    QString top_border = QString("border-top: 1px solid white;");
    //ClickableLabel *grid[3][3];
    gridwid->setStyleSheet("border-color: rgba(0,0,0,0%);");
    QPixmap blank = QPixmap(64,64);
    blank.fill(Qt::transparent);

    for (int i = 0;i<9; i++)
    {
        int x = i/3;
        int y = i%3;
        QString ss = "padding: 28px;"
                     "border-radius: 0px;";
        if(x < 2){
            ss = (ss + bottom_border);
            if(x > 0){
                ss = (ss + top_border);
            }
        }
        if(y < 2){
            ss = (ss + right_border);
            if(y > 0){
                ss = (ss + left_border);
            }
        }
        grid[x][y] = new ClickableLabel();
        grid[x][y]->setPixmap(blank);
        grid[x][y]->setStyleSheet(ss);
        grid[x][y]->setPanel(i);

        //turn->setText(ss);
        gamegrid->addWidget(grid[x][y],x,y);
        QObject::connect(grid[x][y],SIGNAL(clicked(int)),this,SLOT(gridClick(int)));
        //QObject::connect(grid[x][y],SIGNAL(clicked()),this,SLOT());
    }
    gridwid->setLayout(gamegrid);


    //Vertical Box Layout for the gameplay
    QVBoxLayout *gl = new QVBoxLayout;
    gl->setAlignment(Qt::AlignCenter);
    gl->setSpacing(0);
    gl->addWidget(scores);
    gl->addSpacing(63);
    gl->addWidget(turn);
    gl->addSpacing(64);
    gl->addWidget(gridwid);
    gl->addSpacing(75);
    gamebox->setLayout(gl);
    gamebox->setStyleSheet("border: 1px solid white;"
                           "border-radius: 31;"
                           "margin: 0px;");

    //Creates a white roundbox pushbutton using style sheet
    back  = new QPushButton("Back");
    back->setStyleSheet("QPushButton{"
                         "background-color : rgb(49,49,49);"
                         "border-radius : 31px;"
                         "border : 1px solid white;"
                         "color : rgb(255,255,255);"
                         "font: 18pt \"Roboto Condensed\";"
                         "font-weight : bold;"
                         "}");

    //set the height of the button to 62
    back->setFixedHeight(62);
    QObject::connect(back,SIGNAL(clicked()),this,SLOT(back_click()));

    //Creates a white roundbox pushbutton using style sheet
    newg  = new QPushButton("New game");
    newg->setStyleSheet("QPushButton{"
                         "background-color : rgb(255,255,255);"
                         "border-radius : 31px;"
                         "color : rgb(49,49,49);"
                         "font: 18pt \"Roboto Condensed\";"
                         "font-weight : bold;"
                         "}");

    //set the height of the button to 62
    newg->setFixedHeight(62);

    //Connect Startgame button click to start game method
    QObject::connect(newg,SIGNAL(clicked()),this,SLOT(newg_click()));

    QHBoxLayout *bl = new QHBoxLayout;
    bl->addWidget(back);
    bl->addWidget(newg);
    buttons->setLayout(bl);

    game = new QVBoxLayout;
    game->setAlignment(Qt::AlignCenter);
    game->setSpacing(0);
    game->addSpacing(101);
    game->addWidget(gamebox);
    game->addSpacing(33);
    game->addWidget(buttons);
    game->addSpacing(78);
    gamescreen->setLayout(game);
    gamescreen->show();

    //QObject::connect(gridwid,SIGNAL(clicked()),this->parent(),SLOT(gridClick()));
    //this->show();
}

void GameOn::updateturn(QString S)
{
    turn->setText(S);
}

void GameOn::gridClick(int p)
{
    int x = p/3;
    int y = p%3;
    if(t==n_t)
    {
        grid[x][y]->setPixmap(n.scaled(64,64,Qt::KeepAspectRatio,Qt::SmoothTransformation));
        turn->setText("crosses turn!");
        t=c_t;
    }
    else if(t==c_t)
    {
        grid[x][y]->setPixmap(c.scaled(64,64,Qt::KeepAspectRatio,Qt::SmoothTransformation));
        turn->setText("noughts turn!");
        t=n_t;
    }
    QObject::disconnect(grid[x][y],SIGNAL(clicked(int)),this,SLOT(gridClick(int)));

}

int GameOn::checkWin(int p)
{
    int x = p/3;
    int y = p%3;
    bool[8][9]={0};
    return -1;
}

void GameOn::back_click()
{
    gamescreen->hide();
    mainscreen->show();
}

void GameOn::newg_click()
{

}


