#ifndef STRUCT_H
#define STRUCT_H

#include <QString>

//ѡ���ť�ṹ
struct ButtonStr{
    int X; //��ť�����ѡ���ĺ�����
    int Y; //������
    int Width=56; //��ť���
    int Height=56; //��ť�߶�
    QString buttonpngPath; //��ť��ͼƬ·��
};

//����ṹ
struct CoorStr{
    int x;
    int y;
    CoorStr(int x1,int y1):x(x1),y(y1){}
};

//�ӵ��ṹ
struct BulletStr{
    CoorStr coor;
    int a=0,b=0; //���ڼ�����ӵ�·������
    bool moveflag=false;
    BulletStr(CoorStr fuction):coor(fuction){}

    int getX() const{
        return coor.x;
    }

    int getY() const{
        return coor.y;
    }

};

#endif // STRUCT_H
