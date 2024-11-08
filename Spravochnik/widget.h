#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QPushButton>
#include <QKeyEvent>
#include <QSlider>
#include <QPixMap>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <ClickableLabel.h>
#include <QStackedLayout>
#include <QFrame>
#include <QGroupBox>
#include <Qtimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    bool isKeyPressed[255];
    Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:



    void bebeb();
protected:
    virtual void resizeEvent(QResizeEvent* event);
    virtual void paintEvent(QPaintEvent* event);
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void keyReleaseEvent(QKeyEvent *event);//событие перерисовки
private:
    ClickableLabel *menuMath,*menuIt,*menuPhys;
    QPushButton *btn1,*btn2;
    QPixmap pmap;
    QStackedLayout *stack;
    QSize tempPos,tempSize;
    QGroupBox *gbox;
    Ui::Widget *ui;
};
#endif // WIDGET_H
