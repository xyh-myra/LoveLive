#include"gamepanel.h"
#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include<QPainter>
#include<QPixmap>
#include<QUrl>
#include<QWidget>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    ui->setupUi(this);

    b1=new QPushButton(this);
    setButtonImage(b1,":/Images/button.png");//设置按钮图片
    b1->show();
    b1->move(800,780);//设置按钮位置
    b1->resize(250,85);//设置按钮大小
    this->setWindowTitle("LoveLive!");//设置窗口文字
    this->setFixedSize(1900,1100);//设置窗口大小
    this->setWindowIcon(QIcon(":/Images/icon.png"));//设置窗口图标
    //新建游戏
    game=new GamePanel();

    player= new QMediaPlayer(this);//设置播放器
    player->setMedia(QUrl("D:/QThomework/LoveLivesif/Music/kiseki.mp3"));//从本地文件中读取音乐
    player->setVolume(10);//设置音量
    player->play();//开始播放
    //新面板打开,初始化游戏
    connect(b1,&QPushButton::clicked,game,&QWidget::show);
    connect(b1,&QPushButton::clicked,game,[=](){game->initgame();});
    //音乐暂停，窗口关闭
    connect(b1,&QPushButton::clicked,this,[=](){player->stop();});
    connect(b1,&QPushButton::clicked,this,[=](){this->hide();});



}

Widget::~Widget()
{
    delete ui;
}
//设置背景
void Widget::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);

    QPixmap pic = QPixmap(":/Images/login.png");

    painter->drawPixmap(0,0,this->width(),this->height(),pic);

}
//设置按钮图案
void Widget::setButtonImage(QPushButton *button, QString image)
{
    button->setText("");
    QPixmap pixmap(image);
    QPixmap fitpixmap = pixmap.scaled(250, 85, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    button->setIcon(QIcon(fitpixmap));
    button->setIconSize(QSize(250, 85));
    button->setFlat(true);
    button->setStyleSheet("border: 0px"); //消除边框
}


