#include "ironman.h"

//�������ຯ��ʵ��
//����
Ironman::Ironman(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth, int Fheight)
{
    //��ʼ����Ա����
    _x = x, _y = y;
    basepngPath = QString(":/image/base2.png");
    defensetowerpngPath = QString(":/image/ironman1.png");
    _width = Fwidth, _height = Fheight;
    UpLeftX = FUpLeftX, UpLeftY = FUpLeftY;

    Range = 190;    //���

    bullpngPath = QString(":/image/ironmanbullet.png");
    bullwidth = 30, bullheight = 30;           //�ӵ���С

    attack = 40;    //������

    ExplRangeWidth = 25;    //��ըЧ�����
    ExplRangeHeight = ExplRangeWidth;
}
