#include "thor.h"

//�����ຯ��ʵ��
//����
Thor::Thor(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth, int Fheight)
{
    //��ʼ����Ա����
    _x = x, _y = y;
    basepngPath = QString(":/image/base1.png");
    defensetowerpngPath = QString(":/image/thor.png");
    _width = Fwidth, _height = Fheight;
    UpLeftX = FUpLeftX, UpLeftY = FUpLeftY;

    Range = 230;    //���

    bullpngPath = QString(":/image/captainbullet2.png");
    bullwidth = 30, bullheight = 30;           //�ӵ���С

    attack = 90;    //������

    ExplRangeWidth = 35;    //��ըЧ�����
    ExplRangeHeight = ExplRangeWidth;
}
