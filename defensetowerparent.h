#ifndef DEFENSETOWERPARENT_H
#define DEFENSETOWERPARENT_H

//防御塔父类

#include <QString>
#include "monster.h"

class Defensetowerparent{
public:
    int getX() const; //获取横坐标
    int getY() const; //获取纵坐标
    int getWidth() const; //获取宽
    int getHeight() const; //获取高度

    void setAngle(int rot) ; //设定旋转角度
    int getAngle() const; //获取旋转角度
    int getLeftX() const; //获取防御塔左上角原横坐标
    int getLeftY() const; //获取防御塔左上角原纵坐标


    int getRange() const; //设置防御塔的射程

    QString getBasepng() const; //获取底座图片路径
    QString getdefensetowerpng() const; //获取防御塔图片路径
    QString getBulletpng() const;// 获取防御塔子弹图片路径

    QVector<BulletStr *> & getBulletVector(); //返回子弹容器

    void setAimMonster(Monster *);// 设置防御塔的目标怪物
    Monster*getAimMonster() const; //获取当前防御塔的目标怪物

    void buildBullet(); //新建子弹
    void BulletMove(); //子弹移动函数
    int getBulletWidth() const; //获取子弹的宽度
    int getBulletHeight() const; //获取子弹的高度
    int getAttack() const; //获取防御塔攻击力

    //升级
    void setAttack(int ); //设置防御塔攻击力
    void setWidthHeight(int ,int );
    void setXY(int ,int );
    int &setRange(); //设置防御塔的攻击范围

    int getexplosionrangeWidth() const; //获取爆炸效果的宽
    int getexplosionrangeHeight() const; //获取爆炸效果的高
    void setexplosionrangeWidthHeight(int , int); //设置防御塔对应的爆炸效果的宽和高
    void setBulletWidthHeight(int ,int ); //设置子弹宽和高

protected:
    int _x,_y,_width,_height;
    QString basepngPath; //防御塔底座图片路径
    QString defensetowerpngPath; //防御塔图片路径
    QString bullpngPath;       //子弹图片路径
    int RotatAngle = 0;     //防御塔旋转角度
    int UpLeftX, UpLeftY;   //防御塔塔坑原坐标
    int Range;              //防御塔的射程

    Monster* aimsmon = NULL;//记录防御塔的目标怪物


    int power;              //子弹威力
    int bullwidth, bullheight;      //子弹宽高
    QVector<BulletStr*> BulletVec;  //子弹结构数组
    int counter = 0;        //用于控制发射子弹的速度
    int attack;             //防御塔攻击力

    int ExplRangeWidth;     //记录防御塔击中怪物后所能造成的爆炸效果的宽高
    int ExplRangeHeight;


};

#endif // DEFENSETOWERPARENT_H
