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
    //emit clicked with panel location of label
    emit clicked(panel);
}

void ClickableLabel::setPanel(int p)
{
    //panel location of label
    panel = p;
}


