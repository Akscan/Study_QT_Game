#ifndef HERO_H
#define HERO_H
#include <QWidget>
class QPixmap;
class QString;
class Hero : public QWidget
{
    Q_OBJECT
public:
    Hero(QString path,QWidget *parent = 0);
    int get_pos_x();
    int get_pos_y();
    QPixmap get_symbol();
private:
    int     health;
    int     attack;
    QPixmap symbol;
signals:
    void move(int status);
private slots:
};

#endif // HERO_H
