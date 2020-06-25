#include "monster.h"
#include <QDebug>

//�����ຯ��ʵ��

Monster::Monster(CoorStr **pointarray,int arraylength,int x,int y,int fid):
    _x(x),_y(y),id(fid)
{
    for(int i=0;i<arraylength;i++)
       { Waypoint.push_back(pointarray[i]); //����������������뵽Waypoint��̬������
}
        //ȷ����ͬ���������ֵ
        switch (id) {
        case 1: //����1
            life=90;//����ֵ
            _width=64,_height=64; //���
            pngPath=":/image/enemy1.png";
            break;
        case 2: //����2
            life=110;
            _width=86,_height=64;
            pngPath=":/image/enemy2.png";
            break;
        case 3: //����3
            life=180;
            _width=160,_height=120;
            pngPath=":/image/enemy3.png";
            break;
        case 4: //����4
            life=300;
            _width=98,_height=70;
            pngPath=":/image/enemy4.png";
            break;
        case 5: //����5
            life=600;
            _width=90,_height=76;
            pngPath=":/image/enemy5.png";
            break;
        default:
            break;

        }
    }
//���ﰴ���趨·�����ƶ�
bool Monster::Move()
{
    if(Waypoint.empty())
    {
            return true;
    }
    //�����һ��·�����yС�ڹ���ԭ����·���㣬�����������
    if(Waypoint.at(0)->y>_y) //��
    {
        _y+=monstermovespeed;
        return false;
    }
    if(Waypoint.at(0)->x<_x) //��
    {
        _x-=monstermovespeed;
        return false;
    }
    if(Waypoint.at(0)->y<_y) //��
    {
        _y-=monstermovespeed;
        return false;
    }
    if(Waypoint.at(0)->x>_x) //��
    {
        _x+=monstermovespeed;
        return false;
    }

    //�������������·�������꼸���غϣ���ɾ�����·����
    if(Waypoint.at(0)->y==_y&&Waypoint.at(0)->x==_x)
    {
        Waypoint.erase(Waypoint.begin()); //��������ɾ��
    }

    return false;
}

int Monster::getX() const
{
    return _x;
}

int Monster::getY() const
{
    return _y;
}

int Monster::getWidth() const
{
    return _width;
}

int Monster::getHeight() const
{
    return _height;
}

QString Monster::GetpngPath() const
{
    return pngPath;
}

int Monster::getID() const
{
    return id;
}
int Monster::getLife() const
{
    return life;
}

void Monster::setLife(int flife){
    life=flife;
}
