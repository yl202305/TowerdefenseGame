#ifndef FIRETURRET_H
#define FIRETURRET_H

#include "defensetowerparent.h"
//Ö©ÖëÏÀ£¬¼Ì³Ğ·ÀÓùËş¸¸Àà
class Spiderman:public Defensetowerparent{
public:
    Spiderman(int x,int y,int FUpleftX,int FUpleftY,int Fwidth=80,int Fheight=80);
};

#endif // FIRETURRET_H
