#include "Hero.h"
#include <QPixmap>
#define size 20
#define size_map_height 540
#define size_map_weight 480
#define region_play_max_x 480
#define region_play_max_y 420
#define region_play_min_x 20
#define region_play_min_y 20
Hero::Hero(QWidget *parent)
    :QWidget(parent)
{
    pos_x  = 20;
    pos_y  = 20;
    health = 10;
    attack = 1;
    symbol.load("Hero.bmp");
}
void Hero::press_move_down()
{
    pos_y += size;
    if(pos_y>region_play_max_y)
        pos_y -= size;
    emit move(1);
}
void Hero::press_move_up()
{
    pos_y -= size;
    if(pos_y<region_play_min_y)
        pos_y += size;
    emit move(2);
}
void Hero::press_move_left()
{
    pos_x += size;
    if(pos_x > region_play_max_x)
        pos_x -= size;
    emit move(3);
}
void Hero::press_move_right()
{
    pos_x -= size;
    if(pos_x < region_play_min_x)
        pos_x += size;
    emit move(4);
}
void Hero::press_move_up_left()
{
    pos_x -= size;
    pos_y -= size;
    if(pos_x<region_play_min_x && pos_y < region_play_min_y)
    {
        pos_x += size;
        pos_y += size;
    }
    emit move(5);
}
void Hero::press_move_up_right()
{
    pos_x += size;
    pos_y -= size;
    if(pos_x > region_play_max_x && pos_y < region_play_min_y)
    {
        pos_x -= size;
        pos_y += size;
    }
    emit move(6);
}
void Hero::press_move_down_left()
{
    pos_x -= size;
    pos_y += size;
    if(pos_x < region_play_min_x && pos_y > region_play_max_y)
    {
        pos_x += size;
        pos_y -= size;
    }
    emit move(7);

}
void Hero::press_move_down_right()
{
    pos_x += size;
    pos_y += size;
    if(pos_x > region_play_max_x && pos_y > region_play_max_y)
    {
        pos_x -= size;
        pos_y -= size;
    }
    emit move(8);
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
