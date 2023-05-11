#include "gamepanel.h"
#include "qobjectdefs.h"
#include "ui_gamepanel.h"
#include<QTimerEvent>
#include<QTimer>
#include<QRandomGenerator>
#include<QtGlobal>
#include<QPainter>
#include<QPixmap>
#include<QPushButton>
#include<QPainter>
#include<iostream>
using namespace std;
GamePanel::GamePanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GamePanel)
{
    ui->setupUi(this);
    this->setWindowTitle("LoveLive!");
    this->setFixedSize(1900,1100);//设置窗口大小
    this->setWindowIcon(QIcon(":/Images/icon.png"));
    //设置按钮图案
    setButtonImage(ui->pushButton, ":/Images/hanayo.png");
    setButtonImage(ui->pushButton_2, ":/Images/maki.png");
    setButtonImage(ui->pushButton_3, ":/Images/rin.png");
    setButtonImage(ui->pushButton_4, ":/Images/kotori.png");
    setButtonImage(ui->pushButton_5, ":/Images/honoka.png");
    setButtonImage(ui->pushButton_6, ":/Images/umi.png");
    setButtonImage(ui->pushButton_7, ":/Images/eli.png");
    setButtonImage(ui->pushButton_8, ":/Images/nico.png");
    setButtonImage(ui->pushButton_9, ":/Images/nozomi.png");
    //设置初始背景
    QPixmap pixmap(":/Images/text1.png");
    int with = 800;
    int height = 666;
    QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->label_2->setPixmap(pixmap);
    ui->label_2->setPixmap(fitpixmap);
    ui->label_2->show();

    player= new QMediaPlayer(this);
    player->setMedia(QUrl("D:/QThomework/LoveLivesif/Music/hikaru.mp3"));
    player->setVolume(5);

    setButtonImage2(ui->pushButton_10, ":/Images/chouka.png");

    //点击按钮跳转抽卡
    connect(ui->pushButton_10,SIGNAL(clicked()),this,SLOT(gotorandompic()));
    //新建界面
    this->randomp=new Randompic;
    //设置信号方便界面间跳转
    connect(this->randomp,SIGNAL(gocards()),this,SLOT(gotocards()));
    connect(this->randomp,SIGNAL(gogamepanel(int)),this,SLOT(gotogamepanel(int)));

    this->card=new Cards;

    connect(this->card,SIGNAL(gobackgamepanel(int)),this,SLOT(gotogamepanel(int)));
    connect(this->card,SIGNAL(again()),this,SLOT(gotorandompic()));


}

GamePanel::~GamePanel()
{

}

void GamePanel::initgame()
{

    player->play();
}
//设置背景
void GamePanel::paintEvent(QPaintEvent *event)
{
    painter1 = new QPainter(this);

    QPixmap pic = QPixmap(":/Images/background.jpg");

    painter1->drawPixmap(0,0,this->width(),this->height(),pic);

}
void GamePanel::setButtonImage(QPushButton *button, QString image)
{
    button->setText("");
    QPixmap pixmap(image);
    QPixmap fitpixmap = pixmap.scaled(200, 200, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    button->setIcon(QIcon(fitpixmap));
    button->setIconSize(QSize(200, 200));
    button->setFlat(true);
    button->setStyleSheet("border: 0px");
}
void GamePanel::setButtonImage2(QPushButton *button, QString image)
{
    button->setText("");
    QPixmap pixmap(image);
    QPixmap fitpixmap = pixmap.scaled(200, 100, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    button->setIcon(QIcon(fitpixmap));
    button->setIconSize(QSize(260, 130));
    button->setFlat(true);
    button->setStyleSheet("border: 0px");
}

void GamePanel::on_pushButton_clicked()
{
    QPixmap pixmap(":/Images/hanayo1.jpg");
    int with = 1900;
    int height = 1100;
    QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->label->setPixmap(pixmap);
    ui->label->setPixmap(fitpixmap);
    ui->label->show();
}

void GamePanel::on_pushButton_2_clicked()
{
    QPixmap pixmap(":/Images/maki1.jpg");
    int with = 1900;
    int height = 1100;
    QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->label->setPixmap(pixmap);
    ui->label->setPixmap(fitpixmap);
    ui->label->show();

}


void GamePanel::on_pushButton_3_clicked()
{
    QPixmap pixmap(":/Images/rin1.jpg");
    int with = 1900;
    int height = 1100;
    QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->label->setPixmap(pixmap);
    ui->label->setPixmap(fitpixmap);
    ui->label->show();

}


void GamePanel::on_pushButton_4_clicked()
{
    QPixmap pixmap(":/Images/kotori1.jpg");
    int with = 1900;
    int height = 1100;
    QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->label->setPixmap(pixmap);
    ui->label->setPixmap(fitpixmap);
    ui->label->show();

}


void GamePanel::on_pushButton_5_clicked()
{
    QPixmap pixmap(":/Images/honoka1.jpg");
    int with = 1900;
    int height = 1100;
    QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->label->setPixmap(pixmap);
    ui->label->setPixmap(fitpixmap);
    ui->label->show();

}


void GamePanel::on_pushButton_6_clicked()
{
    QPixmap pixmap(":/Images/umi1.jpg");
    int with = 1900;
    int height = 1100;
    QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->label->setPixmap(pixmap);
    ui->label->setPixmap(fitpixmap);
    ui->label->show();

}


void GamePanel::on_pushButton_7_clicked()
{
    QPixmap pixmap(":/Images/eli1.jpg");
    int with = 1900;
    int height = 1100;
    QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->label->setPixmap(pixmap);
    ui->label->setPixmap(fitpixmap);
    ui->label->show();

}


void GamePanel::on_pushButton_8_clicked()
{
    QPixmap pixmap(":/Images/nico1.jpg");
    int with = 1900;
    int height = 1100;
    QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->label->setPixmap(pixmap);
    ui->label->setPixmap(fitpixmap);
    ui->label->show();

}


void GamePanel::on_pushButton_9_clicked()
{
    QPixmap pixmap(":/Images/nozomi1.jpg");
    int with = 1900;
    int height = 1100;
    QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->label->setPixmap(pixmap);
    ui->label->setPixmap(fitpixmap);
    ui->label->show();

}

//设置按钮效果
void GamePanel::on_pushButton_released()
{
    ui->pushButton->move(ui->pushButton->geometry().x(), ui->pushButton->geometry().y() - 6);
}


void GamePanel::on_pushButton_pressed()
{
    ui->pushButton->move(ui->pushButton->geometry().x(), ui->pushButton->geometry().y() + 6);
}


void GamePanel::on_pushButton_2_pressed()
{
     ui->pushButton_2->move(ui->pushButton_2->geometry().x(), ui->pushButton_2->geometry().y() + 6);
}


void GamePanel::on_pushButton_2_released()
{
     ui->pushButton_2->move(ui->pushButton_2->geometry().x(), ui->pushButton_2->geometry().y() - 6);
}


void GamePanel::on_pushButton_3_pressed()
{
  ui->pushButton_3->move(ui->pushButton_3->geometry().x(), ui->pushButton_3->geometry().y() + 6);
}


void GamePanel::on_pushButton_3_released()
{
     ui->pushButton_3->move(ui->pushButton_3->geometry().x(), ui->pushButton_3->geometry().y() - 6);
}


void GamePanel::on_pushButton_4_pressed()
{
     ui->pushButton_4->move(ui->pushButton_4->geometry().x(), ui->pushButton_4->geometry().y() + 6);
}


void GamePanel::on_pushButton_4_released()
{
     ui->pushButton_4->move(ui->pushButton_4->geometry().x(), ui->pushButton_4->geometry().y() - 6);
}


void GamePanel::on_pushButton_5_pressed()
{
     ui->pushButton_5->move(ui->pushButton_5->geometry().x(), ui->pushButton_5->geometry().y() + 6);
}


void GamePanel::on_pushButton_5_released()
{
     ui->pushButton_5->move(ui->pushButton_5->geometry().x(), ui->pushButton_5->geometry().y() - 6);
}


void GamePanel::on_pushButton_6_pressed()
{
     ui->pushButton_6->move(ui->pushButton_6->geometry().x(), ui->pushButton_6->geometry().y() + 6);
}


void GamePanel::on_pushButton_6_released()
{
     ui->pushButton_6->move(ui->pushButton_6->geometry().x(), ui->pushButton_6->geometry().y() - 6);
}


void GamePanel::on_pushButton_7_pressed()
{
     ui->pushButton_7->move(ui->pushButton_7->geometry().x(), ui->pushButton_7->geometry().y() + 6);
}


void GamePanel::on_pushButton_7_released()
{
     ui->pushButton_7->move(ui->pushButton_7->geometry().x(), ui->pushButton_7->geometry().y() - 6);
}


void GamePanel::on_pushButton_8_pressed()
{
     ui->pushButton_8->move(ui->pushButton_8->geometry().x(), ui->pushButton_8->geometry().y() + 6);
}


void GamePanel::on_pushButton_8_released()
{
     ui->pushButton_8->move(ui->pushButton_8->geometry().x(), ui->pushButton_8->geometry().y() - 6);
}


void GamePanel::on_pushButton_9_pressed()
{
     ui->pushButton_9->move(ui->pushButton_9->geometry().x(), ui->pushButton_9->geometry().y() + 6);
}


void GamePanel::on_pushButton_9_released()
{
     ui->pushButton_9->move(ui->pushButton_9->geometry().x(), ui->pushButton_9->geometry().y() - 6);
}


void GamePanel::on_pushButton_10_pressed()
{
     ui->pushButton_10->move(ui->pushButton_10->geometry().x(), ui->pushButton_10->geometry().y() + 4);
}


void GamePanel::on_pushButton_10_released()
{
     ui->pushButton_10->move(ui->pushButton_10->geometry().x(), ui->pushButton_10->geometry().y() - 4);
}

void GamePanel::gotocards()
{
     this->randomp->player->stop();
     this->card->choose(randomp->index);
     this->card->show();
     this->randomp->hide();
     this->hide();

}

void GamePanel::gotorandompic()
{
     this->randomp->playvideo();
     this->randomp->show();
     this->card->hide();
     this->hide();

}

void GamePanel::gotogamepanel(int)
{

     this->show();
     this->card->hide();
     this->randomp->hide();
}



