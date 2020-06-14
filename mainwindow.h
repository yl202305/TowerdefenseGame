#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPainter> //��ͼ
#include <QMouseEvent> //���
#include <QTimer> //��ʱ��
#include <QLabel>
#include <QVector>
#include "defensetowerpit.h" //����������
#include "select.h" //ѡ�����
#include "defensetowerparent.h" //����������
#include "monster.h" //������

class Mainwindow:public QWidget{
private:
    QVector<Defensetowerpit*>TowerPitVector; //������������
    Select *selectbox =new Select(":/image/selection.png");//ѡ�����

    QVector<Defensetowerparent *>DefenseTowerVector; //��������������
    QVector<Monster*>MonsterVector;//��������

    void paintEvent(QPaintEvent *);//��ͼ�¼�
    void mousePressEvent(QMouseEvent *) ;// ������¼�

    void DrawMap(QPainter &);//���ڻ�����ͼ
    void DrawSelectionBox(QPainter &); //���ڻ���ѡ���
    void DrawDefenseTower(QPainter &); //����������
    void DrawMonster(QPainter &); //��������
    void DrawRangeAndUpdate(QPainter &); //�����������Ĺ�����Χ��������ť
    void DrawExplosion(QPainter &); //������ըЧ��

    int DisplayRangeX,DisplayRangeY; //���ڼ�¼��ʾ��Χ�ķ�����������
    bool DisplayRange=false; //������ʾ�������Ĺ�����Χ

    struct ExplosionStr{
        CoorStr coor; //��ըЧ��������
        int index=1; //��¼Ҫ��ʾ��ͼƬ�ļ������
        int ExplosionRangeWidth; //��ըЧ����
        int ExplosionRangeHeight;//��ըЧ����

        //��ʼ��
        ExplosionStr(CoorStr fcoor,int width,int height):coor(fcoor),ExplosionRangeWidth(width),ExplosionRangeHeight(height){}
    };
    QVector<ExplosionStr *>ExploEffectCoor; //��ըЧ����������

    int money=1000; //��¼��Ǯ
    QLabel*moneylable= new QLabel(this); //��ʾ��Ǯ��ǩ�ؼ�

    inline bool DeductionMoney(int); //�жϽ�Ǯ�Ƿ��㹻��ˢ�±�ǩ


    int life=10;//��������
    int counter=0;//���ڲ�������ļ�����
    const int RewardMoney=25; //ÿ�λ��ܹ����õĽ�Ǯ����

    CoorStr *homecoor=new CoorStr(0,0); //��¼�ҵ����꣬�ӵ�ͼ���Զ���ȡ

    void IrodMonsProgDefa(CoorStr **,CoorStr **,CoorStr *,int *,QLabel *); //Ԥ������·�������﷽������

    const int LevelNumber; //�ؿ���ʶ

    bool DisplayAllRange=false; //��ʶ�Ƿ���ʾ���з������Ĺ�����Χ

public:
    Mainwindow(int); //���캯��
    ~Mainwindow(); //��������
};

#endif // MAINWINDOW_H
