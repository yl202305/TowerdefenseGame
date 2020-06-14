#include "ironman.h"

//钢铁侠类函数实现
//构造
Ironman::Ironman(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth, int Fheight)
{
    //初始化成员变量
    _x = x, _y = y;
    basepngPath = QString(":/image/base2.png");
    defensetowerpngPath = QString(":/image/ironman1.png");
    _width = Fwidth, _height = Fheight;
    UpLeftX = FUpLeftX, UpLeftY = FUpLeftY;

    Range = 190;    //射程

    bullpngPath = QString(":/image/ironmanbullet.png");
    bullwidth = 30, bullheight = 30;           //子弹大小

    attack = 40;    //攻击力

    ExplRangeWidth = 25;    //爆炸效果宽高
    ExplRangeHeight = ExplRangeWidth;
}
