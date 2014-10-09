//
//  Pig.cpp
//  ddgame
//
//  Created by aaa on 14-10-8.
//
//

#include "Pig.h"
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


void PigReverse::Run(Vec2 v)
{
    Pig::Run(v);//反向猪，和普通猪一样移动
}

void PigClone::Avatar() //分身函数
{
    
}

void PigClone::Run(Vec2 v)//分身猪移动
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
    this->MaxHp=hp;
    this->Speed=speed;
    this->initWithFile("ice.png");
    this->setScale(0.2, 0.2);
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


