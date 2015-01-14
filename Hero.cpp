#include "Hero.h"
#include <QPixmap>
#include <QString>
#define size 20
#define size_map_height 540
#define size_map_weight 480
#define region_play_max_x 480
#define region_play_max_y 420
#define region_play_min_x 20
#define region_play_min_y 20
Hero::Hero(QString path,QWidget *parent)
    :QWidget(parent)
{
    pos_x  = 20;
    pos_y  = 20;
    health = 10;
    attack = 1;
    symbol.load(path);
}
int Hero::get_pos_x()
{
    return pos_x;
}
int Hero::get_pos_y()
{
    return pos_y;
}
QPixmap Hero::get_symbol()
{
    return symbol;
}
void Hero::move(int status)
{
    if(status == 1)//Движение вверх-лево
    {
        pos_x -= size;
        pos_y -= size;
    }
    if(status == 2)//Движение вверх
    {
        pos_y -= size;
    }
    if(status == 3)//Движение вверх-право
    {
        pos_x += size;
        pos_y -= size;
    }
    if(status == 4)//Движение лево
    {
        pos_x -= size;
    }
    if(status == 5)//Движение право
    {
        pos_x += size;
    }
    if(status == 6)//Движение низ-лево
    {
        pos_x -= size;
        pos_y += size;
    }
    if(status == 7)//Движение низ
    {
        pos_y += size;
    }
    if(status == 8)//Движение низ-право
    {
        pos_x += size;
        pos_y += size;
    }

}
