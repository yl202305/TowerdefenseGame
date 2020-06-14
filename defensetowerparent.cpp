#include "defensetowerparent.h"

int Defensetowerparent::getX() const{
    return _x;
}

int Defensetowerparent::getY() const{
    return _y;
}

int Defensetowerparent::getWidth() const{
    return _width;
}

int Defensetowerparent::getHeight() const{
    return _height;
}

int Defensetowerparent::getAngle() const{
    return RotatAngle;
}

QString Defensetowerparent::getBasepng() const{
    return basepngPath;
}

QString Defensetowerparent::getdefensetowerpng() const{
    return defensetowerpngPath;
}

int Defensetowerparent::getLeftX() const{
    return UpLeftX;
}

int Defensetowerparent::getLeftY() const{
    return UpLeftY;
}

void Defensetowerparent::setAngle(int rot){
    RotatAngle=rot;
}

int Defensetowerparent::getRange() const{
    return Range;
}

Monster* Defensetowerparent::getAimMonster() const{
    return aimsmon;
}

void Defensetowerparent::setAimMonster(Monster *mon){
    aimsmon=mon;
}

QString Defensetowerparent::getBulletpng() const{
    return bullpngPath;
}

QVector<BulletStr *>&Defensetowerparent::getBulletVector(){
    return BulletVec;
}

void Defensetowerparent::buildBullet(){
    counter++;
    if(counter<7||!aimsmon){
        return;
    }
    //向子弹数组中插入子弹
    BulletStr *bull=new BulletStr(CoorStr(UpLeftX+40,UpLeftY+40));

    bull->coor.x=UpLeftX+40,bull->coor.y=UpLeftY+40;

    BulletVec.push_back(bull); //将子弹存到数组中

    //计算每一个子弹的路径
    if(!(aimsmon->getX()-bull->coor.x)){
        delete bull;
        bull=NULL;
        goto L1;
    }
    bull->a=(aimsmon->getY()-bull->coor.y)/(aimsmon->getX()-bull->coor.x);
    bull->b=aimsmon->getY()-aimsmon->getX()*bull->a;

    bull->coor.x=UpLeftX+40,bull->coor.y=UpLeftX+40;

    BulletVec.push_back(bull); //将子弹插入到子弹数组里

    if(aimsmon->getX()<=UpLeftX+40){
        bull->moveflag=true;
    }
    L1:

    counter=0; //计数器重置为0
}

void Defensetowerparent::BulletMove(){
    //子弹移动
    for(auto bulli : BulletVec){
        const int speed=30; //子弹移动速度

        if(bulli->moveflag==true){
            bulli->coor.x-=speed;//根据移动方向标记判断每颗子弹的移动方向
        }
        else{
            bulli->coor.x+=speed;
        }

        bulli->coor.y=bulli->a*bulli->coor.x+bulli->b; //子弹纵坐标改变

    }
    for(auto bullii=BulletVec.begin();bullii!=BulletVec.end();bullii++){
        if((*bullii)->coor.x>1040||(*bullii)->coor.x<0||(*bullii)->coor.y>640||(*bullii)->coor.y<0){
            BulletVec.erase(bullii);
            break;
        }
    }
}

int Defensetowerparent::getBulletWidth() const{
    return bullwidth;
}

int Defensetowerparent::getBulletHeight() const{
    return bullheight;
}

int Defensetowerparent::getAttack() const{
    return attack;
}

void Defensetowerparent::setAttack(int attack){
    this->attack=attack;
}

void Defensetowerparent::setXY(int x, int y){
    this->_x=x,this->_y=y;
}

void Defensetowerparent::setWidthHeight(int width, int height){
    this->_width=width,this->_height=height;
}

int & Defensetowerparent::setRange(){
    return Range;
}

int Defensetowerparent::getexplosionrangeWidth() const{
    return ExplRangeWidth;
}

int Defensetowerparent::getexplosionrangeHeight() const{
    return ExplRangeHeight;
}

void Defensetowerparent::setexplosionrangeWidthHeight(int width, int height){
    ExplRangeWidth=width,ExplRangeHeight=height;
}

void Defensetowerparent::setBulletWidthHeight(int width, int height){
    bullwidth=width,bullheight=height;
}

