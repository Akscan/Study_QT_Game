#include "MainWindow.h"
#include "map.h"
#include "Interface.h"
#include <QLayout>
mainWindow::mainWindow(QWidget *parent)
    :QWidget(parent)
{
    Map *MainMap = new Map;
    Interface *MainInterface = new Interface;
    QGridLayout *mainlayout = new QGridLayout;

    connect(MainInterface,SIGNAL(clicked_down()),MainMap,SLOT(move_down()));
    connect(MainInterface,SIGNAL(clicked_up()),MainMap,SLOT(move_up()));
    connect(MainInterface,SIGNAL(clicked_right()),MainMap,SLOT(move_right()));
    connect(MainInterface,SIGNAL(clicked_left()),MainMap,SLOT(move_left()));
    connect(MainInterface,SIGNAL(clicked_up_left()),MainMap,SLOT(move_up_left()));
    connect(MainInterface,SIGNAL(clicked_up_right()),MainMap,SLOT(move_up_right()));
    connect(MainInterface,SIGNAL(clicked_down_left()),MainMap,SLOT(move_down_left()));
    connect(MainInterface,SIGNAL(clicked_down_right()),MainMap,SLOT(move_down_right()));
    connect(MainMap,SIGNAL(Map_Lost_battle()),MainInterface,SLOT(Int_Lost_Battle()));
    MainInterface->setFixedSize(100,480);
    MainMap->setFixedSize(540,480);

    mainlayout->addWidget(MainMap,0,1);
    mainlayout->addWidget(MainInterface,0,0);
    mainlayout->setColumnStretch(0,0);
    mainlayout->setColumnMinimumWidth(1,10);
    setLayout(mainlayout);
}
