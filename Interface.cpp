#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QKeyEvent>
#include "Interface.h"
Interface::Interface(QWidget *parent)
    :QWidget(parent)
{
    Up = new QPushButton("&w");
    Down = new QPushButton("&x");
    Right = new QPushButton("&d");
    Left = new QPushButton("&a");
    Up_Left = new QPushButton("&q");
    Up_Right = new QPushButton("&e");
    Down_Left = new QPushButton("&z");
    Down_Right = new QPushButton("&c");
    Up_Left = new QPushButton("&q");
    Up_Right = new QPushButton("&e");
    Down_Right = new QPushButton("&c");
    Down_Left = new QPushButton("&z");
    IntHealth = new QLabel("HP");
    IntAttack = new QLabel("Atack");
    Health = new QLabel;
    Attack = new QLabel;
    Player_attack = 1;
    Player_health = 10;
    Attack->setNum(Player_attack);
    Health->setNum(Player_health);
    Status = new QLabel;

    connect(Down,SIGNAL(clicked()),this,SLOT(button_pressed()));
    connect(Up,SIGNAL(clicked()),this,SLOT(button_pressed()));
    connect(Right,SIGNAL(clicked()),this,SLOT(button_pressed()));
    connect(Left,SIGNAL(clicked()),this,SLOT(button_pressed()));
    connect(Up_Left,SIGNAL(clicked()),this,SLOT(button_pressed()));
    connect(Up_Right,SIGNAL(clicked()),this,SLOT(button_pressed()));
    connect(Down_Left,SIGNAL(clicked()),this,SLOT(button_pressed()));
    connect(Down_Right,SIGNAL(clicked()),this,SLOT(button_pressed()));
    connect(this,SIGNAL(Decrease_health(int)),Health,SLOT(setNum(int)));
    connect(this,SIGNAL(Attack_chanched(int)),Attack,SLOT(setNum(int)));
    connect(this,SIGNAL(Player_death()),this,SLOT(game_end()));
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(Up,0,1);
    layout->addWidget(Left,1,0);
    layout->addWidget(Right,1,2);
    layout->addWidget(Down,2,1);
    layout->addWidget(Up_Left,0,0);
    layout->addWidget(Up_Right,0,2);
    layout->addWidget(Down_Left,2,0);
    layout->addWidget(Down_Right,2,2);
    layout->addWidget(IntHealth,3,0);
    layout->addWidget(IntAttack,4,0);
    layout->addWidget(Status,5,0);
    layout->addWidget(Health,3,2);
    setLayout(layout);
//    setFixedSize(100,480);
}

void Interface::Int_Lost_Battle()
{
    if(Player_health!=0)
    {
        Player_health--;
        emit Decrease_health(Player_health);
    }
    else
    {
        Status->setText("You Lose");
        emit Player_death();
    }
}

void Interface::game_end()
{
    Up->hide();
    Right->hide();
    Left->hide();
    Right->hide();
    Up_Left->hide();
    Up_Right->hide();
    Down_Left->hide();
    Down_Right->hide();
    Down->hide();

}

void Interface::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W)
    {
        Up->click();
    }
    if(event->key() == Qt::Key_Q)
    {
        Up_Left->click();
    }
    if(event->key() == Qt::Key_E)
    {
        Up_Right->click();
    }
    if(event->key() == Qt::Key_A)
    {
        Left->click();
    }
    if(event->key() == Qt::Key_D)
    {
        Right->click();
    }
    if(event->key() == Qt::Key_Z)
    {
        Down_Left->click();
    }
    if(event->key() == Qt::Key_X)
    {
        Down->click();
    }
    if(event->key() == Qt::Key_C)
    {
        Down_Right->click();
    }
}

void Interface::Win_game()
{
    Status->setText("You WIN!");
}

void Interface::button_pressed()
{

    if(Up_Left->isDown())
    {
        emit change_posicion(1);
    }
    if(Up->isDown())
    {
        emit change_posicion(2);
    }
    if(Up_Right->isDown())
    {
        emit change_posicion(3);
    }
    if(Left->isDown())
    {
        emit change_posicion(4);
    }
    if(Right->isDown())
    {
        emit change_posicion(5);
    }
    if(Down_Left->isDown())
    {
        emit change_posicion(6);
    }
    if(Down->isDown())
    {
        emit change_posicion(7);
    }
    if(Down_Right->isDown())
    {
        emit change_posicion(8);
    }
}
