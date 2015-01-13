#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>

class QPushButton;
class QLabel;

class Interface : public QWidget
{
    Q_OBJECT
public:
    Interface(QWidget *parent = 0);
private:
    QPushButton *Up;
    QPushButton *Down;
    QPushButton *Left;
    QPushButton *Right;
    QPushButton *Up_Right;
    QPushButton *Up_Left;
    QPushButton *Down_Left;
    QPushButton *Down_Right;
    QLabel *IntHealth;
    QLabel *IntAttack;
    QLabel *Health;
    QLabel *Attack;
    QLabel *Status;
    int Player_health;
    int Player_attack;
public slots:
    void Int_Lost_Battle();
private slots :
    void game_end();
    void Win_game();
protected:
    virtual void keyPressEvent(QKeyEvent *);
signals:
    void clicked_up();
    void clicked_down();
    void clicked_right();
    void clicked_left();
    void clicked_up_left();
    void clicked_up_right();
    void clicked_down_left();
    void clicked_down_right();
    void Decrease_health(int);
    void Player_death();
    void Attack_chanched(int attack);
};

#endif // INTERFACE_H
