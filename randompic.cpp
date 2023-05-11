#include "randompic.h"
#include "ui_randompic.h"
#include<QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>
#include<QRandomGenerator>
#include<QTimer>
#include"cards.h"
#include<iostream>
using namespace std;
Randompic::Randompic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Randompic)
{
    ui->setupUi(this);
    this->setWindowTitle("LoveLive!");
    this->setFixedSize(1500,1150);
    this->setWindowIcon(QIcon(":/Images/icon.png"));

    setButtonImage1(ui->pushButton,":/Images/confirm.png");

    QPushButton *btn = new QPushButton(this);
    setButtonImage(btn,":/Images/goback.png");
     //界面之间跳转所用的信号
    connect(btn,SIGNAL(clicked()),this,SLOT(gogamepanel()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(getcard()));




}
int Randompic::count=0;//初始化抽卡次数
//抽卡视频播放
void Randompic::playvideo()
{
    //用随机数随机抽卡概率
    index=QRandomGenerator::global()->bounded(100);
    if(index==0)//UR的概率1％
    {
        if(count==0)
        {
            player= new QMediaPlayer(this);//设置播放器
            vw=new QVideoWidget(this);//设置播放器所在的页面
        }
        vw->show();
        ui->verticalLayout->addWidget(vw);
        player->setVideoOutput(vw);
        player->setMedia(QUrl("D:/QThomework/LoveLivesif/Video/UR1.mp4"));
        player->play();
        player->setVolume(6);
        count++;


    }
    else if(index<21)//SR的概率20％
    {
        if(count==0)
        {
            player= new QMediaPlayer(this);
            vw=new QVideoWidget(this);
        }
        player->setVideoOutput(vw);
        vw->show();
        ui->verticalLayout->addWidget(vw);
        player->setMedia(QUrl("D:/QThomework/LoveLivesif/Video/SR1.mp4"));
        player->play();
        player->setVolume(6);
        count++;
    }
    else//R的概率79％
    {
        if(count==0)
        {
            player= new QMediaPlayer(this);
            vw=new QVideoWidget(this);
        }
        player->setVideoOutput(vw);
        player->setMedia(QUrl::fromLocalFile("D:/QThomework/LoveLivesif/Video/R1.mp4"));
        vw->show();
        player->play();
        ui->verticalLayout->addWidget(vw);
        player->setVolume(6);
        count++;
    }

}

Randompic::~Randompic()
{
    delete ui;
}
void Randompic::setButtonImage(QPushButton *button, QString image)
{
    button->setText("");
    QPixmap pixmap(image);
    QPixmap fitpixmap = pixmap.scaled(80, 50, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    button->setIcon(QIcon(fitpixmap));
    button->setIconSize(QSize(80, 50));
    button->setFlat(true);
    button->setStyleSheet("border: 0px"); //消除边框
}

void Randompic::setButtonImage1(QPushButton *button, QString image)
{
    button->setText("");
    QPixmap pixmap(image);
    QPixmap fitpixmap = pixmap.scaled(410, 94, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    button->setIcon(QIcon(fitpixmap));
    button->setIconSize(QSize(410, 94));
    button->setFlat(true);
    button->setStyleSheet("border: 0px"); //消除边框
}

void Randompic::on_pushButton_pressed()
{
      ui->pushButton->move(ui->pushButton->geometry().x(), ui->pushButton->geometry().y() + 4);
}


void Randompic::on_pushButton_released()
{
      ui->pushButton->move(ui->pushButton->geometry().x(), ui->pushButton->geometry().y() - 4);
}

void Randompic::gogamepanel()
{
      this->slC++;
      emit gogamepanel(this->slC);

}

void Randompic::getcard()
{
      emit gocards();
}

