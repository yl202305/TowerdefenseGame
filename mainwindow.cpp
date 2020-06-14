#include "mainwindow.h"
#include <QDebug>
#include "struct.h"       //ѡ���ťȫ�ֽṹ
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
    QPainter painter(this);     //����������

    painter.setRenderHint(QPainter::Antialiasing);

    DrawMap(painter);        //������ͼ

    DrawDefenseTower(painter);  //�������������ӵ�

    DrawMonster(painter);       //��������

    DrawRangeAndUpdate(painter);//����������Χ��������ť

    DrawExplosion(painter);     //������ըЧ��

    DrawSelectionBox(painter);  //����ѡ���
}


void Mainwindow::DrawMap(QPainter& painter)
{
    //��ͼ����  ��һ��
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
    //��ͼ���� �ڶ���
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


   //��ͼ���� ������
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

    int Map[16][26];    //���ڿ�����ͬ�Ĺؿ�����

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
                //�������������ʼ���������꣬���뵽���Ӷ�������
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
        QPixmap(":/image/house.png")); //��������
    }
}

//����ѡ���
void Mainwindow::DrawSelectionBox(QPainter& painter)
{
    //��ʾѡ���
    if (!selectbox->getDisplay())
        return;

   //����ѡ���
    painter.drawPixmap(selectbox->getX(), selectbox->getY(), selectbox->getWidth(), selectbox->getHeight(),
        QPixmap(selectbox->getpngPath()));

    //�����Ӱ�ť
    ButtonStr *ASubBut = selectbox->getSubButton();    //�����Ӱ�ť�ṹ����
    for (int i = 0; i < 4; i++)
        painter.drawPixmap(ASubBut[i].X, ASubBut[i].Y, ASubBut[i].Width, ASubBut[i].Height,
            QPixmap(ASubBut[i].buttonpngPath));

    painter.setPen(QPen(Qt::black, 6, Qt::SolidLine));     //���û���
    painter.drawRect(QRect(selectbox->getX() + 95, selectbox->getY() + 95, 80, 80));
}

//����������
void Mainwindow::DrawDefenseTower(QPainter& painter)
{
    //����������
    for (auto defei : DefenseTowerVector)  //��������������
    {
        //��������
        painter.drawPixmap(defei->getLeftX(), defei->getLeftY(), 80, 80, QPixmap(defei->getBasepng()));

        //�������з������Ĺ�����Χ
        if(DisplayAllRange)
            painter.drawEllipse(QPoint(defei->getLeftX() + 40, defei->getLeftY() + 40), defei->getRange(), defei->getRange());

        //�������з������ӵ�
        for (auto bulli : defei->getBulletVector())
            painter.drawPixmap(bulli->coor.x, bulli->coor.y, defei->getBulletWidth(), defei->getBulletHeight(),QPixmap(defei->getBulletpng()));

        //����������
        painter.translate(defei->getLeftX() + 40, defei->getLeftY() + 40);          //������ת����
        painter.rotate(defei->getAngle());             //��ת�Ƕ�
        painter.translate(-(defei->getLeftX() + 40), -(defei->getLeftY() + 40));    //ԭ�㸴λ
        painter.drawPixmap(defei->getX(), defei->getY(), defei->getWidth(), defei->getHeight(), QPixmap(defei->getdefensetowerpng()));
        painter.resetTransform();   //���õ���
    }
}

//��������
void Mainwindow::DrawMonster(QPainter& painter)
{
    for (auto moni : MonsterVector)//��������
        painter.drawPixmap(moni->getX(), moni->getY(), moni->getWidth(), moni->getHeight(), QPixmap(moni->GetpngPath()));
}

//������������������ť
void Mainwindow::DrawRangeAndUpdate(QPainter& painter)
{
    //������������������������Χ��������ť
    for (auto defei : DefenseTowerVector)
        if(defei->getLeftX() == DisplayRangeX && defei->getLeftY() == DisplayRangeY && DisplayRange)
        {
            painter.setPen(QPen(Qt::black));
            painter.drawEllipse(QPoint(DisplayRangeX + 40, DisplayRangeY + 40), defei->getRange(), defei->getRange());
            painter.drawPixmap(DisplayRangeX + 10, DisplayRangeY - 80, 60, 60, QPixmap(":/image/update.png"));
        }
}

//������ըЧ��
void Mainwindow::DrawExplosion(QPainter& painter)
{
    //��ʾ���б�ըЧ��
    for (auto expli : ExploEffectCoor)
            painter.drawPixmap(expli->coor.x - (expli->ExplosionRangeWidth >> 1), expli->coor.y - (expli->ExplosionRangeHeight >> 1),
                expli->ExplosionRangeWidth, expli->ExplosionRangeHeight, QPixmap(QString(":/image/explosion1.png").arg(expli->index)));
}


inline bool Mainwindow::DeductionMoney(int money)
{
    if(this->money - money < 0) return true; //�жϽ�Ǯ�Ƿ��㹻
    this->money -= money; //�۳���Ǯ
    moneylable->setText(QString("Money:%1").arg(this->money)); //ˢ�±�ǩ�ı�
    return false;
}

//������¼�
void Mainwindow::mousePressEvent(QMouseEvent *ev)
{
    if (ev->button() != Qt::LeftButton)
        return;

    //�ж�������ť�ĵ��
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
                    defei->setXY(defei->getX() - 6, defei->getY() - 3); //��������������
                    defei->setAimMonster(NULL);                        //��������Ŀ����Ϊ��
                    defei->setRange() += 14;                            //���÷������Ĺ�����Χ
                    defei->setexplosionrangeWidthHeight(defei->getexplosionrangeWidth() + 5, defei->getexplosionrangeHeight() + 5);
                    defei->setBulletWidthHeight(defei->getBulletWidth() + 5, defei->getBulletHeight() + 5);
                    break;
                }

            selectbox->setDisplay(false);      //ȡ����ʾ�½���������
            DisplayRange = false;           //ȡ����ʾ�Լ�
            update();
            return;
        }
    }

    //�ж�ѡ����ĸ��Ӱ�ť�ĵ��
    ButtonStr *ASubBut = selectbox->getSubButton();
    for (int i = 0; i < 4; i++)
        if (MouseClickRegion(ASubBut[i].X, ASubBut[i].Width, ASubBut[i].Y, ASubBut[i].Height) && selectbox->getDisplay())
        {
            selectbox->setDisplay(false);      //ȡ����ʾѡ���

            //���ݵ���Ĳ�ͬ�İ�ť����������������뵽��������������
            switch (i)
            {
            case 0: 
                if (DeductionMoney(100)) return;    //�۳���Ǯ
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

    //������������
    for (auto APit : TowerPitVector)
        //�жϵ������
        if (MouseClickRegion(APit->getX(), APit->getWidth(), APit->getY(), APit->getHeight()))
        {
            DisplayRange = false;               //��������������ѡ����ʾ�ر�
            for (auto defei : DefenseTowerVector)      //���������жϷ���������͵���������غ��򷵻�
                if(defei->getLeftX() == APit->getX() && defei->getLeftY() == APit->getY())
                {
                    DisplayRangeX = defei->getLeftX(), DisplayRangeY = defei->getLeftY();   //��¼Ҫ��ʾ������Χ�ķ�����������
                    DisplayRange = true;        //��ʾ������������Χ
                    return;
                }

            selectbox->checkTower(APit->getX(), APit->getY());
            update();

            return;
        }

    DisplayRange = false;           //ȡ����ʾ������������Χ
    selectbox->setDisplay(false);      //ȡ����ʾѡ���

    update();
}

//����
Mainwindow::Mainwindow(int LevelNumber) : LevelNumber(LevelNumber)
{
    setFixedSize(1040, 640);
    setWindowTitle("Marvel's The Avengers");
    QLabel *victorylable = new QLabel(this);
    victorylable->move(176, 180);
    victorylable->setFont(QFont("����", 30));
    victorylable->setText(QString("Congratulations! You Win!"));
    victorylable->hide();

    QTimer* timer2 = new QTimer(this);      //���ڲ�����ﶨʱ��
    timer2->start(2000);

    connect(
                timer2,&QTimer::timeout,[=]()
    {
        switch (LevelNumber) {
        case 0:
        {
            //����·����
            CoorStr* Waypointarr1[] = {new CoorStr(X40(4), X40(8)), new CoorStr(X40(20), X40(8)), new CoorStr(X40(20), X40(13)), new CoorStr(X40(6), X40(13)), new CoorStr(homecoor->x, homecoor->y)};
            CoorStr* Waypointarr2[] = {new CoorStr(X40(11), X40(8)), new CoorStr(X40(20), X40(8)), new CoorStr(X40(20), X40(13)), new CoorStr(X40(6), X40(13)), new CoorStr(homecoor->x, homecoor->y)};

            //������ĸ���ʼ��
            CoorStr staco[] = {CoorStr(4, 0), CoorStr(11, 0), CoorStr(4, -1), CoorStr(11, -1)};

            //ÿ��·���Ľ�����
            int PathLength[] = {sizeof(Waypointarr1)/sizeof(CoorStr*), sizeof(Waypointarr1)/sizeof(CoorStr*)};

            IrodMonsProgDefa(Waypointarr1, Waypointarr2, staco, PathLength, victorylable);
            break;
        }

        case 1:
        {
            //����·����
            CoorStr* Waypointarr1[] = {new CoorStr(X40(12), X40(9)), new CoorStr(X40(8), X40(9)), new CoorStr(X40(8), X40(0)), new CoorStr(homecoor->x, homecoor->y)};
            CoorStr* Waypointarr2[] = {new CoorStr(X40(12), X40(9)), new CoorStr(X40(16), X40(9)), new CoorStr(X40(16), X40(0)), new CoorStr(homecoor->x, homecoor->y)};

            //������ĸ���ʼ��
            CoorStr staco[] = {CoorStr(12, 16), CoorStr(12, 16), CoorStr(12, 17), CoorStr(12, 18)};

            //ÿ��·���Ľ�����
            int PathLength[] = {sizeof(Waypointarr1)/sizeof(CoorStr*), sizeof(Waypointarr1)/sizeof(CoorStr*)};

            IrodMonsProgDefa(Waypointarr1, Waypointarr2, staco, PathLength, victorylable);
            break;
        }
        case 2:
        {
            //����·����
            CoorStr* Waypointarr1[] = {new CoorStr(X40(8), X40(6)), new CoorStr(X40(2), X40(6)), new CoorStr(X40(2), X40(13)), new CoorStr(X40(19), X40(13)), new CoorStr(X40(19), X40(9)), new CoorStr(homecoor->x, homecoor->y)};
            CoorStr* Waypointarr2[] = {new CoorStr(X40(20), X40(5)), new CoorStr(X40(14), X40(5)), new CoorStr(X40(14), X40(9)), new CoorStr(X40(8), X40(9)), new CoorStr(X40(8), X40(6)), new CoorStr(X40(2), X40(6)),
                                             new CoorStr(X40(2), X40(13)), new CoorStr(X40(19), X40(13)), new CoorStr(X40(19), X40(9)), new CoorStr(homecoor->x, homecoor->y)};
            //������ĸ���ʼ��
            CoorStr staco[] = {CoorStr(8, 0), CoorStr(20, 0), CoorStr(8, -1), CoorStr(20, -1)};

            //ÿ��·���Ľ�����
            int PathLength[] = {sizeof(Waypointarr1)/sizeof(CoorStr*), sizeof(Waypointarr1)/sizeof(CoorStr*)};

            IrodMonsProgDefa(Waypointarr1, Waypointarr2, staco, PathLength, victorylable);

            break;
        }

        default:
            break;
        }
    });



    //��Ǯ��ǩ
    moneylable->move(20, 40);       //λ��
    setStyleSheet("color:black");   //������ɫ
    moneylable->setFont(QFont("������", 24));             //���ý�Ǯ��ǩ����
    moneylable->setText(QString("Money:%1").arg(money));    //��ʾ��Ǯ��Ϣ

    //����ֵ��ǩ
    QLabel *lifelable = new QLabel(this);
    lifelable->setGeometry(20, 100, 220, 40);   //���ÿؼ�λ�úʹ�С
    lifelable->setFont(QFont("������", 24));
    lifelable->setText(QString("Life:%1").arg(life));

    //��ʱ��ÿʱÿ��ִ�з�������������Ļ����
    QTimer* timer = new QTimer(this);
    timer->start(120);

    connect(timer,&QTimer::timeout,[=]()
    {
        for (auto defei : DefenseTowerVector)      //����������
        {
            if (!defei->getAimMonster())   //Ŀ�����Ϊ��ʱ�Ӻ���ǰ������������Ѱ��Ŀ�����
            {
                for(int i = MonsterVector.size() - 1; i >= 0; i--)
                    //�����Է��������ĵ�͹������ĵ��ж�
                    if (DistBetPoints(defei->getLeftX() + 40, defei->getLeftY() + 40,
                        MonsterVector.at(i)->getX() + (MonsterVector.at(i)->getWidth() >> 1),
                        MonsterVector.at(i)->getY() + (MonsterVector.at(i)->getHeight() >> 1)) <= defei->getRange())
                    {
                        defei->setAimMonster(MonsterVector.at(i));    //���÷�������Ŀ�����
                        break;  //�ҵ�������ѭ��
                    }
            }
            else                //��ǰ������ӵ��Ŀ���ҹ����ڷ�������Χ֮��ʱʱ��������
                if (DistBetPoints(defei->getLeftX() + 40, defei->getLeftY() + 40,
                    defei->getAimMonster()->getX() + (defei->getAimMonster()->getWidth() >> 1),
                    defei->getAimMonster()->getY() + (defei->getAimMonster()->getHeight() >> 1)) <= defei->getRange())
                {
                    //����ÿ����������Ŀ����������ת�Ƕ�
                    defei->setAngle(
                        atan2
                        (
                            defei->getAimMonster()->getY() - defei->getLeftY() + 40,
                            defei->getAimMonster()->getX()- defei->getLeftX()
                        ) * 180 / 3.1415 );

                     defei->buildBullet();           //ӵ��Ŀ��ʱһֱ�����ӵ�
                }

            if (defei->getAimMonster())    //Ŀ����ﲻΪ��
                if (DistBetPoints(defei->getLeftX() + 40, defei->getLeftY() + 40,
                    defei->getAimMonster()->getX() + (defei->getAimMonster()->getWidth() >> 1),
                    defei->getAimMonster()->getY() + (defei->getAimMonster()->getHeight() >> 1)) > defei->getRange())
                        defei->setAimMonster(NULL);     //�������뽫Ŀ�������Ϊ��
        }

        //�������ӵ��ƶ�
        for (auto defei : DefenseTowerVector)
            defei->BulletMove();

        //�����ƶ�
        for (auto Moni = MonsterVector.begin(); Moni != MonsterVector.end(); Moni++)
            if((*Moni)->Move()) //�����ߵ��յ�
            {
                delete *Moni;
                MonsterVector.erase(Moni);         //�����ߵ��յ���ɾ���������

                life--;                         //���ǵ���������-1
                lifelable->setText(QString("Life:%1").arg(life));

                if (life <= 0) this->close();   //����ֵΪ0ʱ�رոô���

                break;
            }

        //�ж��ӵ����й���
        for (auto defei : DefenseTowerVector)  //������
        {
            auto &tbullvec = defei->getBulletVector();    //��ʱ�洢�ӵ�
            for (auto bullit = tbullvec.begin(); bullit != tbullvec.end(); bullit++)    //�ӵ�
                for (auto monit = MonsterVector.begin(); monit != MonsterVector.end(); monit++)//����
                    if ((*bullit)->getX() + (defei->getBulletWidth() >> 1) >= (*monit)->getX() && (*bullit)->getX() <= (*monit)->getX() + (*monit)->getWidth() &&
                       (*bullit)->getY() + (defei->getBulletHeight() >> 1) >= (*monit)->getY() && (*bullit)->getY() <= (*monit)->getY() + (*monit)->getHeight())
                    {   //���й���ʱ
                        tbullvec.erase(bullit);     //ɾ���ӵ�

                        (*monit)->setLife((*monit)->getLife() - defei->getAttack());      //����Ѫ�� = ����Ѫ����ȥ ��ǰ����������

                        //�����еĹ������ĵ�������뵽��ըЧ������
                        ExploEffectCoor.push_back(new ExplosionStr(CoorStr((*monit)->getX() + ((*monit)->getWidth() >> 1), (*monit)->getY() + ((*monit)->getHeight() >> 1)),
                                                                defei->getexplosionrangeWidth(), defei->getexplosionrangeHeight()));

                        if ((*monit)->getLife() <= 0) //����ֵΪ��ʱ
                        {
                            //�ж�һ��������������Ŀ������Ƿ�͵�ǰ����������Ĺ����ظ�������ظ�������һ����������Ŀ�����Ҳ��Ϊ��
                            for (auto defei2 : DefenseTowerVector)
                                if (defei2->getAimMonster() == *monit)
                                    defei2->setAimMonster(NULL);

                            MonsterVector.erase(monit);    //ɾ������
                            money += RewardMoney;       //���ܹ������ӽ�Ǯ
                            moneylable->setText(QString("Money:%1").arg(money));//ˢ�±�ǩ
                        }

                        //���ﲻ�ܽ�������Ŀ�������Ϊ�գ���Ϊ���������ӵ��������Ĺ��ﲻһ���Ǹ÷�������Ŀ�����
                        goto L1;
                    }
            L1:;
        }

        //��ʾ��ըЧ��
        for (auto expli = ExploEffectCoor.begin(); expli != ExploEffectCoor.end(); expli++)
        {
            if((*expli)->index >= 8)           //��ըЧ����ʾ��󽫸�Ч����������ɾ��
            {
                ExploEffectCoor.erase(expli);
                break;
            }

            (*expli)->index++;                 //��Ҫ��ʾ��ͼƬ�����++
        }

        update();   //��ͼ
    });
}



//Ԥ�������·�������﷽��
void Mainwindow::IrodMonsProgDefa(CoorStr** Waypointarr1, CoorStr** Waypointarr2, CoorStr* staco, int* PathLength, QLabel* victorylable)
{
    //����·��
    CoorStr** pointarr[] = {Waypointarr1, Waypointarr2};

    //�������
    if(counter >= 1 && counter <= 14)
    {
        InsterMonster(0, 0, 1); //�ڼ���·�����ڼ�����ʼ�㡢������
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

    if (counter > 71 && MonsterVector.empty())   //ʱ�����71�ҹ�������Ϊ��ʱ��Ϸʤ��
        victorylable->show();

    counter++;          //������+1
    update();
}

//�������黭����ͼ����
//�ɻ�ͼ��������





//�����ͷ��ڴ�
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
