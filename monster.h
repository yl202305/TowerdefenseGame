#ifndef MONSTER_H
#define MONSTER_H

#include <QVector>
#include <QString>
#include "struct.h" //坐标结构

//怪物类
class Monster{
public:
    Monster(CoorStr **pointarray,int arraylength, int x, int y,int fid); //构造函数
    bool Move(); //怪物是否移动
     int getX() const; //获取横坐标
     int getY() const; //获取纵坐标
     int getWidth() const; //获取宽度
     int getHeight() const; //获取长度

     QString GetpngPath() const; //获取图片的路径

     int getID() const; //获取编号
     int getLife() const; //获取生命值
     void setLife(int); //设置生命值

private:
     QVector<CoorStr*>Waypoint; //存储怪物路径点的容器
     int _x,_y,_width,_height;
     QString pngPath; //怪物图片的路径
     int id; //怪物编号
     int life; //怪物生命值
     int monstermovespeed=10; //怪物移动速度

};

#endif // MONSTER_H
