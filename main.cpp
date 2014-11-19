#include <QApplication>
#include <QtSerialPort/QtSerialPort>
#include <QString>
#include <QWidget>
#include <QPushButton>
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWindow b;
    b.show();
    return a.exec();
}
