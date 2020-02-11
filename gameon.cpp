#include "ClickableLabel.h"

#include "gameon.h"
#include "ui_gameon.h"

GameOn::GameOn(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameOn)
{
    ui->setupUi(this);

    //Initialise 0 wins for both players
    noughtwin = 0;
    crosswin = 0;

    //Creates Blank Pixmap with transparent background
    blank= QPixmap(64,64);
    blank.fill(Qt::transparent);

    //Loads nought and cross png files into Pixmap objects
    n = QPixmap("D:\\Metix\\noughcross\\nought-01.png");
    c = QPixmap("D:\\Metix\\noughcross\\cross-01.png");

    //create widgets to contain main and game screen
    mainscreen = new QWidget(this);
    gamescreen = new QWidget(this);

    //Bring up the mainscreen
    showHome();

    //build layout and widgets for gamescreen to been shown when start.clicked() signal emitted
    buildGameLayout();
}



GameOn::~GameOn()
{
    delete ui;
}

void GameOn::showHome()
{
    //Set background colour using style sheet
    setStyleSheet("background-color: rgb(49,49,49);");

    /*-------------------------initiate elements for the main screen-----------------------------*/

    //Create and Stlye the noughts text label
    noughts = new QLabel("noughts");
    noughts->setStyleSheet("background-color: rgba(0,0,0,0%);"
                           "color: rgb(240,129,19);"
                           "font: 58pt \"Roboto Condensed\";"
                           );

     //Create and Stlye a + text label
    plus = new QLabel("+");
    plus->setStyleSheet("background-color: rgba(0,0,0,0%);"
                        "color: rgb(255,255,255); "
                        "font: 58pt \"Roboto Condensed\";"
                        "padding: 17px;"
                        );

     //Create and Stlye the crossess text label
    crosses = new QLabel("crosses");
    crosses->setStyleSheet("background-color: rgba(0,0,0,0%);"
                           "color: rgb(184,57,142); "
                           "font: 58pt \"Roboto Condensed\";"
                           );

    //creates nought and cross icon by scaling pixmaps into labels.
    nought= new QLabel();
    nought->setPixmap(n.scaled(46,46,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    nought->setStyleSheet("border-right: 1px solid white;"
                          "padding: 17px;");

    cross= new QLabel();
    cross->setPixmap(c.scaled(46,46,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    cross->setStyleSheet("border-left: 1px solid white;"
                         "padding: 17px;");

    //Creates a white roundbox pushbutton using style sheet
    start  = new QPushButton("Start game");
    start->setStyleSheet("background-color: white;"
                         "border-radius: 31px;"
                         "color: rgb(49,49,49);"
                         "font: 18pt \"Roboto Condensed\";"
                         "font-weight: bold;"
                         );

    //set the height of the button to 62
    start->setFixedHeight(62);

    //Connect Startgame button click to start game method
    QObject::connect(start,SIGNAL(clicked()),this,SLOT(startgame()));

    /*--------------------Set widgets and layouts for the main screen----------------------------*/

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


void GameOn::buildGameLayout()
{
    /*---------------------Elements for Building gamescreen----------------------------------------*/

    /*A small nought icon and text label to display number of noughts games won*/
    QLabel *smalln = new QLabel();
    smalln->setPixmap(n.scaled(23,23,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    nscore = new QLabel("Noughts score: " + QString::number(noughtwin));

    //Sets background colour and border to transparent and font style
    nscore->setStyleSheet("background-color: rgba(0,0,0,0%);"
                          "color: rgb(255,255,255); "
                          "font: 21pt \"Roboto Condensed\";"
                          "font-weight: bold;"
                          "border-color: rgba(0,0,0,0%);"
                          "margins: 0px;"
                           );

    //A small cross icon and text label to display number of noughts games won
    QLabel *smallc = new QLabel();
    smallc->setPixmap(c.scaled(23,23,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    cscore = new QLabel("Crosses score: "+ QString::number(crosswin));

    //Sets background colour and border to transparent and font style
    cscore->setStyleSheet("background-color: rgba(0,0,0,0%);"
                          "color: rgb(255,255,255); "
                          "font: 21pt \"Roboto Condensed\";"
                          "font-weight: bold;"
                          "border-color: rgba(0,0,0,0%);"
                          "margins: 0px;"
                          );

//    QFrame *pipe = new QFrame();
//    pipe->setFixedWidth(490);
//    pipe->setFrameShape(QFrame::HLine);
//    pipe->setStyleSheet("color: white;"
//                        "border-color: rgba(0,0,0,0%);"
//                        "border-bottom: 1px solid white;"
//                        );

     /*text label to display win state or current turn*/
    turn = new QLabel("noughts turn!");

    //Sets background colour and border to transparent and font style
    turn->setStyleSheet("background-color: rgba(0,0,0,0%);"
                        "color: rgb(255,255,255); "
                        "font: 31pt \"Roboto Condensed\";"
                        "border-color: rgba(0,0,0,0%);"
                        );
    turn->setAlignment(Qt::AlignCenter);

    /*--------------------Create Buttons for back to mainscreen and new game-----------------------------*/
    //Creates and styles a white line roundbox pushbutton Back
    back  = new QPushButton("Back");
    back->setStyleSheet( "background-color: rgb(49,49,49);"
                         "border-radius: 31px;"
                         "border: 1px solid white;"
                         "color: rgb(255,255,255);"
                         "font: 18pt \"Roboto Condensed\";"
                         "font-weight: bold;"
                         );
    back->setFixedHeight(62);

    //connects back PushButton clicked SIGNAL() to back_click handler SLOT() in GameOn
    QObject::connect(back,SIGNAL(clicked()),this,SLOT(back_click()));

    //Creates and styles a white filled roundbox pushbutton New game
    newg  = new QPushButton("New game");
    newg->setStyleSheet("background-color: rgb(255,255,255);"
                         "border-radius: 31px;"
                         "color: rgb(49,49,49);"
                         "font: 18pt \"Roboto Condensed\";"
                         "font-weight: bold;"
                         );
    newg->setFixedHeight(62);

    //connects newg PushButton clicked() SIGNAL() to newg_click() handler SLOT() in GameOn
    QObject::connect(newg,SIGNAL(clicked()),this,SLOT(newg_click()));

    /*---------------------Widgets for gamescreen layouts----------------------------------------*/
    //Score screen labels
    QWidget *scores = new QWidget(gamescreen);
    QWidget *scoren = new QWidget(scores);
    QWidget *scorec = new QWidget(scores);

    //Game board
    QWidget *gamebox = new QWidget(gamescreen);
    QWidget *gridwid = new QWidget(gamebox);

    //Button Controls
    QWidget *buttons = new QWidget(gamescreen);

    /*--------------------Specifying Layouts for gamescreen widgets-----------------------------*/
    //Horizontal Box Layout for noughts score
    QHBoxLayout *nl = new QHBoxLayout;
    nl->setSpacing(0);
    nl->addWidget(smalln);
    nl->addWidget(nscore);
    scoren->setLayout(nl);
    scoren->setStyleSheet("border-color: rbga(0,0,0,0%);"
                          "margins: 0px;"
                          );

    //Horizontal Box Layout for crosses score
    QHBoxLayout *cl = new QHBoxLayout;
    cl->setSpacing(0);
    cl->addWidget(smallc);
    cl->addWidget(cscore);
    scorec->setLayout(cl);
    scorec->setStyleSheet("border-color: rbga(0,0,0,0%);"
                          "margins: 0px;"
                          );

    //Horizontal layout for whole score board
    QHBoxLayout *sl = new QHBoxLayout;
    sl->setSpacing(0);
    sl->addWidget(scoren);
    sl->addWidget(scorec);
    scores->setLayout(sl);
    scores->setStyleSheet("border-color: rgba(0,0,0,0%);"
                          "border-bottom: 2px solid white;"
                          "border-radius: 0px;"
                          "margins: 0px;"
                          );

    QHBoxLayout *bl = new QHBoxLayout;
    bl->addWidget(back);
    bl->addWidget(newg);
    buttons->setLayout(bl);

    /*-----------------------Create Gamegrid out of QPixMap Labels-------------------------------*/
    //create and align QGrid Layout for gameplay
    gamegrid = new QGridLayout(gridwid);
    gamegrid->setAlignment(Qt::AlignCenter);
    gamegrid->setSpacing(0);
    gridwid->setStyleSheet("border-color: rgba(0,0,0,0%);");

    //String Constants for setting borders in stylesheets
    const QString bottom_border = QString("border-bottom: 1px solid white;");
    const QString left_border = QString("border-left: 1px solid white;");
    const QString right_border = QString("border-right: 1px solid white;");
    const QString top_border = QString("border-top: 1px solid white;");

    //for every panel in the grid get coordinates and initialise
    for (int i = 0;i<9; i++)
    {
        //x and y coordinates
        int x = i/3;
        int y = i%3;

        //StyleSheet String base with padding and square border corners
        QString ss = "padding: 28px;"
                     "border-radius: 0px;";

        //add appropriate border string constants to stylesheet string
        if(x < 2){ss = (ss + bottom_border);
            if(x > 0){ss = (ss + top_border);}
        }
        if(y < 2){ss = (ss + right_border);
            if(y > 0){ss = (ss + left_border);}
        }

        //Create each panel as a new styles ClickableLabel marking its position with setPanel(i)
        grid[x][y] = new ClickableLabel();
        grid[x][y]->setStyleSheet(ss);
        grid[x][y]->setPanel(i);

        //add the panel to the gamegrid layout at (x,y)
        gamegrid->addWidget(grid[x][y],x,y);

    }
    //set grid widget to the grid layout
    gridwid->setLayout(gamegrid);

    /*--------------------Vertical layouts for sections of gamescreen----------------------------*/

    //Vertical Box Layout for the gameplay
    QVBoxLayout *gl = new QVBoxLayout;
    gl->setAlignment(Qt::AlignCenter);
    gl->setSpacing(0);
    gl->addWidget(scores);
//    gl->addWidget(pipe);
    gl->addSpacing(50);
    gl->addWidget(turn);
    gl->addSpacing(80);
    gl->addWidget(gridwid);
    gl->addSpacing(75);

    //Set gamebox layout to gl and style
    gamebox->setLayout(gl);
    gamebox->setStyleSheet("border: 2px solid white;"
                           "border-radius: 23px;"
                           "margin: 0px;"
                           "padding: 0px;"
                           );
    newg_click();
    game = new QVBoxLayout;
    game->setAlignment(Qt::AlignCenter);
    game->setSpacing(0);
    game->addSpacing(101);
    game->addWidget(gamebox);
    game->addSpacing(33);
    game->addWidget(buttons);
    game->addSpacing(78);
    gamescreen->setLayout(game);
}

void GameOn::startgame()
{
    //Set Scoreboard
    nscore->setText("Noughts score: " + QString::number(noughtwin));
    cscore->setText("Crosses score: " + QString::number(crosswin));

    //hide the mainscreen and show gamescreen
    mainscreen->hide();
    gamescreen->show();

    //set turn(t) to naughts turn(n_t) and won < 0
    t=n_t;
    won=false;
}

void GameOn::gridClick(int p)
{
    //calculate coordnates of panel #p
    int x = p/3;
    int y = p%3;

    /**
     * If it's noughts turn then set Pixmap of appropriate label to nought
     * Update turn indicator and state of noughts(nstate); set turn to crosses turn(c_t)
    */
    if(t==n_t){grid[x][y]->setPixmap(n.scaled(64,64,Qt::KeepAspectRatio,Qt::SmoothTransformation));
        turn->setText("crosses turn!"); nstate|=bit[p]; t=c_t;
    }
    /**
     * If it's crosses turn then set Pixmap of appropriate label to crosses
     * Update turn indicator and state of crosses(cstate); set turn to crosses turn(c_t)
    */
    else if(t==c_t){grid[x][y]->setPixmap(c.scaled(64,64,Qt::KeepAspectRatio,Qt::SmoothTransformation));
        turn->setText("noughts turn!"); cstate|=bit[p]; t=n_t;
    }

    //disconnect label to prevent overwriting state
    QObject::disconnect(grid[x][y],SIGNAL(clicked(int)),this,SLOT(gridClick(int)));

    //update number of panels clicked(clicks) and check the win conditions
    clicks++;
    checkWin();
}

void GameOn::checkWin()
{
    //local variable
    uint16_t check=0;

    /*Initialise winning conditions of 3 matching tiles in a row
     *
     * win states    {0xE000,0x1C00,0x0380,0x9200,0x7900,0x2480,0x8880,0x2A00}
     *
     * correspond to the following 5 winning binary grid conditions
     *
     * Horizontal   {{1,1,1, {0,0,0, {0,0,0,
     *                0,0,0,  1,1,1,  0,0,0,
     *                0,0,0}, 0,0,0}, 1,1,1},
     *
     * Vertial      {1,0,0, {0,1,0, {0,0,1,
     *               1,0,0,  0,1,0,  0,0,1,
     *               1,0,0}, 0,1,0}, 0,0,1},
     *
     * Diagonal     {1,0,0, {0,0,1,
     *               0,1,0,  0,1,0,
     *               0,0,1}, 1,0,0}};*/
    uint16_t win_state[8] = {0xE000,0x1C00,0x0380,0x9200,0x7900,0x2480,0x8880,0x2A00};

    /*Set Local grid state to previous turn since checkWin is only ever invoked by
     *gridClick() current t state is opponents next turn, set check appropriately*/
    if(t==c_t){check = nstate;}
    else{check = cstate;}

    //For each win_state...
    for (int i=0;i<9;i++)
    {
        //set local instance of uint16_t to current state check bitmasked by win_state
        uint16_t lcheck =check & win_state[i];

        //if local check now equals win state player has won
        if (lcheck == win_state[i])
        {
            //Update and Display appropriate scoreboard
            if(t==c_t){turn->setText("noughts won!");   noughtwin++;
                nscore->setText("Noughts score: " + QString::number(noughtwin));
            }
            else{turn->setText("crosses won!"); crosswin++;
                cscore->setText("Crosses score: " + QString::number(crosswin));
            }

            //disconnect all other panels to prevent further play until newg.clicked()
            gridDisconnect();
            won=true;
        }
    }

    //if no win was detected and all panels have been clicked then Display it's a draw
    if(not(won)&&clicks>=9){turn->setText("it's a draw!");}

}

//disconnect all labels on the grid from the gridClick() SLOT()
void GameOn::gridDisconnect(){
    for(int l=0;l<9;l++)
    {
        int x = l/3;
        int y = l%3;
        grid[x][y]->disconnect();
    }
}

void GameOn::back_click()
{

    //Delete game history reset to 0 wins for both players
    noughtwin = 0;
    crosswin = 0;

    //reset game screen using newg_click()
    newg_click();

    //Hide gamescreen, show mainscreen
    gamescreen->hide();
    mainscreen->show();
}

void GameOn::newg_click()
{
    //for every panel in the grid...
    for (int i = 0;i<9; i++)
    {
        //calculate x and y coordinates
        int x = i/3;
        int y = i%3;

        //set it's QPixmap to blank
        grid[x][y]->setPixmap(blank);

        //Connect ClickableLabel clicked(int) SIGNAL() to gridClick(int) SLOT() handler in GameOn
        QObject::connect(grid[x][y],SIGNAL(clicked(int)),this,SLOT(gridClick(int)));
    }

    //reset game state for both players
    nstate &= 0x0000;
    cstate &= 0x0000;

    //set Turn(t) to noughts turn(n_t), reset clicks and set turn indicator
    t=n_t;
    clicks=0;
    won=false;
    turn->setText("noughts turn!");
}
