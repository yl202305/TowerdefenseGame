#include "defensetowerpit.h"

//����
Defensetowerpit::Defensetowerpit(int x, int y, int width, int height)
    : _x(x), _y(y), _width(width), _height(height) {}

int Defensetowerpit::getX() const     //��ȡ������
{
    return _x;
}

int Defensetowerpit::getY() const     //��ȡ������
{
    return _y;
}

int Defensetowerpit::getWidth() const //��ȡ��
{
    return _width;
}

int Defensetowerpit::getHeight() const //��ȡ��
{
    return _height;
}
