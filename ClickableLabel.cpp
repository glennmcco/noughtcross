#include "ClickableLabel.h"

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent)
{
    panel = -1;
    claimedby=d_w;
}

ClickableLabel::~ClickableLabel()
{

}

void ClickableLabel::mousePressEvent(QMouseEvent* event)
{
    emit clicked(panel);
    //emit clicked();
}

void ClickableLabel::setPanel(int p)
{
    panel = p;
}

bool ClickableLabel::isclaimed()
{
    return not(claimedby==d_w);
}


