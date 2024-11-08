#include "widget.h"
#include "ui_widget.h"

#include <iostream>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //QBoxLayout *grid = new QBoxLayout(QBoxLayout::RightToLeft);




    pmap = QPixmap("C:/Users/dismooont/Downloads/11270197ba89e6cb1e0ee767c9ab322a.png");
    this->resize(500,900);

    stack = new QStackedLayout;
    QFrame *frameFirst = new QFrame;
    QFrame *frameSecond = new QFrame;
    QVBoxLayout *vbox = new QVBoxLayout;
    QGridLayout *firstLayout = new QGridLayout;
    firstLayout->setColumnStretch(0,0);
    firstLayout->setColumnStretch(1,0);
    firstLayout->setColumnStretch(2,0);
    firstLayout->setColumnStretch(3,0);
    firstLayout->setRowStretch(0,0);
    firstLayout->setRowStretch(1,0);
    firstLayout->setRowStretch(2,0);



    gbox = new QGroupBox("Выберите нужную вам тему");
    gbox->setFixedSize(QSize(400,850));
    QFont f;
    f.setFamily("Fantasy");
    f.setPointSize(16);
    gbox->setFont(f);

    QGridLayout *secondLayout = new QGridLayout;
    secondLayout->setColumnStretch(0,0);

    QPushButton *btn1 = new QPushButton("перейти");
    QPushButton *btn2 = new QPushButton("Вернуться");

    menuMath = new ClickableLabel;
    menuMath->setPixmap(QPixmap("C:/Users/dismooont/Pictures/Снимок экрана 2024-11-03 190810.png").scaled(200,200));
    menuMath->setGeometry(250,0,200,200);
    menuIt = new ClickableLabel("Coming Soon(IT)");
    menuPhys = new ClickableLabel("Coming soon(PHYS)");

    firstLayout->addWidget(menuMath,0,1);
    firstLayout->addWidget(menuIt,1,0);
    firstLayout->addWidget(menuPhys,1,2);
    firstLayout->addWidget(btn1,2,0,1,3);


    secondLayout->addWidget(gbox,0,0,3,1);
    secondLayout->addWidget(btn2,0,3,1,1);

    frameFirst->setLayout(firstLayout);
    frameSecond->setLayout(secondLayout);

    stack->addWidget(frameFirst);
    stack->addWidget(frameSecond);
    vbox->addLayout(stack);

    connect(btn1,&QPushButton::clicked,this,&Widget::bebeb);
    connect(menuMath,&ClickableLabel::Pressed,this,&Widget::bebeb);
    connect(btn2,&QPushButton::clicked,this,&Widget::bebeb);


    std::cout<<1;

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
        tempSize = this->size();
        tempPos = QSize(this->x(),this->y());
        this->setGeometry(100,100,1600,900);
    }
    else{
        stack->setCurrentIndex(0);
        this->setGeometry(tempPos.width(),tempPos.height()+40,tempSize.width(),tempSize.height());
    }

    qDebug()<<1;
}
void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<event->key();
    if(event->key() == Qt::Key_T){

        this->close();
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    isKeyPressed[ event->key() ] = 0;


}
void Widget::resizeEvent(QResizeEvent* event){
    qDebug()<<event->size();
    menuPhys->setGeometry(event->size().width()-menuPhys->size().width(),menuPhys->y(),menuPhys->width(),menuPhys->height());
}

