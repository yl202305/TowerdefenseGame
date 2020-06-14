#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPainter> //画图
#include <QMouseEvent> //鼠标
#include <QTimer> //定时器
#include <QLabel>
#include <QVector>
#include "defensetowerpit.h" //防御塔坑类
#include "select.h" //选择框类
#include "defensetowerparent.h" //防御塔父类
#include "monster.h" //怪物类

class Mainwindow:public QWidget{
private:
    QVector<Defensetowerpit*>TowerPitVector; //防御塔坑数组
    Select *selectbox =new Select(":/image/selection.png");//选择框类

    QVector<Defensetowerparent *>DefenseTowerVector; //防御塔父类数组
    QVector<Monster*>MonsterVector;//怪物数组

    void paintEvent(QPaintEvent *);//绘图事件
    void mousePressEvent(QMouseEvent *) ;// 鼠标点击事件

    void DrawMap(QPainter &);//用于画出地图
    void DrawSelectionBox(QPainter &); //用于画出选择框
    void DrawDefenseTower(QPainter &); //画出防御塔
    void DrawMonster(QPainter &); //画出怪物
    void DrawRangeAndUpdate(QPainter &); //画出防御塔的攻击范围和升级按钮
    void DrawExplosion(QPainter &); //画出爆炸效果

    int DisplayRangeX,DisplayRangeY; //用于记录显示范围的防御塔的坐标
    bool DisplayRange=false; //用于显示防御塔的攻击范围

    struct ExplosionStr{
        CoorStr coor; //爆炸效果的坐标
        int index=1; //记录要显示的图片文件的序号
        int ExplosionRangeWidth; //爆炸效果宽
        int ExplosionRangeHeight;//爆炸效果高

        //初始化
        ExplosionStr(CoorStr fcoor,int width,int height):coor(fcoor),ExplosionRangeWidth(width),ExplosionRangeHeight(height){}
    };
    QVector<ExplosionStr *>ExploEffectCoor; //爆炸效果坐标数组

    int money=1000; //记录金钱
    QLabel*moneylable= new QLabel(this); //显示金钱标签控件

    inline bool DeductionMoney(int); //判断金钱是否足够并刷新标签


    int life=10;//生命数量
    int counter=0;//用于产生怪物的计数器
    const int RewardMoney=25; //每次击败怪物获得的金钱数量

    CoorStr *homecoor=new CoorStr(0,0); //记录家的坐标，从地图中自动获取

    void IrodMonsProgDefa(CoorStr **,CoorStr **,CoorStr *,int *,QLabel *); //预设两条路产生怪物方案函数

    const int LevelNumber; //关卡标识

    bool DisplayAllRange=false; //标识是否显示所有防御塔的攻击范围

public:
    Mainwindow(int); //构造函数
    ~Mainwindow(); //析构函数
};

#endif // MAINWINDOW_H
