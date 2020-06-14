#ifndef DEFENSETOWERPIT_H
#define DEFENSETOWERPIT_H

#include <QVector>

//防御塔坑类
class Defensetowerpit{
public:
    Defensetowerpit(int x,int y,int width=80,int height=80);//构造函数
    int getX() const; //获取横坐标
    int getY() const;  //获取纵坐标
    int getWidth() const; //获取宽
    int getHeight() const; //获取高
private:
    const int _x,_y,_width,_height; //位置坐标及宽高
};

#endif // DEFENSETOWERPIT_H
