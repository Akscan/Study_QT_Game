#include "MainWindow.h"
//#include "map.h"
#include "Interface.h"
#include "Hero.h"
#include <QLayout>
#include <QTimer>
#include <QLabel>
#define SIZE_OF_INTERFACE_X 100
#define SIZE_OF_INTERFACE_Y 480
mainWindow::mainWindow(QWidget *parent)
    :QWidget(parent)
{
    QLabel *lbl = new QLabel;
    lbl->setText("1");
//    Map *MainMap = new Map;
    Interface *MainInterface = new Interface;
    Hero *player = new Hero("Hero.bmp");
    QGridLayout *mainlayout = new QGridLayout;
    QTimer timer;
    timer.setInterval(40000);
    connect(MainInterface,SIGNAL(change_posicion(int)),player,SLOT(move(int)));
//    connect(MainMap,SIGNAL(Map_Lost_battle()),MainInterface,SLOT(Int_Lost_Battle()));
//    connect(MainMap,SIGNAL(Win_game()),MainInterface,SLOT(Win_game()));
//    connect(&timer,SIGNAL(timeout()),MainMap,SLOT(upd()));
    MainInterface->setFixedSize(100,480);
//    MainMap->setFixedSize(540,480);
    lbl->setFixedSize(540,480);
    lbl->setPalette(QPalette(QColor(Qt::white)));
    MainInterface->setPalette(QPalette(QColor(Qt::gray)));
//    mainlayout->addWidget(MainMap,0,1);
    mainlayout->addWidget(lbl,0,1);
    mainlayout->addWidget(MainInterface,0,0);
    mainlayout->setColumnStretch(0,0);
    mainlayout->setColumnMinimumWidth(1,10);
    setLayout(mainlayout);
    setFixedSize(640,480);
}
