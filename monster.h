#ifndef MONSTER_H
#define MONSTER_H

#include <QVector>
#include <QString>
#include "struct.h" //����ṹ

//������
class Monster{
public:
    Monster(CoorStr **pointarray,int arraylength, int x, int y,int fid); //���캯��
    bool Move(); //�����Ƿ��ƶ�
     int getX() const; //��ȡ������
     int getY() const; //��ȡ������
     int getWidth() const; //��ȡ���
     int getHeight() const; //��ȡ����

     QString GetpngPath() const; //��ȡͼƬ��·��

     int getID() const; //��ȡ���
     int getLife() const; //��ȡ����ֵ
     void setLife(int); //��������ֵ

private:
     QVector<CoorStr*>Waypoint; //�洢����·���������
     int _x,_y,_width,_height;
     QString pngPath; //����ͼƬ��·��
     int id; //������
     int life; //��������ֵ
     int monstermovespeed=10; //�����ƶ��ٶ�

};

#endif // MONSTER_H
