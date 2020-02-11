#include "ClickableLabel.h"

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent)
{
    panel = -1;
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


