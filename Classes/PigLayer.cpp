//
//  PigLayer.cpp
//  ddgame
//
//  Created by aaa on 14-10-8.
//
//

#include "PigLayer.h"

void PigLayer::addPig(int Tag,Pig Flag)
{
    //Pig::run();
}

void PigLayer::addRndPig()
{
    int Fx = arc4random()%8;
    auto p = Pig::createPig(Fx);
    this->addChild(p);
    p->Run();
}
