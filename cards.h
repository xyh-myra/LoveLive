#ifndef CARDS_H
#define CARDS_H

#include <QPushButton>
#include <QWidget>
namespace Ui {
class Cards;
}

class Cards : public QWidget
{
    Q_OBJECT
private:
    //设置卡面地址
    char *c[54]={":/Images/1.jpeg",":/Images/2.jpeg",":/Images/3.png",":/Images/4.png",":/Images/5.jpeg",":/Images/6.jpeg",":/Images/7.jpeg",":/Images/8.png",":/Images/9.png",":/Images/10.png",":/Images/11.jpeg",":/Images/12.png",":/Images/13.png",":/Images/14.png",":/Images/15.png",":/Images/16.png",":/Images/17.png",":/Images/18.jpeg",":/Images/19.png",":/Images/20.png",":/Images/21.jpeg",":/Images/22.jpeg",":/Images/23.jpeg",":/Images/24.jpeg",":/Images/25.jpeg",":/Images/26.jpeg",":/Images/27.jpeg",":/Images/28.png",":/Images/29.png",":/Images/30.png",":/Images/31.png",":/Images/32.png",":/Images/33.png",":/Images/34.png",":/Images/35.png",":/Images/36.png",":/Images/37.jpeg",":/Images/38.jpeg",":/Images/39.jpeg",":/Images/40.jpeg",":/Images/41.jpeg",":/Images/42.jpeg",":/Images/43.jpeg",":/Images/44.jpeg",":/Images/45.jpeg",":/Images/46.jpeg",":/Images/47.png",":/Images/48.png",":/Images/49.png",":/Images/50.png",":/Images/51.png",":/Images/52.png",":/Images/53.png",":/Images/54.png"};
    public:
    explicit Cards(QWidget *parent = nullptr);
    ~Cards();
    void choose(int index);
    void setButtonImage(QPushButton *button, QString image);
    int slC1=0;

signals:

    void gobackgamepanel(int);
    void again(void);

private slots:
    void on_pushButton_2_pressed();

    void on_pushButton_2_released();

    void on_pushButton_pressed();

    void on_pushButton_released();

    void gogamepanel();

    void gorandompic();


private:
    Ui::Cards *ui;
};

#endif // CARDS_H
