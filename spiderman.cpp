#include "spiderman.h"

//֩�����ຯ��ʵ��
//����
Spiderman::Spiderman(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth, int Fheight)
{
    //��ʼ����Ա���������ﲻ���ó�ʼ���б�
    _x = x, _y = y;
    basepngPath = QString(":/image/base3.png");
    defensetowerpngPath = QString(":/image/spiderman1.png");
    _width = Fwidth,_height = Fheight;
    UpLeftX = FUpLeftX, UpLeftY = FUpLeftY;

    Range = 170;    //���

    bullpngPath = QString(":/image/captainbullet1.png");
    bullwidth = 40, bullheight = 40;           //�ӵ���С

    attack = 85;    //������

    ExplRangeWidth = 30;    //��ըЧ�����
    ExplRangeHeight = ExplRangeWidth;
}
