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
    int hero_status;
    int num_enemy;
public slots:
signals:
};



#endif // MAP_H
