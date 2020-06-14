#include "captain.h"

//美队类函数实现
//构造
Captain::Captain(int x,int y,int FUpleftX,int FUpleftY,int Fwidth,int Fheight){
    _x=x,_y=y;
    basepngPath=QString(":/image/base4.png");
    defensetowerpngPath=QString(":/image/captain.png");
    _width=Fwidth,_height=Fheight;
    UpLeftX=FUpleftX,UpLeftY=FUpleftY;

    Range=210;

    bullpngPath=QString(":/image/captainbullet3.png");
    bullwidth=40,bullheight=40;

    attack=115; //攻击力

    ExplRangeWidth=35;
    ExplRangeHeight=35;
}
