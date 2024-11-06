#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //QBoxLayout *grid = new QBoxLayout(QBoxLayout::RightToLeft);

    pmap = QPixmap("C:/Users/dismooont/Downloads/11270197ba89e6cb1e0ee767c9ab322a.png");
    this->resize(1600,900);

    QStackedLayout *stack = new QStackedLayout;
    QFrame *frameFirst = new QFrame;
    QFrame *frameSecond = new QFrame;
    QVBoxLayout *vbox = new QVBoxLayout;
    QHBoxLayout *firstLayout = new QHBoxLayout;
    QHBoxLayout *secondLayout = new QHBoxLayout;

    QPushButton *btn1 = new QPushButton("перейти");
    QPushButton *btn2 = new QPushButton("Вернуться");

    secondLayout->addWidget(btn2);

    frameFirst->setLayout(firstLayout);
    frameSecond->setLayout(secondLayout);

    stack->addWidget(frameFirst);
    stack->addWidget(frameSecond);
    vbox->addLayout(stack);
    vbox->addWidget(btn1);
    connect(btn1,&QPushButton::clicked,this,&Widget::bebeb);
    connect(btn2,&QPushButton::clicked,this,&Widget::bebeb);

    setLayout(vbox);
}

Widget::~Widget()
{
    delete ui;

}

void Widget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event)

    QPainter painter(this); //создали объект рисования
    painter.setRenderHint(QPainter::Antialiasing, false);
    QPen pen(Qt::black);
    pen.setWidth(5);

    QBrush brush(Qt::white, Qt::SolidPattern); //параметры кисти
    painter.fillRect(this->rect(), brush);     //заливка окна кистью
    painter.drawRect(this->rect());            //рамка виджета

    painter.drawPixmap(QPoint(0,0),pmap.scaled((QSize(this->size()))));

}
void Widget::bebeb(){
    if(stack->currentIndex()==0){
        stack->setCurrentIndex(1);
    }
    else{
        stack->setCurrentIndex(0);
    }

}
void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() & Qt::Key_T){

        this->close();
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    isKeyPressed[ event->key() ] = 0;
}
