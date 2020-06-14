#include "select.h"

//����
Select::Select(QString Path, int width, int height) :
    _width(width), _height(height), selectpngPath(Path) {}

int Select::getX() const     //��ȡ������
{
    return _x;
}
int Select::getY() const     //��ȡ������
{
    return _y;
}
int Select::getWidth() const //��ȡ��
{
    return _width;
}
int Select::getHeight() const //��ȡ��
{
    return _height;
}

QString Select::getpngPath() const    //����ѡ���ͼƬ·��
{
    return selectpngPath;
}

//��ȡ��ʾ״̬
bool Select::getDisplay() const
{
    return display;
}

//������ʾ״̬
void Select::setDisplay(const bool SetPlay)
{
    display = SetPlay;
}

//ѡ�з�����
void Select::checkTower(int x, int y)
{
    //ȷ��ѡ����λ��
    _x = x - 95, _y = y - 95;

    //ȷ���Ӱ�ť��λ��
    SubBut[0].X = _x + 106, SubBut[0].Y = _y + 14;
    SubBut[0].buttonpngPath = QString(":/image/ironmanbuy.png");

    SubBut[1].X = _x + 14, SubBut[1].Y = _y + 106;
    SubBut[1].buttonpngPath = QString(":/image/spidermanbuy.png");

    SubBut[2].X = _x + 202, SubBut[2].Y = _y + 106;
    SubBut[2].buttonpngPath = QString(":/image/thor.png");

    SubBut[3].X = _x + 106, SubBut[3].Y = _y + 190;
    SubBut[3].buttonpngPath = QString(":/image/captain.png");

    display = true; //��ʾ״̬��Ϊ��
}

//��ȡ�Ӱ�ť�ṹ����
ButtonStr* Select::getSubButton()
{
    return SubBut;
}
