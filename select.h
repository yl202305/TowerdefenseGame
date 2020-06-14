#ifndef SELECT_H
#define SELECT_H

#include <QString>
#include "struct.h"

//ѡ������
class Select{
private:
    bool display=false; //�Ƿ���ʾѡ���
    int _x=0,_y=0; //�����Ͻ�����
    const int _width,_height; //������
    QString selectpngPath; //ѡ���ͼƬ·��

    ButtonStr SubBut[4]; //�ĸ��Ӱ�ť������������

public:
    Select(QString Path,int width =270,int height=270);
    int getX()const;//��ȡ������
    int getY()const;//��ȡ������
    int getWidth()const;//��ȡ��
    int getHeight()const;//��ȡ��
    QString getpngPath() const;// ��ȡѡ���ͼƬ��·��
    bool getDisplay() const; //��ȡ��ʾ״̬
    void setDisplay(const bool SetPlay); //������ʾ״̬
    void checkTower(int x,int y);//ѡ�з�����
    ButtonStr *getSubButton();//��ȡ�Ӱ�ť�ṹ����

};

#endif // SELECT_H
