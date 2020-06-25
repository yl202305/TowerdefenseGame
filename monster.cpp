#include "monster.h"
#include <QDebug>

//怪物类函数实现

Monster::Monster(CoorStr **pointarray,int arraylength,int x,int y,int fid):
    _x(x),_y(y),id(fid)
{
    for(int i=0;i<arraylength;i++)
       { Waypoint.push_back(pointarray[i]); //将传进来的数组插入到Waypoint动态数组中
}
        //确定不同怪物的生命值
        switch (id) {
        case 1: //怪物1
            life=90;//生命值
            _width=64,_height=64; //宽高
            pngPath=":/image/enemy1.png";
            break;
        case 2: //怪物2
            life=110;
            _width=86,_height=64;
            pngPath=":/image/enemy2.png";
            break;
        case 3: //怪物3
            life=180;
            _width=160,_height=120;
            pngPath=":/image/enemy3.png";
            break;
        case 4: //怪物4
            life=300;
            _width=98,_height=70;
            pngPath=":/image/enemy4.png";
            break;
        case 5: //怪物5
            life=600;
            _width=90,_height=76;
            pngPath=":/image/enemy5.png";
            break;
        default:
            break;

        }
    }
//怪物按照设定路径点移动
bool Monster::Move()
{
    if(Waypoint.empty())
    {
            return true;
    }
    //如果第一个路径点的y小于怪物原本的路径点，则怪物向下走
    if(Waypoint.at(0)->y>_y) //下
    {
        _y+=monstermovespeed;
        return false;
    }
    if(Waypoint.at(0)->x<_x) //左
    {
        _x-=monstermovespeed;
        return false;
    }
    if(Waypoint.at(0)->y<_y) //上
    {
        _y-=monstermovespeed;
        return false;
    }
    if(Waypoint.at(0)->x>_x) //右
    {
        _x+=monstermovespeed;
        return false;
    }

    //如果怪物的坐标和路径点坐标几乎重合，则删除这个路径点
    if(Waypoint.at(0)->y==_y&&Waypoint.at(0)->x==_x)
    {
        Waypoint.erase(Waypoint.begin()); //从数组中删除
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
