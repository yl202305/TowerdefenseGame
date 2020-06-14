#include "defensetowerpit.h"

//构造
Defensetowerpit::Defensetowerpit(int x, int y, int width, int height)
    : _x(x), _y(y), _width(width), _height(height) {}

int Defensetowerpit::getX() const     //获取横坐标
{
    return _x;
}

int Defensetowerpit::getY() const     //获取横坐标
{
    return _y;
}

int Defensetowerpit::getWidth() const //获取宽
{
    return _width;
}

int Defensetowerpit::getHeight() const //获取高
{
    return _height;
}
