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
    void button_pressed();
    void game_end();
    void Win_game();
protected:
    virtual void keyPressEvent(QKeyEvent *);
signals:
    void change_posicion(int);
    void Decrease_health(int);
    void Player_death();
    void Attack_chanched(int attack);
};

#endif // INTERFACE_H
