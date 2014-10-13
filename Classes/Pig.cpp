//
//  Pig.cpp
//  ddgame
//
//  Created by aaa on 14-10-8.
//
//

#include "Pig.h"
#include "PigLayer.h"
 
bool PigClick::Drag(int tag)
{
    
}
void PigClick::Click()
{
    hit();
    Hp--;
}
void PigClick::Die()
{
    stopAllActions();
    runAction(
              Sequence::
              create(
                     Repeat::
                     create(
                            Sequence::
                            create(
                                   RotateBy::
                                   create(0.05, -10),
                                   RotateBy::
                                   create(0.05, 10),
                                   NULL),
                            3),
                     FadeOut::
                     create(0.5),
                     CallFunc::
                     create([this]{Kill(); }),
                     NULL)  );
 
}

const Vec2 Flag[8] = {Vec2(0,0),Vec2(0,0.5),Vec2(0,1),Vec2(0.5,1),Vec2(1,1),Vec2(1,0.5),Vec2(1,0),Vec2(0.5,0)};


void PigClone::Avatar() //分身函数
{
    int Rand = arc4random()%8;
    auto parent = (PigLayer*)getParent();
    for (int i=0; i<4; i++) {
        Rand+=arc4random()%2+1;
        auto child = PigLayer::createPigById(8);
        child->RunAt(Flag[(Rand)%8],this->getPosition());
        parent->addChild(child);
        child->setTag((Rand%8));
    }
    this->Kill();
}

void PigSwap::Orbit()
{
    int _Flag = (this->getTag()+arc4random()%8)%8;
    this->RunAt(Flag[_Flag],this->getPosition());
    this->setTag(_Flag);
}
void PigSwap::Run(Vec2 v)//变轨猪移动
{
    this->v=v;
    setPosition(FlagToVec(v));
    v=Vec2(0.5, 0.5);
    v=FlagToVec(v);
    auto mt = MoveTo::create(this->Speed, Vec2(RectSize - v.x, RectSize - v.y));
    this->runAction(Sequence::create(mt,CallFunc::create(CC_CALLBACK_0(PigSwap::Orbit , this)), NULL));
}
void PigReverse::Run(Vec2 v)//箭猪移动
{
    Pig::Run(Vec2(1-v.x,1-v.y));
}
void PigReverse::Die()
{
    stopAllActions();
    v=Vec2(1-v.x,1-v.y);
    
    runAction(Sequence::create(MoveTo::create(0.2, v*640),CallFunc::create([this]{
        Kill();
    }) , NULL) );
}
void PigClone::Run(Vec2 v)//分身猪移动
{
    this->v=v;
    setPosition(FlagToVec(v));
    v=Vec2(0.5, 0.5);
    v=FlagToVec(v);
    auto mt = MoveTo::create(this->Speed, Vec2(RectSize - v.x, RectSize - v.y));
    this->runAction(Sequence::create(mt,CallFunc::create(CC_CALLBACK_0(PigClone::Avatar, this)), NULL));
}


void PigHide::Run(Vec2 v)
{
    auto fo = FadeOut::create(0.3);
    auto fi = FadeIn::create(4);
    Pig::Run(v);
    this->runAction(Sequence::create(fo,fi, NULL));
} 

PigReverse::PigReverse(int speed,int hp):Pig(speed,hp) {
    
};

PigSwap::PigSwap(int speed,int hp):Pig(speed,hp) {

};

PigClick::PigClick(int speed,int hp):Pig(speed,hp) {
    
};

PigClone::PigClone(int speed,int hp):PigClick(speed,hp) {

};

PigHide::PigHide(int speed,int hp):Pig(speed,hp) {
    
};






