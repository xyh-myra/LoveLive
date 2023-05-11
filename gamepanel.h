#ifndef GAMEPANEL_H
#define GAMEPANEL_H

#include <QWidget>

namespace Ui {
class GamePanel;
}
#define GAMEPANEL_H
#include<QPushButton>
#include <QWidget>
#include<QTimer>
#include<QLabel>
#include <deque>
#include<QMouseEvent>
#include<QPaintEvent>
#include"randompic.h"
#include"cards.h"
using namespace std;
class GamePanel : public QWidget
{
    Q_OBJECT
public:
    explicit GamePanel(QWidget *parent = nullptr);
        ~GamePanel();
    QPushButton* random;
    QMediaPlayer* player;
    QPainter *painter1;
    Cards* card;
    Randompic *randomp;
    void initgame();
    void paintEvent(QPaintEvent *event);
    void random_clicked();
    void setButtonImage(QPushButton *button, QString image);
    void setButtonImage2(QPushButton *button, QString image);
private:
    Ui::GamePanel *ui;

signals:
    void back();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_released();
    void on_pushButton_pressed();
    void on_pushButton_2_pressed();
    void on_pushButton_2_released();
    void on_pushButton_3_pressed();
    void on_pushButton_3_released();
    void on_pushButton_4_pressed();
    void on_pushButton_4_released();
    void on_pushButton_5_pressed();
    void on_pushButton_5_released();
    void on_pushButton_6_pressed();
    void on_pushButton_6_released();
    void on_pushButton_7_pressed();
    void on_pushButton_7_released();
    void on_pushButton_8_pressed();
    void on_pushButton_8_released();
    void on_pushButton_9_pressed();
    void on_pushButton_9_released();
    void on_pushButton_10_pressed();
    void on_pushButton_10_released();

    void gotocards(void);
    void gotorandompic(void);
    void gotogamepanel(int);
};

#endif // GAMEPANEL_H

