//
//  PigLayer.cpp
//  ddgame
//
//  Created by aaa on 14-10-8.
//
//

#include "PigLayer.h"

bool PigLayer::init()
{
    return true;
}

void PigLayer::addPig(int Fx,int Tp)
{
    Tp=6;
    auto p = Pig::createPig(Tp);
    p->setTag(Fx);
    p->Run(Flag[Fx]);
    this->addChild(p);
}

void PigLayer::addRndPig()
{
    int Fx = arc4random()%8;//方向
    int Tp= arc4random()%8; //小猪类型
    Tp=6;
    auto p = Pig::createPig(Tp);
    p->setTag(Fx);
    p->Run(Flag[Fx]);
    //log("%d",Fx);
    this->addChild(p);
}
void PigLayer::pigDelete()
{
    
}