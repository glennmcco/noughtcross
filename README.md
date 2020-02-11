# noughtcross
Noughts and Crosses game built in Qt framework

Version: 0.8
Title: noughtscross
Author: Glenn McConnell
Last Update: 11/02/2020

Description: Runs a QWidget extension which initialises itself to a splash Screen
        where the player can choose to start a game of noughts and crosses allowing
        them to play games while retaining the overall score.

Classes:
        ClickableLabel: extends QLable with the clicked() signal and contains
                        variable for storing panel position in the game grid
        GameOn:         extends QWidget with 2 QWidgets representing the mainscreen
                         and the game screen. Handles all the game logic and win
                         conditions as some minor manipulation of the GUI it codes for.

Resources:  filename                    Type            Description
            cross-01.png                Image           wireframe for cross icon
            nought-01.png               Image           wireframe for nought icon
            RobotoCondensed-Bold.ttf    fonts           Font for bold weight Roboto Condensed
            RobotoCondensed-Regular.ttf fonts           Font for regular weight Roboto Condensed

Change Log:
        V0.1: Lables and Layouts
        V0.2: Stylesheets and Pixmaps
        V0.3: Spacing the Layouts & scaling picture labels
        V0.4: Home Screen with button importing fonts
        V0.5: Added Gamescreen, encapsulated functionality in QWidget subclass gameon
        V0.6: Implemented Clickable Labels and gamescreen borders
        V0.7: Game Logic class
        V0.8: added gameplay, reduced responsibilities of Game Logic Class, encapsulated mainscreen layout
        V0.9: back and new game, horizontal win states functioning correctly
