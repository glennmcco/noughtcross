//#include "gameon.h"
//#include "ClickableLabel.h"
//#include "gamelogic.h"

//GameLogic::GameLogic(QObject *parent) : QObject(parent)
//{
//    n = QPixmap("D:\\Metix\\noughcross\\nought-01.png");
//    c = QPixmap("D:\\Metix\\noughcross\\cross-01.png");
//    won=2;
//    t=n_t;
//    QPixmap blank = QPixmap(64,64);
//    blank.fill(Qt::transparent);

//    for (int i = 0;i<9; i++)
//    {
//        int x = i/3;
//        int y = i%3;

//        grid[x][y] = new ClickableLabel();
//        grid[x][y]->setPixmap(blank);
//        grid[x][y]->setPanel(i);

//        QObject::connect(grid[x][y],SIGNAL(clicked(int i)),this,SLOT(updatePanel(int p)));
//        //QObject::connect(grid[x][y],SIGNAL(clicked()),this,SLOT());
//    }
//}

//void GameLogic::updatePanel(int p)
//{
//    if(p>=0 && p<9)
//    {
//        int x = p/3;
//        int y = p%3;

////        if(not(grid[x][y]->isclaimed()))
////        {
////            if(t==n_t)
////            {
////                grid[x][y]->setPixmap(n.scaled(64,64,Qt::KeepAspectRatio,Qt::SmoothTransformation));
////            }
////            if(t==c_t)
////            {
////                grid[x][y]->setPixmap(c.scaled(64,64,Qt::KeepAspectRatio,Qt::SmoothTransformation));
////            }
////        }
//    }
//}

//void GameLogic::updateTurn()
//{
//    if(won<2)
//    {
//        if(won==n_w)
//        {
//            window->updateturn("noughts won!");
//        }
//        if(won==d_w)
//        {
//            window->updateturn("it's a draw!");
//        }
//        if(won==c_w)
//        {
//            window->updateturn("crosses won!");
//        }
//    }
//    else
//    {
//        if(t==n_t)
//        {
//            t=c_t;
//            window->updateturn("crosses turn!");
//        }
//        else if(t==c_t)
//        {
//            t=n_t;
//            window->updateturn("noughts turn!");
//        }
//    }
//}

//QPixmap GameLogic::getnought()
//{
//    return n;
//}

//QPixmap GameLogic::getcross()
//{
//    return c;
//}
