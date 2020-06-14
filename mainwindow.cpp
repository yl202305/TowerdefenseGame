#include "mainwindow.h"
#include <QDebug>
#include "struct.h"       //选择框按钮全局结构
#include <math.h>
#include "ironman.h"
#include "spiderman.h"
#include "thor.h"
#include "captain.h"
#include <QPushButton>

#define MouseClickRegion(X, Width, Y, Height)     \
(ev->x() >= (X) && ev->x() <= (X) + (Width) &&  \
ev->y() >= (Y) && ev->y() <= (Y)+(Height))

#define DistBetPoints(X1, Y1, X2, Y2)           \
abs(sqrt((((X1) - (X2)) * ((X1) - (X2))) + (((Y1) - (Y2)) * ((Y1) - (Y2)))))


#define X40(num) ((num) - 1) * 40 + 10

#define InsterMonster(PathNum, StaCoorNum, MonsterId)     \
MonsterVector.push_back(new Monster(pointarr[PathNum], PathLength[PathNum], X40(staco[StaCoorNum].x), X40(staco[StaCoorNum].y), MonsterId));

void Mainwindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);     //创建画家类

    painter.setRenderHint(QPainter::Antialiasing);

    DrawMap(painter);        //画出地图

    DrawDefenseTower(painter);  //画出防御塔和子弹

    DrawMonster(painter);       //画出怪物

    DrawRangeAndUpdate(painter);//画出攻击范围和升级按钮

    DrawExplosion(painter);     //画出爆炸效果

    DrawSelectionBox(painter);  //画出选择框
}


void Mainwindow::DrawMap(QPainter& painter)
{
    //地图数组  第一关
    int Map_1[16][26] =
    {
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 3, 2, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 2, 2, 1, 1, 0, 0, 3, 2, 0, 1, 1, 0, 0, 3, 2, 0, 0, 3, 2, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 2, 2, 0, 1, 1, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, 3, 2, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 2, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 5, 1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    //地图数组 第二关
    int Map_2[16][26] =
    {
        {0, 0, 0, 0, 0, 3, 2, 1, 1, 1, 1, 5, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 3, 2, 0, 0, 3, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 0, 0, 2, 2, 1, 1, 3, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 3, 2, 0, 0, 1, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 2, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 3, 2, 0, 0, 3, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 0, 0, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 3, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };


   //地图数组 第三关
    int Map_3[16][26] =
    {
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 0, 0, 0, 0, 0, 0, 3, 2, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 3, 2, 1, 1, 3, 2, 0, 0, 0, 0, 0, 0, 2, 2, 1, 1, 3, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 2, 1, 1, 2, 2, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 3, 2, 0, 1, 1, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 3, 2, 0, 1, 1, 0, 2, 2, 0, 1, 1, 0, 3, 2, 0, 2, 2, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 2, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 2, 1, 1, 1, 1, 1, 1, 5, 1},
        {0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 1, 0, 3, 2, 0, 0, 3, 2, 0, 0, 3, 2, 0, 0, 3, 2, 1, 1, 3, 2, 0, 0, 0, 0},
        {0, 1, 1, 0, 2, 2, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 2, 2, 1, 1, 2, 2, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    int Map[16][26];    //用于拷贝不同的关卡数组

    switch (LevelNumber)
    {
    case 0:
        memcpy(Map, Map_1, sizeof(Map));
        break;
    case 1:
        memcpy(Map, Map_2, sizeof(Map));
        break;
    case 2:
        memcpy(Map, Map_3, sizeof(Map));
        break;
    default:
        break;
    }

    for (int j = 0; j < 16; j++)
       {
        for (int i = 0; i < 26; i++)
        {
            switch (Map[j][i])
            {
            case 0:
                painter.drawPixmap(i * 40, j * 40, 40, 40,
                    QPixmap(":/image/grass.png"));
                break;
            case 1:
                painter.drawPixmap(i * 40, j * 40, 40, 40,
                    QPixmap(":/image/ground.png"));
                break;
            case 3:
                painter.drawPixmap(i * 40, j * 40, 80, 80,
                    QPixmap(":/image/stone.png"));
                //防御塔坑坐标初始化塔坑坐标，插入到塔坑对象数组
                TowerPitVector.push_back(new Defensetowerpit(i * 40, j * 40));
                break;
            case 5:
                painter.drawPixmap(i * 40, j * 40, 40, 40,
                    QPixmap(":/image/ground.png"));
                homecoor->x = i * 40, homecoor->y = j * 40;
                break;
            }
        }

    painter.drawPixmap(homecoor->x, homecoor->y, 80, 80,
        QPixmap(":/image/house.png")); //画出房子
    }
}

//画出选择框
void Mainwindow::DrawSelectionBox(QPainter& painter)
{
    //显示选择框
    if (!selectbox->getDisplay())
        return;

   //画出选择框
    painter.drawPixmap(selectbox->getX(), selectbox->getY(), selectbox->getWidth(), selectbox->getHeight(),
        QPixmap(selectbox->getpngPath()));

    //画出子按钮
    ButtonStr *ASubBut = selectbox->getSubButton();    //接收子按钮结构数组
    for (int i = 0; i < 4; i++)
        painter.drawPixmap(ASubBut[i].X, ASubBut[i].Y, ASubBut[i].Width, ASubBut[i].Height,
            QPixmap(ASubBut[i].buttonpngPath));

    painter.setPen(QPen(Qt::black, 6, Qt::SolidLine));     //设置画笔
    painter.drawRect(QRect(selectbox->getX() + 95, selectbox->getY() + 95, 80, 80));
}

//画出防御塔
void Mainwindow::DrawDefenseTower(QPainter& painter)
{
    //画出防御塔
    for (auto defei : DefenseTowerVector)  //遍历防御塔数组
    {
        //画出底座
        painter.drawPixmap(defei->getLeftX(), defei->getLeftY(), 80, 80, QPixmap(defei->getBasepng()));

        //画出所有防御塔的攻击范围
        if(DisplayAllRange)
            painter.drawEllipse(QPoint(defei->getLeftX() + 40, defei->getLeftY() + 40), defei->getRange(), defei->getRange());

        //画出所有防御塔子弹
        for (auto bulli : defei->getBulletVector())
            painter.drawPixmap(bulli->coor.x, bulli->coor.y, defei->getBulletWidth(), defei->getBulletHeight(),QPixmap(defei->getBulletpng()));

        //画出防御塔
        painter.translate(defei->getLeftX() + 40, defei->getLeftY() + 40);          //设置旋转中心
        painter.rotate(defei->getAngle());             //旋转角度
        painter.translate(-(defei->getLeftX() + 40), -(defei->getLeftY() + 40));    //原点复位
        painter.drawPixmap(defei->getX(), defei->getY(), defei->getWidth(), defei->getHeight(), QPixmap(defei->getdefensetowerpng()));
        painter.resetTransform();   //重置调整
    }
}

//画出怪物
void Mainwindow::DrawMonster(QPainter& painter)
{
    for (auto moni : MonsterVector)//画出怪物
        painter.drawPixmap(moni->getX(), moni->getY(), moni->getWidth(), moni->getHeight(), QPixmap(moni->GetpngPath()));
}

//画出防御塔和升级按钮
void Mainwindow::DrawRangeAndUpdate(QPainter& painter)
{
    //根据条件画出防御塔攻击范围和升级按钮
    for (auto defei : DefenseTowerVector)
        if(defei->getLeftX() == DisplayRangeX && defei->getLeftY() == DisplayRangeY && DisplayRange)
        {
            painter.setPen(QPen(Qt::black));
            painter.drawEllipse(QPoint(DisplayRangeX + 40, DisplayRangeY + 40), defei->getRange(), defei->getRange());
            painter.drawPixmap(DisplayRangeX + 10, DisplayRangeY - 80, 60, 60, QPixmap(":/image/update.png"));
        }
}

//画出爆炸效果
void Mainwindow::DrawExplosion(QPainter& painter)
{
    //显示所有爆炸效果
    for (auto expli : ExploEffectCoor)
            painter.drawPixmap(expli->coor.x - (expli->ExplosionRangeWidth >> 1), expli->coor.y - (expli->ExplosionRangeHeight >> 1),
                expli->ExplosionRangeWidth, expli->ExplosionRangeHeight, QPixmap(QString(":/image/explosion1.png").arg(expli->index)));
}


inline bool Mainwindow::DeductionMoney(int money)
{
    if(this->money - money < 0) return true; //判断金钱是否足够
    this->money -= money; //扣除金钱
    moneylable->setText(QString("Money:%1").arg(this->money)); //刷新标签文本
    return false;
}

//鼠标点击事件
void Mainwindow::mousePressEvent(QMouseEvent *ev)
{
    if (ev->button() != Qt::LeftButton)
        return;

    //判断升级按钮的点击
    if (DisplayRange)
    {
        if (MouseClickRegion(DisplayRangeX + 10, 60 , DisplayRangeY - 80, 60))
        {
            for (auto defei : DefenseTowerVector)
                if (defei->getLeftX() == DisplayRangeX && defei->getLeftY() == DisplayRangeY && DisplayRange)
                {
                    if (DeductionMoney(180)) return;

                    defei->setAttack(defei->getAttack() + 20);
                    defei->setWidthHeight(defei->getWidth() + 12, defei->getHeight() + 6);
                    defei->setXY(defei->getX() - 6, defei->getY() - 3); //调整防御塔坐标
                    defei->setAimMonster(NULL);                        //将防御塔目标设为空
                    defei->setRange() += 14;                            //设置防御塔的攻击范围
                    defei->setexplosionrangeWidthHeight(defei->getexplosionrangeWidth() + 5, defei->getexplosionrangeHeight() + 5);
                    defei->setBulletWidthHeight(defei->getBulletWidth() + 5, defei->getBulletHeight() + 5);
                    break;
                }

            selectbox->setDisplay(false);      //取消显示新建防御塔框
            DisplayRange = false;           //取消显示自己
            update();
            return;
        }
    }

    //判断选择框四个子按钮的点击
    ButtonStr *ASubBut = selectbox->getSubButton();
    for (int i = 0; i < 4; i++)
        if (MouseClickRegion(ASubBut[i].X, ASubBut[i].Width, ASubBut[i].Y, ASubBut[i].Height) && selectbox->getDisplay())
        {
            selectbox->setDisplay(false);      //取消显示选择框

            //根据点击的不同的按钮，将防御塔子类插入到防御塔父类数组
            switch (i)
            {
            case 0: 
                if (DeductionMoney(100)) return;    //扣除金钱
                DefenseTowerVector.push_back(new Ironman(selectbox->getX() + 110, selectbox->getY() + 112, selectbox->getX() + 95, selectbox->getY() + 95, 72, 46));
                break;
            case 1: 
                if (DeductionMoney(160)) return;
                DefenseTowerVector.push_back(new Spiderman(selectbox->getX() + 110, selectbox->getY() + 112, selectbox->getX() + 95, selectbox->getY() + 95, 72, 46));
                break;
            case 2: 
                if (DeductionMoney(240)) return;
                DefenseTowerVector.push_back(new Thor(selectbox->getX() + 110, selectbox->getY() + 112, selectbox->getX() + 95, selectbox->getY() + 95, 76, 50));
                break;
            case 3: 
                if (DeductionMoney(400)) return;
                DefenseTowerVector.push_back(new Captain(selectbox->getX() + 110, selectbox->getY() + 104, selectbox->getX() + 95, selectbox->getY() + 95, 80, 70));
                break;
            default:
                break;
            }

            update();
            return;
        }

    //遍历所有塔坑
    for (auto APit : TowerPitVector)
        //判断点击塔坑
        if (MouseClickRegion(APit->getX(), APit->getWidth(), APit->getY(), APit->getHeight()))
        {
            DisplayRange = false;               //降防御塔的升级选择显示关闭
            for (auto defei : DefenseTowerVector)      //遍历数组判断防御塔坐标和点击坑坐标重合则返回
                if(defei->getLeftX() == APit->getX() && defei->getLeftY() == APit->getY())
                {
                    DisplayRangeX = defei->getLeftX(), DisplayRangeY = defei->getLeftY();   //记录要显示攻击范围的防御塔的坐标
                    DisplayRange = true;        //显示防御塔攻击范围
                    return;
                }

            selectbox->checkTower(APit->getX(), APit->getY());
            update();

            return;
        }

    DisplayRange = false;           //取消显示防御塔攻击范围
    selectbox->setDisplay(false);      //取消显示选择框

    update();
}

//构造
Mainwindow::Mainwindow(int LevelNumber) : LevelNumber(LevelNumber)
{
    setFixedSize(1040, 640);
    setWindowTitle("Marvel's The Avengers");
    QLabel *victorylable = new QLabel(this);
    victorylable->move(176, 180);
    victorylable->setFont(QFont("宋体", 30));
    victorylable->setText(QString("Congratulations! You Win!"));
    victorylable->hide();

    QTimer* timer2 = new QTimer(this);      //用于插入怪物定时器
    timer2->start(2000);

    connect(
                timer2,&QTimer::timeout,[=]()
    {
        switch (LevelNumber) {
        case 0:
        {
            //设置路径点
            CoorStr* Waypointarr1[] = {new CoorStr(X40(4), X40(8)), new CoorStr(X40(20), X40(8)), new CoorStr(X40(20), X40(13)), new CoorStr(X40(6), X40(13)), new CoorStr(homecoor->x, homecoor->y)};
            CoorStr* Waypointarr2[] = {new CoorStr(X40(11), X40(8)), new CoorStr(X40(20), X40(8)), new CoorStr(X40(20), X40(13)), new CoorStr(X40(6), X40(13)), new CoorStr(homecoor->x, homecoor->y)};

            //怪物的四个起始点
            CoorStr staco[] = {CoorStr(4, 0), CoorStr(11, 0), CoorStr(4, -1), CoorStr(11, -1)};

            //每条路径的结点个数
            int PathLength[] = {sizeof(Waypointarr1)/sizeof(CoorStr*), sizeof(Waypointarr1)/sizeof(CoorStr*)};

            IrodMonsProgDefa(Waypointarr1, Waypointarr2, staco, PathLength, victorylable);
            break;
        }

        case 1:
        {
            //设置路径点
            CoorStr* Waypointarr1[] = {new CoorStr(X40(12), X40(9)), new CoorStr(X40(8), X40(9)), new CoorStr(X40(8), X40(0)), new CoorStr(homecoor->x, homecoor->y)};
            CoorStr* Waypointarr2[] = {new CoorStr(X40(12), X40(9)), new CoorStr(X40(16), X40(9)), new CoorStr(X40(16), X40(0)), new CoorStr(homecoor->x, homecoor->y)};

            //怪物的四个起始点
            CoorStr staco[] = {CoorStr(12, 16), CoorStr(12, 16), CoorStr(12, 17), CoorStr(12, 18)};

            //每条路径的结点个数
            int PathLength[] = {sizeof(Waypointarr1)/sizeof(CoorStr*), sizeof(Waypointarr1)/sizeof(CoorStr*)};

            IrodMonsProgDefa(Waypointarr1, Waypointarr2, staco, PathLength, victorylable);
            break;
        }
        case 2:
        {
            //设置路径点
            CoorStr* Waypointarr1[] = {new CoorStr(X40(8), X40(6)), new CoorStr(X40(2), X40(6)), new CoorStr(X40(2), X40(13)), new CoorStr(X40(19), X40(13)), new CoorStr(X40(19), X40(9)), new CoorStr(homecoor->x, homecoor->y)};
            CoorStr* Waypointarr2[] = {new CoorStr(X40(20), X40(5)), new CoorStr(X40(14), X40(5)), new CoorStr(X40(14), X40(9)), new CoorStr(X40(8), X40(9)), new CoorStr(X40(8), X40(6)), new CoorStr(X40(2), X40(6)),
                                             new CoorStr(X40(2), X40(13)), new CoorStr(X40(19), X40(13)), new CoorStr(X40(19), X40(9)), new CoorStr(homecoor->x, homecoor->y)};
            //怪物的四个起始点
            CoorStr staco[] = {CoorStr(8, 0), CoorStr(20, 0), CoorStr(8, -1), CoorStr(20, -1)};

            //每条路径的结点个数
            int PathLength[] = {sizeof(Waypointarr1)/sizeof(CoorStr*), sizeof(Waypointarr1)/sizeof(CoorStr*)};

            IrodMonsProgDefa(Waypointarr1, Waypointarr2, staco, PathLength, victorylable);

            break;
        }

        default:
            break;
        }
    });



    //金钱标签
    moneylable->move(20, 40);       //位置
    setStyleSheet("color:black");   //设置颜色
    moneylable->setFont(QFont("新宋体", 24));             //设置金钱标签属性
    moneylable->setText(QString("Money:%1").arg(money));    //显示金钱信息

    //生命值标签
    QLabel *lifelable = new QLabel(this);
    lifelable->setGeometry(20, 100, 220, 40);   //设置控件位置和大小
    lifelable->setFont(QFont("新宋体", 24));
    lifelable->setText(QString("Life:%1").arg(life));

    //定时器每时每刻执行防御塔父类数组的活动函数
    QTimer* timer = new QTimer(this);
    timer->start(120);

    connect(timer,&QTimer::timeout,[=]()
    {
        for (auto defei : DefenseTowerVector)      //遍历防御塔
        {
            if (!defei->getAimMonster())   //目标怪物为空时从后往前遍历怪物数组寻找目标怪物
            {
                for(int i = MonsterVector.size() - 1; i >= 0; i--)
                    //这里以防御塔中心店和怪物中心点判断
                    if (DistBetPoints(defei->getLeftX() + 40, defei->getLeftY() + 40,
                        MonsterVector.at(i)->getX() + (MonsterVector.at(i)->getWidth() >> 1),
                        MonsterVector.at(i)->getY() + (MonsterVector.at(i)->getHeight() >> 1)) <= defei->getRange())
                    {
                        defei->setAimMonster(MonsterVector.at(i));    //设置防御塔的目标怪物
                        break;  //找到后跳出循环
                    }
            }
            else                //当前防御塔拥有目标且怪物在防御塔范围之内时时攻击怪物
                if (DistBetPoints(defei->getLeftX() + 40, defei->getLeftY() + 40,
                    defei->getAimMonster()->getX() + (defei->getAimMonster()->getWidth() >> 1),
                    defei->getAimMonster()->getY() + (defei->getAimMonster()->getHeight() >> 1)) <= defei->getRange())
                {
                    //根据每个防御塔的目标怪物计算旋转角度
                    defei->setAngle(
                        atan2
                        (
                            defei->getAimMonster()->getY() - defei->getLeftY() + 40,
                            defei->getAimMonster()->getX()- defei->getLeftX()
                        ) * 180 / 3.1415 );

                     defei->buildBullet();           //拥有目标时一直创建子弹
                }

            if (defei->getAimMonster())    //目标怪物不为空
                if (DistBetPoints(defei->getLeftX() + 40, defei->getLeftY() + 40,
                    defei->getAimMonster()->getX() + (defei->getAimMonster()->getWidth() >> 1),
                    defei->getAimMonster()->getY() + (defei->getAimMonster()->getHeight() >> 1)) > defei->getRange())
                        defei->setAimMonster(NULL);     //超过距离将目标怪物设为空
        }

        //防御塔子弹移动
        for (auto defei : DefenseTowerVector)
            defei->BulletMove();

        //怪物移动
        for (auto Moni = MonsterVector.begin(); Moni != MonsterVector.end(); Moni++)
            if((*Moni)->Move()) //怪物走到终点
            {
                delete *Moni;
                MonsterVector.erase(Moni);         //怪物走到终点则删除这个怪物

                life--;                         //我们的生命数量-1
                lifelable->setText(QString("Life:%1").arg(life));

                if (life <= 0) this->close();   //生命值为0时关闭该窗口

                break;
            }

        //判断子弹击中怪物
        for (auto defei : DefenseTowerVector)  //防御塔
        {
            auto &tbullvec = defei->getBulletVector();    //临时存储子弹
            for (auto bullit = tbullvec.begin(); bullit != tbullvec.end(); bullit++)    //子弹
                for (auto monit = MonsterVector.begin(); monit != MonsterVector.end(); monit++)//怪物
                    if ((*bullit)->getX() + (defei->getBulletWidth() >> 1) >= (*monit)->getX() && (*bullit)->getX() <= (*monit)->getX() + (*monit)->getWidth() &&
                       (*bullit)->getY() + (defei->getBulletHeight() >> 1) >= (*monit)->getY() && (*bullit)->getY() <= (*monit)->getY() + (*monit)->getHeight())
                    {   //击中怪物时
                        tbullvec.erase(bullit);     //删除子弹

                        (*monit)->setLife((*monit)->getLife() - defei->getAttack());      //敌人血量 = 本身血量减去 当前炮塔攻击力

                        //将击中的怪物中心的坐标插入到爆炸效果数组
                        ExploEffectCoor.push_back(new ExplosionStr(CoorStr((*monit)->getX() + ((*monit)->getWidth() >> 1), (*monit)->getY() + ((*monit)->getHeight() >> 1)),
                                                                defei->getexplosionrangeWidth(), defei->getexplosionrangeHeight()));

                        if ((*monit)->getLife() <= 0) //生命值为空时
                        {
                            //判断一下其他防御塔的目标怪物是否和当前防御塔消灭的怪物重复，如果重复，则将那一个防御塔的目标怪物也设为空
                            for (auto defei2 : DefenseTowerVector)
                                if (defei2->getAimMonster() == *monit)
                                    defei2->setAimMonster(NULL);

                            MonsterVector.erase(monit);    //删除怪物
                            money += RewardMoney;       //击败怪物增加金钱
                            moneylable->setText(QString("Money:%1").arg(money));//刷新标签
                        }

                        //这里不能将防御塔目标怪物设为空，因为防御塔的子弹攻击到的怪物不一定是该防御塔的目标怪物
                        goto L1;
                    }
            L1:;
        }

        //显示爆炸效果
        for (auto expli = ExploEffectCoor.begin(); expli != ExploEffectCoor.end(); expli++)
        {
            if((*expli)->index >= 8)           //爆炸效果显示完后将该效果从数组中删除
            {
                ExploEffectCoor.erase(expli);
                break;
            }

            (*expli)->index++;                 //将要显示的图片的序号++
        }

        update();   //绘图
    });
}



//预设的两条路产生怪物方案
void Mainwindow::IrodMonsProgDefa(CoorStr** Waypointarr1, CoorStr** Waypointarr2, CoorStr* staco, int* PathLength, QLabel* victorylable)
{
    //两条路径
    CoorStr** pointarr[] = {Waypointarr1, Waypointarr2};

    //插入怪物
    if(counter >= 1 && counter <= 14)
    {
        InsterMonster(0, 0, 1); //第几条路径、第几个起始点、怪物编号
    }
    else if(counter > 14 && counter <= 34)
    {
        InsterMonster(0, 0, 1);
        InsterMonster(1, 1, 2);
    }
    else if (counter > 34 && counter <= 35)
    {
        InsterMonster(0, 0, 3);
        InsterMonster(1, 1, 3);
    }
    else if (counter > 35 && counter <= 52)
    {
        InsterMonster(0, 2, 4);
        InsterMonster(0, 0, 4);
        InsterMonster(1, 1, 1);
    }
    if(counter > 52 && counter <= 56)
    {
        InsterMonster(0, 0, 3);
        InsterMonster(1, 1, 3);
    }
    if (counter > 52 && counter <= 71)
    {
        InsterMonster(0, 2, 2);
        InsterMonster(0, 0, 5);
        InsterMonster(1, 3, 1);
        InsterMonster(1, 1, 4);
    }

    if (counter > 71 && MonsterVector.empty())   //时间大于71且怪物数组为空时游戏胜利
        victorylable->show();

    counter++;          //计数器+1
    update();
}

//根据数组画出地图函数
//由绘图函数调用





//析构释放内存
Mainwindow::~Mainwindow()
{
    for (auto it = TowerPitVector.begin(); it != TowerPitVector.end(); it++)
    {
        delete *it;
        *it = NULL;
    }

    delete selectbox;
    selectbox = NULL;

    for (auto it = DefenseTowerVector.begin(); it != DefenseTowerVector.end(); it++)
    {
        delete *it;
        *it = NULL;
    }

    for (auto it = MonsterVector.begin(); it != MonsterVector.end(); it++)
    {
        delete *it;
        *it = NULL;
    }

    for (auto it = ExploEffectCoor.begin(); it != ExploEffectCoor.end(); it++)
    {
        delete *it;
        *it = NULL;
    }

    delete homecoor;
}
