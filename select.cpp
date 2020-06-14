#include "select.h"

//构造
Select::Select(QString Path, int width, int height) :
    _width(width), _height(height), selectpngPath(Path) {}

int Select::getX() const     //获取横坐标
{
    return _x;
}
int Select::getY() const     //获取横坐标
{
    return _y;
}
int Select::getWidth() const //获取宽
{
    return _width;
}
int Select::getHeight() const //获取高
{
    return _height;
}

QString Select::getpngPath() const    //返回选择框图片路径
{
    return selectpngPath;
}

//获取显示状态
bool Select::getDisplay() const
{
    return display;
}

//设置显示状态
void Select::setDisplay(const bool SetPlay)
{
    display = SetPlay;
}

//选中防御塔
void Select::checkTower(int x, int y)
{
    //确定选择框的位置
    _x = x - 95, _y = y - 95;

    //确定子按钮的位置
    SubBut[0].X = _x + 106, SubBut[0].Y = _y + 14;
    SubBut[0].buttonpngPath = QString(":/image/ironmanbuy.png");

    SubBut[1].X = _x + 14, SubBut[1].Y = _y + 106;
    SubBut[1].buttonpngPath = QString(":/image/spidermanbuy.png");

    SubBut[2].X = _x + 202, SubBut[2].Y = _y + 106;
    SubBut[2].buttonpngPath = QString(":/image/thor.png");

    SubBut[3].X = _x + 106, SubBut[3].Y = _y + 190;
    SubBut[3].buttonpngPath = QString(":/image/captain.png");

    display = true; //显示状态设为真
}

//获取子按钮结构数组
ButtonStr* Select::getSubButton()
{
    return SubBut;
}
