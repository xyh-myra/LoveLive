#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include<QPushButton>
#include"gamepanel.h"
#include <QPushButton>
#include<QPainter>
#include<QPixmap>
#include<QMediaPlayer>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget

{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent *event);
    QMediaPlayer* player;
    void setButtonImage(QPushButton *button, QString image);


private:
    Ui::Widget *ui;
    QPushButton* b1;
    GamePanel *game;

};

#endif // WIDGET_H
