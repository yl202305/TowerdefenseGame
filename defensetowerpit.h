#ifndef DEFENSETOWERPIT_H
#define DEFENSETOWERPIT_H

#include <QVector>

//����������
class Defensetowerpit{
public:
    Defensetowerpit(int x,int y,int width=80,int height=80);//���캯��
    int getX() const; //��ȡ������
    int getY() const;  //��ȡ������
    int getWidth() const; //��ȡ��
    int getHeight() const; //��ȡ��
private:
    const int _x,_y,_width,_height; //λ�����꼰���
};

#endif // DEFENSETOWERPIT_H
