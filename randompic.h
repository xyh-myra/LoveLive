#ifndef RANDOMPIC_H
#define RANDOMPIC_H
#include<QPushButton>
#include <QWidget>
#include<QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>
#include"cards.h"
namespace Ui {
class Randompic;
}

class Randompic : public QWidget
{
    Q_OBJECT

int slC=0;
public:
    explicit Randompic(QWidget *parent = nullptr);
    ~Randompic();
    void playvideo();
    QMediaPlayer *player;
    QVideoWidget* vw;
    Cards* card;
    QPushButton *btn;
    int index;
    static int count;
    void setButtonImage(QPushButton *button, QString image);
    void setButtonImage1 (QPushButton *button, QString image);


signals:

    void back();
    void gogamepanel(int);
    void gocards();

private slots:

    void on_pushButton_pressed();

    void on_pushButton_released();

    void gogamepanel(void);

    void getcard(void);


private:
    Ui::Randompic *ui;


};

#endif // RANDOMPIC_H
