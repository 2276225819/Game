//
//  basePig.cpp
//  ddgame
//
//  Created by aaa on 14-10-9.
//
//

#include "basePig.h"


Vec2 Pig::FlagToVec(Vec2 v)
{
    return v*RectSize;
}

<<<<<<< HEAD
void Pig::Drag(int tag)
=======
void Pig::Drag(cocos2d::Vec2 v)
>>>>>>> FETCH_HEAD
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
    
    Vec2 pt=Vec2(RectSize-po.x , RectSize-po.y);//对角线位置
    
    runAction(Sequence::create(MoveTo::create(Speed, pt),CallFunc::create([this](){
        this->Remove();
    }), NULL));
}