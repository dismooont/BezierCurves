#ifndef CLICKABLELABLE_H
#define CLICKABLELABLE_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

class ClickableLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ClickableLabel(const char* Text="",QWidget *parent = nullptr);

    ~ClickableLabel();
protected:
    virtual void mousePressEvent (QMouseEvent* Event);

signals:
    void Pressed();
signals:
};

#endif // CLICKABLELABLE_H
