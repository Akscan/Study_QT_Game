#ifndef HERO_H
#define HERO_H
#include <QWidget>
class QPixmap;
class Hero : public QWidget
{
    Q_OBJECT
public:
    Hero(QWidget *parent = 0);
    int get_pos_x();
    int get_pos_y();
    QPixmap get_symbol();
private:
    int     pos_x;
    int     pos_y;
    int     health;
    int     attack;
    QPixmap symbol;
signals:
    void move(int);
private slots:
    void press_move_up();
    void press_move_down();
    void press_move_right();
    void press_move_left();
    void press_move_up_left();
    void press_move_up_right();
    void press_move_down_left();
    void press_move_down_right();
};

#endif // HERO_H
