//
//  Pig.cpp
//  ddgame
//
//  Created by aaa on 14-10-8.
//
//

#include "Pig.h"
#include "PigLayer.h"
 
void PigClick::Drag(int tag)
{
    
}
void PigClick::Click()
{
    
}

   const Vec2 Flag[8] = {Vec2(0,0),Vec2(0,0.5),Vec2(0,1),Vec2(0.5,1),Vec2(1,1),Vec2(1,0.5),Vec2(1,0),Vec2(0.5,0)};



void PigClone::Avatar() //分身函数
{
    int Rand = arc4random()%8;
    auto parent = (PigLayer*)getParent();
    for (int i=0; i<4; i++) {
        Rand+=arc4random()%2+1;
        auto child = createPig(8);
        child->RunAt(Flag[(Rand)%8],this->getPosition());
        parent->addChild(child);
        child->setTag((Rand%8));
    }
    this->Remove();
}

void PigSwap::Orbit()
{
    int _Flag = this->getTag();
    this->RunAt(Flag[(_Flag+arc4random()%8)%8],this->getPosition());
}
void PigSwap::Run(Vec2 v)//变轨猪移动
{
    setPosition(FlagToVec(v));
    v=Vec2(0.5, 0.5);
    v=FlagToVec(v);
    auto mt = MoveTo::create(this->Speed, Vec2(RectSize - v.x, RectSize - v.y));
    this->runAction(Sequence::create(mt,CallFunc::create(CC_CALLBACK_0(PigSwap::Orbit , this)), NULL));
}
void PigReverse::Run(Vec2 v)//反向猪移动
{
    Pig::Run(v);
}
void PigClone::Run(Vec2 v)//分身猪移动
{
    setPosition(FlagToVec(v));
    v=Vec2(0.5, 0.5);
    v=FlagToVec(v);
    auto mt = MoveTo::create(this->Speed, Vec2(RectSize - v.x, RectSize - v.y));
    this->runAction(Sequence::create(mt,CallFunc::create(CC_CALLBACK_0(PigClone::Avatar, this)), NULL));
}

void PigHide::Run(Vec2 v)
{
    auto fo = FadeOut::create(1);
    auto fi = FadeIn::create(1);
    Pig::Run(v);
    this->runAction(Sequence::create(fo,fi, NULL));
}

const int MaxSpeed = 4;
std::string s[] ={"普通","快速","厚血","箭猪","变轨","分身","隐形","分身猪"};
Pig::Pig(int speed,int hp)
{
    this->Hp=hp;
    this->MaxHp=hp;
    this->Speed=MaxSpeed - speed;
    this->initWithFile("ice.png");
    this->setScale(0.1, 0.1);
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
            p= new Pig(1, 3);
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
        case 8://分身猪🐷
            p=new PigClick(2,1);
            break;
        default://test小猪
            p=new Pig(3, 3);
            break;
    }
    p->addChild(LabelTTF::create(s[pigType-1], "yahai",200));//, const std::string &fontName, float fontSize)
    p->autorelease();
    p->setColor(Color3B(pigType*35, 0, 0));
    return p;
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






