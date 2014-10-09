//
//  GameLayer.cpp
//  ddgame
//
//  Created by mimix on 14-10-8.
//
//

#include "GameLayer.h"

const Vec2 Flag[8] = {Vec2(0,0),Vec2(0,0.5),Vec2(0,1),Vec2(0.5,1),Vec2(1,1),Vec2(1,0.5),Vec2(1,0),Vec2(0.5,0)};


Scene* GameLayer::CreateScene(IMode mode)
{
    auto s=Scene::create();
    auto g=GameLayer::create();
    g->mode=mode;
    s->addChild(g);
    return s;
}

bool GameLayer::init()
{
    auto root=LayerColor::create(Color4B(100, 100, 100, 255), 630, 630);
    addChild(root);
    
    
    addChild(pigs=PigLayer::create());
    addChild(labScore=LabelTTF::create("TEXT", "yahei", 30));
    
    
    
    
    initEvent();
    return true;
}

Vec2 _op;
void GameLayer::initEvent()
{
    auto Listen = EventListenerTouchOneByOne::create();
    Listen->onTouchBegan =[&](Touch *pTouch, Event *pEvent){
        _op=pTouch->getLocation();
        auto ls=pigs->getChildren();
        for (int i=0,len=ls.size(); i<len; i++) {
            auto pig=ls.at(i);
            if (pig->getBoundingBox().containsPoint(pTouch->getLocation()))
                ((Pig *)pig)->Click();
        }
        return true;
    };
    Listen->onTouchEnded =[&](Touch *pTouch, Event *pEvent){
        Vec2 np=pTouch->getLocation();
        Vec2 v= -_op + np;
        float ag= CC_RADIANS_TO_DEGREES(v.getAngle());
        ag=(ag>0?ag:360+ag);
        int tg= 8-((int)(ag/45 + 2.5)%8);
        
        auto ls=pigs->getChildren();
        for (int i,len=ls.size(); i<len; i++) {
            auto pig=ls.at(i);
            if (pigs->getTag()==1)
                ((Pig *)pig)->Drag(Flag[tg]);
        }
    };
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(Listen, this);
}


void GameLayer::ModeA()//游戏模式一：随机创建
{
    ActionInterval* ac;
    ac=Sequence::create(CallFunc::create([&]{
        pigs->addRndPig();
    }),DelayTime::create(1000), NULL);
    ac=RepeatForever::create(ac);
    runAction(ac);
}