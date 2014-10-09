//
//  Pig.cpp
//  ddgame
//
//  Created by aaa on 14-10-8.
//
//

#include "Pig.h"


Vec2 Pig::FlagToVec(Vec2 v)
{
    v.x*=640;
    v.y*=640;
    return v;
}

void Pig::Drag(cocos2d::Vec2 v)
{
    
}

void Pig::Click()
{
    
}

void Pig::Run(Vec2 v)
{
    Vec2 to=v*600;
    runAction(MoveTo::create(Speed, to));
}


void PigReverse::Run(Vec2 v)
{
    v=FlagToVec(v);
    this->runAction(MoveTo::create(this->Speed, v));
}

void PigClone::Avatar()
{
    
}

void PigClone::Run(Vec2 v)
{
    v=FlagToVec(v);
    auto mt = MoveTo::create(this->Speed, v);
    this->runAction(Sequence::create(mt,CallFunc::create(CC_CALLBACK_0(PigClone::Avatar, this)), NULL));
}

void PigHide::Run(Vec2 v)
{
    v=FlagToVec(v);
    auto mt = MoveTo::create(this->Speed, v);
    auto fo = FadeOut::create(1);
    auto fi = FadeIn::create(1);
    this->runAction(Sequence::create(mt,fo,fi, NULL));
}

Pig::Pig(int speed,int hp)
{
    this->Hp=hp;
    this->Speed=speed;
    //onDelete=[](){};
}




Pig* Pig::createPig(int pigType)
{
    Pig* p;
    switch (pigType) {
        case 1: //普通🐷
            p= new Pig(2, 1);
            break;
        case 2: //快速🐷
            p= new Pig(3, 1);
            break;
        case 3: //厚血🐷
            p= new Pig(1, 2);
            break;
        case 4: //箭猪🐷
            p=new PigReverse(1, 1);
            break;
        case 5: //变轨🐷
            p=new PigSwap(2, 1);
            break;
        case 6: //分身🐷
            p=new PigClone(2, 2);
            break;
        case 7: //隐形🐷
            p=new PigHide(2, 1);
            break;
        default://小猪
            p=new Pig(1, 1);
            break;
    }
    p->autorelease();
    return p;
}


