//
//  Pig.cpp
//  ddgame
//
//  Created by aaa on 14-10-8.
//
//

#include "Pig.h"
#include "PigLayer.h"

const int RectSize = 640;

Vec2 Pig::FlagToVec(Vec2 v)
{
    return v*RectSize;
}

void Pig::Drag(cocos2d::Vec2 v)
{
    Hp--;
    runAction(
              Repeat::
              create(
                     Sequence::
                     create(
                            RotateBy::
                            create(0.05, -10),
                            RotateBy::
                            create(0.05, 10), NULL), 3));
    auto lText=String::createWithFormat("%d",Hp)->getCString();
    auto hSprite=LabelTTF::create(lText, "yahei", 30);
    hSprite->setColor(Color3B(255,255,0));
    hSprite->setPosition(getPosition());
    hSprite->runAction(MoveBy::create(1, Vec2(0,80)));
    hSprite->runAction(Sequence::create(FadeOut::create(1),CallFuncN::create([](Node* me){
        me->getParent()->removeChild(me);
    
    }), NULL));
    getParent()-> addChild(hSprite,10);
    
}

void Pig::Click()
{
    
}
bool Pig::isDie()
{
    return Hp==0;
}
void Pig::Remove()
{
    runAction(Sequence::create(DelayTime::create(0.01),CallFunc::create([&]{
        getParent()->removeChild(this);
        
    }), NULL));
}

void Pig::Run(Vec2 v)
{
    Vec2 po=v*RectSize;                  //起点位置
    setPosition(po);
    Vec2 pt=Vec2(RectSize-po.x , RectSize-po.y);//对角线位置
    
    runAction(Sequence::create(MoveTo::create(Speed, pt),CallFunc::create([this](){
        this->Remove();
    }), NULL));
}

void Pig::RunAt(Vec2 v,Vec2 pos)
{
    setPosition(pos);
    Vec2 po=v*RectSize;                  //起点位置

    //Vec2 pt=Vec2(RectSize-po.x , RectSize-po.y);//对角线位置
    
    runAction(Sequence::create(MoveTo::create(Speed, po),CallFunc::create([this](){
        this->Remove();
    }), NULL));
}
   const Vec2 Flag[8] = {Vec2(0,0),Vec2(0,0.5),Vec2(0,1),Vec2(0.5,1),Vec2(1,1),Vec2(1,0.5),Vec2(1,0),Vec2(0.5,0)};


void PigClone::Avatar() //分身函数
{
    int Rand = arc4random()%8;
    for (int i=0; i<4; i++) {
        Rand+=arc4random()%2+1;
        auto parent = (PigLayer*)getParent();
        auto child = createPig(1);
        child->RunAt(Flag[(Rand)%8],this->getPosition());
        parent->addChild(child);
    }
    this->Remove();
}
void PigSwap::Run(Vec2 v)//变轨猪移动
{
    Pig::Run(v);
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
    v=FlagToVec(v);
    auto mt = MoveTo::create(this->Speed, v);
    auto fo = FadeOut::create(1);
    auto fi = FadeIn::create(1);
    this->runAction(Sequence::create(mt,fo,fi, NULL));
}

Pig::Pig(int speed,int hp)
{
    this->Hp=hp;
    this->MaxHp=hp;
    this->Speed=speed;
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
        default://test小猪
            p=new Pig(3, 3);
            break;
    }
    p->autorelease();
    return p;
}

PigReverse::PigReverse(int speed,int hp):Pig(speed,hp) {

};

PigSwap::PigSwap(int speed,int hp):Pig(speed,hp) {

};
PigClone::PigClone(int speed,int hp):Pig(speed,hp) {

};

PigHide::PigHide(int speed,int hp):Pig(speed,hp) {

};




