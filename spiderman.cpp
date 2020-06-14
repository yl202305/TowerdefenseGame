#include "spiderman.h"

//蜘蛛侠类函数实现
//构造
Spiderman::Spiderman(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth, int Fheight)
{
    //初始化成员变量，这里不能用初始化列表
    _x = x, _y = y;
    basepngPath = QString(":/image/base3.png");
    defensetowerpngPath = QString(":/image/spiderman1.png");
    _width = Fwidth,_height = Fheight;
    UpLeftX = FUpLeftX, UpLeftY = FUpLeftY;

    Range = 170;    //射程

    bullpngPath = QString(":/image/captainbullet1.png");
    bullwidth = 40, bullheight = 40;           //子弹大小

    attack = 85;    //攻击力

    ExplRangeWidth = 30;    //爆炸效果宽高
    ExplRangeHeight = ExplRangeWidth;
}
