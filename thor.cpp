#include "thor.h"

//雷神类函数实现
//构造
Thor::Thor(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth, int Fheight)
{
    //初始化成员变量
    _x = x, _y = y;
    basepngPath = QString(":/image/base1.png");
    defensetowerpngPath = QString(":/image/thor.png");
    _width = Fwidth, _height = Fheight;
    UpLeftX = FUpLeftX, UpLeftY = FUpLeftY;

    Range = 230;    //射程

    bullpngPath = QString(":/image/captainbullet2.png");
    bullwidth = 30, bullheight = 30;           //子弹大小

    attack = 90;    //攻击力

    ExplRangeWidth = 35;    //爆炸效果宽高
    ExplRangeHeight = ExplRangeWidth;
}
