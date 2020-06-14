#ifndef STRUCT_H
#define STRUCT_H

#include <QString>

//选择框按钮结构
struct ButtonStr{
    int X; //按钮相对于选择框的横坐标
    int Y; //纵坐标
    int Width=56; //按钮宽度
    int Height=56; //按钮高度
    QString buttonpngPath; //按钮的图片路径
};

//坐标结构
struct CoorStr{
    int x;
    int y;
    CoorStr(int x1,int y1):x(x1),y(y1){}
};

//子弹结构
struct BulletStr{
    CoorStr coor;
    int a=0,b=0; //用于计算出子弹路径函数
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
