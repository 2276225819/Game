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
    int Rnd = arc4random()%8;
    auto PigClass = Pig::create(1);
    this->addChild(PigClass.PigSprite);
    //Pig::run();
}

void PigLayer::addRndPig(int Tag)
{
    
}