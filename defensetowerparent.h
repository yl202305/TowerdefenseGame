#ifndef DEFENSETOWERPARENT_H
#define DEFENSETOWERPARENT_H

//����������

#include <QString>
#include "monster.h"

class Defensetowerparent{
public:
    int getX() const; //��ȡ������
    int getY() const; //��ȡ������
    int getWidth() const; //��ȡ��
    int getHeight() const; //��ȡ�߶�

    void setAngle(int rot) ; //�趨��ת�Ƕ�
    int getAngle() const; //��ȡ��ת�Ƕ�
    int getLeftX() const; //��ȡ���������Ͻ�ԭ������
    int getLeftY() const; //��ȡ���������Ͻ�ԭ������


    int getRange() const; //���÷����������

    QString getBasepng() const; //��ȡ����ͼƬ·��
    QString getdefensetowerpng() const; //��ȡ������ͼƬ·��
    QString getBulletpng() const;// ��ȡ�������ӵ�ͼƬ·��

    QVector<BulletStr *> & getBulletVector(); //�����ӵ�����

    void setAimMonster(Monster *);// ���÷�������Ŀ�����
    Monster*getAimMonster() const; //��ȡ��ǰ��������Ŀ�����

    void buildBullet(); //�½��ӵ�
    void BulletMove(); //�ӵ��ƶ�����
    int getBulletWidth() const; //��ȡ�ӵ��Ŀ��
    int getBulletHeight() const; //��ȡ�ӵ��ĸ߶�
    int getAttack() const; //��ȡ������������

    //����
    void setAttack(int ); //���÷�����������
    void setWidthHeight(int ,int );
    void setXY(int ,int );
    int &setRange(); //���÷������Ĺ�����Χ

    int getexplosionrangeWidth() const; //��ȡ��ըЧ���Ŀ�
    int getexplosionrangeHeight() const; //��ȡ��ըЧ���ĸ�
    void setexplosionrangeWidthHeight(int , int); //���÷�������Ӧ�ı�ըЧ���Ŀ�͸�
    void setBulletWidthHeight(int ,int ); //�����ӵ���͸�

protected:
    int _x,_y,_width,_height;
    QString basepngPath; //����������ͼƬ·��
    QString defensetowerpngPath; //������ͼƬ·��
    QString bullpngPath;       //�ӵ�ͼƬ·��
    int RotatAngle = 0;     //��������ת�Ƕ�
    int UpLeftX, UpLeftY;   //����������ԭ����
    int Range;              //�����������

    Monster* aimsmon = NULL;//��¼��������Ŀ�����


    int power;              //�ӵ�����
    int bullwidth, bullheight;      //�ӵ����
    QVector<BulletStr*> BulletVec;  //�ӵ��ṹ����
    int counter = 0;        //���ڿ��Ʒ����ӵ����ٶ�
    int attack;             //������������

    int ExplRangeWidth;     //��¼���������й����������ɵı�ըЧ���Ŀ��
    int ExplRangeHeight;


};

#endif // DEFENSETOWERPARENT_H
