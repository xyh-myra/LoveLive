#include "cards.h"
#include "qtimer.h"
#include "ui_cards.h"
#include<QRandomGenerator>
#include<QtGlobal>
#include<QPainter>
#include<QPixmap>
Cards::Cards(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cards)
{
    ui->setupUi(this);
    this->setWindowTitle("LoveLive!");
    this->setFixedSize(800,1280);
    this->setWindowIcon(QIcon(":/Images/icon.png"));
    setButtonImage(ui->pushButton,":/Images/ok.png");
    setButtonImage(ui->pushButton_2,":/Images/again.png");

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(gogamepanel()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(gorandompic()));

}

Cards::~Cards()
{
    delete ui;
}
//确定卡型随机卡面
void Cards::choose(int index)
{
    int num=0;
    if(index==0)//从UR卡池中随机抽取一张卡
    {
        num=QRandomGenerator::global()->bounded(9);
        QPixmap pixmap(c[num+27]);
        int with = 800;
        int height = 1120;
        QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->label->setPixmap(pixmap);
        ui->label->setPixmap(fitpixmap);
        ui->label->show();

    }
    else if(index<21)
    {
        num=QRandomGenerator::global()->bounded(27);
        QPixmap pixmap(c[num]);
        int with = 800;
        int height = 1120;
        QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->label->setPixmap(pixmap);
        ui->label->setPixmap(fitpixmap);
        ui->label->show();
    }
    else
    {
        num=QRandomGenerator::global()->bounded(27);
        QString p(c[num+36]);
        QPixmap pixmap(p);
        int with = 800;
        int height = 1120;
        QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->label->setPixmap(pixmap);
        ui->label->setPixmap(fitpixmap);
        ui->label->show();

    }

}
void Cards::setButtonImage(QPushButton *button, QString image)
{
    button->setText("");
    QPixmap pixmap(image);
    QPixmap fitpixmap = pixmap.scaled(300, 75, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    button->setIcon(QIcon(fitpixmap));
    button->setIconSize(QSize(300, 75));
    button->setFlat(true);
    button->setStyleSheet("border: 0px"); //消除边框
}

void Cards::on_pushButton_2_pressed()
{
      ui->pushButton_2->move(ui->pushButton_2->geometry().x(), ui->pushButton_2->geometry().y() + 4);
}


void Cards::on_pushButton_2_released()
{
      ui->pushButton_2->move(ui->pushButton_2->geometry().x(), ui->pushButton_2->geometry().y() - 4);
}


void Cards::on_pushButton_pressed()
{
      ui->pushButton->move(ui->pushButton->geometry().x(), ui->pushButton->geometry().y() + 4);
}


void Cards::on_pushButton_released()
{
      ui->pushButton->move(ui->pushButton->geometry().x(), ui->pushButton->geometry().y() - 4);
}

void Cards::gogamepanel()
{
      this->slC1++;
      emit gobackgamepanel(this->slC1);

}

void Cards::gorandompic()
{
      emit again();

}

