#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>

//#include "gamelogic.h"
#include "gameon.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ClickableLabel; }
QT_END_NAMESPACE

class ClickableLabel : public QLabel
{
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~ClickableLabel();
    void setPanel(int p);

signals:
    void clicked(int p);

protected:
    void mousePressEvent(QMouseEvent* event);

private:
    uint8_t panel;

};

#endif // CLICKABLELABEL_H
