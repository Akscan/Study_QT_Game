#include "map.h"
#include "Interface.h"
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QPainter>
#include <QLine>
#include <QPicture>
#include <QPaintEvent>
#include <QImage>
#include <QPoint>
#include <ctime>
#include "Hero.h"

#define size 20
#define size_map_height 540
#define size_map_weight 480
#define region_play_max_x 480
#define region_play_max_y 420
#define region_play_min_x 20
#define region_play_min_y 20

int status = 0;
int player_pos_x = 20;
int battle_enemy = 0;

Map::Map(QWidget *parent)
    : QWidget(parent)
{
    num_enemy = 10;
    hero_status = 0;
    setFixedSize(540,480);//540 480
    setPalette(QPalette(QColor(Qt::white)));
    setAutoFillBackground(true);
    player = new Hero;
    Hero_Image.load("Hero.bmp");
    Hero_Sword.load("Hero_Sword.bmp");
    Wall.load("Wall.bmp");
    Enemy.load("Enemy.bmp");
    Sword.load("Sword.bmp");
    enemy_generation();
}

void Map::paintEvent(QPaintEvent */*event*/)
{
    QPoint point(player->get_pos_x(),player->get_pos_y());
    QPainter painter(this);
    if(hero_status == 0)
        painter.drawPixmap(point,Hero_Image);
    if(hero_status == 1)
        painter.drawPixmap(point,Hero_Sword);
    for(int i=0;i<=size_map_height;i+=size)
    {
        for(int j = 0; j <=size_map_weight; j+=size)
        {
            if(i==0 || j==0 || i>size_map_height - size*3 || j>size_map_weight - size*3)//"*3" обусловлено размерами 2-х стен(40 пикселей) + размер игрока(20 пикселей),
            {
                QPoint points(i,j);
                painter.drawPixmap(points,Wall);
            }
        }
    }
    for(int i=0;i<number_enemy;i++)
    {
        QPoint point_enemy(enemy_pos_x[i],enemy_pos_y[i]);
        painter.drawPixmap(point_enemy,Enemy);
    }
    if(hero_status!=1)
    {
        point.setX(40);
        point.setY(40);
        painter.drawPixmap(point,Sword);
    }

}
