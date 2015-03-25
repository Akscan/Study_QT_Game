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

#define default_health 100;
#define size 20
#define size_map_height 540
#define size_map_weight 480
#define region_play_max_x 480
#define region_play_max_y 420
#define region_play_min_x 20
#define region_play_min_y 20
int sword_attack = 0;
int status = 0;
int player_pos_x = 20;
int player_pos_y = 20;
int battle_enemy = 0;

Map::Map(QWidget *parent)
    : QWidget(parent)
{
    num_enemy = 10;
    hero_status = 0;
    player_attack = 10;
    setFixedSize(540,480);//540 480
    setPalette(QPalette(QColor(Qt::white)));
    setAutoFillBackground(true);
    player = new Hero;
    Hero_Image.load("Hero.bmp");
    Hero_Sword.load("Hero_Sword.bmp");
    Wall.load("Wall.bmp");
    Enemy.load("Enemy.bmp");
    Sword.load("Sword.bmp");
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
    if(hero_status == 0)
        painter.drawPixmap(point,Hero_Image);
    if(hero_status == 1)
    {
       sword_attack = 10;
       Attack_changed(sword_attack+player_attack);
       painter.drawPixmap(point,Hero_Sword);
    }
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

void Map::move_down()
{
    status = 1;
   player_pos_y+=size;
   if(player_pos_y>region_play_max_y)
       player_pos_y -=size;
   battle();
   update();
}
void Map::move_up()
{
    status = 2;
   player_pos_y-=size;
   if(player_pos_y<region_play_min_y)
       player_pos_y += size;
   battle();
   update();
}
void Map::move_right()
{
    status = 3;
   player_pos_x+=size;
   if(player_pos_x>region_play_max_x)
       player_pos_x -= size;
   battle();
   update();
}
void Map::move_left()
{
    status = 4;
   player_pos_x-=size;
   if(player_pos_x<region_play_min_x)
       player_pos_x+= size;
   battle();
   update();
}
void Map::move_up_left()
{
    status = 5;
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
    status = 6;
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
    status = 7;
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
    status = 8;
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
        enemy_health[i] = default_health;
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
    if(player_pos_x == 40 && player_pos_y == 40)
        hero_status = 1;
    for(int i = 0;i < number_enemy; i++)
    {
        if(player_pos_x == enemy_pos_x[i] && player_pos_y == enemy_pos_y[i])
        {
            battle_enemy = i;
            int battle_res;
            battle_res = rand()%20;
            if(battle_res < 10)
            {
                if(status == 1)
                {
                    player_pos_y-=size;
                }
                if(status == 2)
                {
                    player_pos_y+=size;
                }
                if(status == 3)
                {
                    player_pos_x-=size;
                }
                if(status == 4)
                {
                    player_pos_x+=size;
                }
                if(status == 5)
                {
                    player_pos_x +=size;
                    player_pos_y +=size;
                }
                if(status == 6)
                {
                    player_pos_x -=size;
                    player_pos_y +=size;
                }
                if(status == 7)
                {
                    player_pos_x +=size;
                    player_pos_y -=size;
                }
                if(status == 8)
                {
                    player_pos_x -=size;
                    player_pos_y -=size;
                }
                emit Map_Lost_battle();
            }
            else
            {
                enemy_health[battle_enemy] -= player_attack + sword_attack;
                if(enemy_health[battle_enemy] == 0 || enemy_health[battle_enemy] < 0)
                {
                    num_enemy--;
                    enemy_pos_x[battle_enemy] = -20;
                    enemy_pos_y[battle_enemy] = -20;
                }
                else
                {
                    if(status == 1)
                    {
                        player_pos_y-=size;
                    }
                    if(status == 2)
                    {
                        player_pos_y+=size;
                    }
                    if(status == 3)
                    {
                        player_pos_x-=size;
                    }
                    if(status == 4)
                    {
                        player_pos_x+=size;
                    }
                    if(status == 5)
                    {
                        player_pos_x +=size;
                        player_pos_y +=size;
                    }
                    if(status == 6)
                    {
                        player_pos_x -=size;
                        player_pos_y +=size;
                    }
                    if(status == 7)
                    {
                        player_pos_x +=size;
                        player_pos_y -=size;
                    }
                    if(status == 8)
                    {
                        player_pos_x -=size;
                        player_pos_y -=size;
                    }
                }
                if(num_enemy == 0)
                {
                    emit Win_game();
                }
            }
        }
    }
}

