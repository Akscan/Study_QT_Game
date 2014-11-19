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
#define size 20
#define size_map_height 540
#define size_map_weight 480
#define region_play_max_x 480
#define region_play_max_y 420
#define region_play_min_x 20
#define region_play_min_y 20
Map::Map(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(540,480);//540 480

    setPalette(QPalette(QColor(Qt::white)));
    setAutoFillBackground(true);
    player_pos_x = 20;
    player_pos_y = 20;
    Hero.load("Hero.bmp");
    Wall.load("Wall.bmp");
    Enemy.load("Enemy.bmp");
    connect(this,SIGNAL(value_changed_down()),this,SLOT(move_down()));
    connect(this,SIGNAL(value_changed_up()),this,SLOT(move_up()));
    connect(this,SIGNAL(value_changed_right()),this,SLOT(move_right()));
    connect(this,SIGNAL(value_changed_left()),this,SLOT(move_left()));
    connect(this,SIGNAL(value_changed_up_left()),this,SLOT(move_up_left()));
    connect(this,SIGNAL(value_changed_down_left()),this,SLOT(move_down_left()));
    connect(this,SIGNAL(value_changed_up_right()),this,SLOT(move_up_right()));
    connect(this,SIGNAL(value_changed_down_right()),this,SLOT(move_down_right()));
    enemy_generation();
}



void Map::paintEvent(QPaintEvent */*event*/)
{
    QPoint point(player_pos_x,player_pos_y);
    QPainter painter(this);
    painter.drawPixmap(point,Hero);
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

}



void Map::move_down()
{
   player_pos_y+=size;
   if(player_pos_y>region_play_max_y)
       player_pos_y -=size;
   battle();
   update();
}
void Map::move_up()
{
   player_pos_y-=size;
   if(player_pos_y<region_play_min_y)
       player_pos_y += size;
   battle();
   update();
}
void Map::move_right()
{
   player_pos_x+=size;
   if(player_pos_x>region_play_max_x)
       player_pos_x -= size;
   battle();
   update();
}
void Map::move_left()
{
   player_pos_x-=size;
   if(player_pos_x<region_play_min_x)
       player_pos_x+= size;
   battle();
   update();
}
void Map::move_up_left()
{
    player_pos_x -=size;
    player_pos_y -=size;
    if(player_pos_x<region_play_min_x || player_pos_y < region_play_min_y)
    {
        player_pos_x+=size;
        player_pos_y+=size;
    }
    battle();
    update();
}
void Map::move_up_right()
{
    player_pos_x +=size;
    player_pos_y -=size;
    if(player_pos_x>region_play_max_x || player_pos_y<region_play_min_y)
    {
        player_pos_x -= size;
        player_pos_y += size;
    }
    battle();
    update();
}
void Map::move_down_left()
{
    player_pos_x -=size;
    player_pos_y +=size;
    if(player_pos_x<region_play_min_x || player_pos_y>region_play_max_y)
    {
        player_pos_x += size;
        player_pos_y -= size;
    }
    battle();
    update();
}
void Map::move_down_right()
{
    player_pos_x +=size;
    player_pos_y +=size;
    if(player_pos_x>region_play_max_x || player_pos_y > region_play_max_y)
    {
        player_pos_x-=size;
        player_pos_y-=size;
    }
    battle();
    update();
}

void Map::enemy_generation()
{
    srand(time(0));
    for(int i = 0; i<number_enemy; i++)
    {
        enemy_pos_x[i] = rand()%region_play_max_x;
        enemy_pos_y[i] = rand()%region_play_max_y;
        for(int k=0;k<size;k++)
        {
            if(enemy_pos_x[i]%size!=0)
            {
                enemy_pos_x[i]++;
            }
            if(enemy_pos_y[i]%size!=0)
            {
                enemy_pos_y[i]++;
            }

        }
    }
    for(int i=0;i<number_enemy;i++)
    {
        for(int j=0;j<number_enemy;j++)
        {
            if(enemy_pos_x[i]==enemy_pos_x[j] && enemy_pos_y[i]==enemy_pos_y[j])
            {
                if(i!=j)
                    enemy_generation();
            }
        }
    }
}

void Map::battle()
{
    for(int i = 0;i < number_enemy; i++)
    {
        if(player_pos_x == enemy_pos_x[i] && player_pos_y == enemy_pos_y[i])
        {
            int temp;
            temp = rand()%20;
            if(temp < 5)
            {
                emit Map_Lost_battle();
            }
            else
            {

            }
        }
    }
}

