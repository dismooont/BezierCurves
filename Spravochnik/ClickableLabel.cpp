#include "ClickableLabel.h"

ClickableLabel::ClickableLabel(const char* Text,QWidget *parent)
    : QLabel{parent}
{
    this->setText(Text);

}
void  ClickableLabel::mousePressEvent (QMouseEvent* Event)
{
    if(Qt::LeftButton & Event->buttons()){
        emit Pressed();}
}

ClickableLabel::~ClickableLabel(){

}
