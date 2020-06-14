#ifndef SELECT_H
#define SELECT_H

#include <QString>
#include "struct.h"

//选择框对象
class Select{
private:
    bool display=false; //是否显示选择框
    int _x=0,_y=0; //最左上角坐标
    const int _width,_height; //整体宽高
    QString selectpngPath; //选择框图片路径

    ButtonStr SubBut[4]; //四个子按钮（四种炮塔）

public:
    Select(QString Path,int width =270,int height=270);
    int getX()const;//获取横坐标
    int getY()const;//获取纵坐标
    int getWidth()const;//获取宽
    int getHeight()const;//获取高
    QString getpngPath() const;// 获取选择框图片的路径
    bool getDisplay() const; //获取显示状态
    void setDisplay(const bool SetPlay); //设置显示状态
    void checkTower(int x,int y);//选中防御塔
    ButtonStr *getSubButton();//获取子按钮结构数组

};

#endif // SELECT_H
