//#ifndef GAMELOGIC_H
//#define GAMELOGIC_H

//#include <QObject>
//#include <QPixmap>

//enum Turn {n_t= 0, c_t = 1};
//enum WinCon {n_w=-1, d_w=0, c_w=1};

//QT_BEGIN_NAMESPACE
//namespace Ui { class GameLogic; }
//QT_END_NAMESPACE

//class GameOn;
//class ClickableLabel;

//class GameLogic : public QObject
//{
//    Q_OBJECT

//public:
//    explicit GameLogic(QObject *parent = nullptr);

//    void setWindow(GameOn g);

//    static QPixmap getnought();
//    static QPixmap getcross();

//    ClickableLabel *getPanel(int p);

//private:
//    static int won;
//    static Turn t;
//    static GameOn *window;

//    ClickableLabel *grid[3][3];

//    //PixMaps for storing icons
//    static QPixmap n;
//    static QPixmap c;

//    void whosTurn();
//    void updateTurn();

//private slots:
//        void updatePanel(int p);

//};

//#endif // GAMELOGIC_H
