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
    return false;
}

void PigLayer::addPig(int Tag,Pig Flag)
{
    //Pig::run();
}

void PigLayer::addRndPig()
{
    int Fx = arc4random()%8;
    auto p = Pig::createPig(Fx);
    p->setTag(Fx);
    this->addChild(p);
     p->Run(Flag[Fx]);
}
