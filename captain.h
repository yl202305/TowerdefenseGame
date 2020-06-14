#ifndef BIGTURRET_H
#define BIGTURRET_H

#include"defensetowerparent.h"
//美国队长
class Captain:public Defensetowerparent{
public:
    Captain(int x,int y,int FUpleftX,int FUpleftY,int Fwidth=80,int Fheight=80);
};

#endif // BIGTURRET_H
