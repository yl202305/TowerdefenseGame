#ifndef LIGHTTURRET_H
#define LIGHTTURRET_H

#include "defensetowerparent.h"

//À×Éñ£¬¼Ì³Ð×Ô·ÀÓùËþ¸¸Àà
class Thor:public Defensetowerparent{
public:
    Thor(int x,int y,int FUpleftX,int FUpleftY,int Fwidth=80,int Fheight=80);
};

#endif // LIGHTTURRET_H
