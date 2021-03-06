#ifndef MAP_H
#define MAP_H

#include <QWidget>
#define map_height 20
#define map_weight 20
#define number_enemy 10

class QLabel;
class QPushButton;
class QImage;
class QPixmap;
class Hero;
class Map : public QWidget
{
    Q_OBJECT

public:
    Map(QWidget *parent = 0);
    void enemy_generation();
protected:
    void paintEvent(QPaintEvent *);
//    bool event(QEvent *);
private:
    void battle();
    Hero *player;
    QPixmap Wall;
    QPixmap Hero_Image;
    QPixmap Enemy;
    QPixmap Sword;
    QPixmap Hero_Sword;
    int enemy_pos_x[number_enemy];
    int enemy_pos_y[number_enemy];
    int enemy_health[number_enemy];
    int player_attack;
    int hero_status;
    int num_enemy;
public slots:
    void move_down();
    void move_up();
    void move_right();
    void move_left();
    void move_up_left();
    void move_up_right();
    void move_down_left();
    void move_down_right();
signals:
    void value_changed_down();
    void value_changed_up();
    void value_changed_right();
    void value_changed_left();
    void value_changed_up_left();
    void value_changed_up_right();
    void value_changed_down_left();
    void value_changed_down_right();
    void Map_Lost_battle();
    void Win_game();
    void Attack_changed(int);
};



#endif // MAP_H
