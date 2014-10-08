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
    addChild(pigs=PigLayer::create());
    
    auto Listen = EventListenerTouchOneByOne::create();
    Listen->onTouchBegan =[&](Touch *pTouch, Event *pEvent){
        auto ls=pigs->getChildren();
        for (int i,len=ls.size(); i<len; i++) {
            auto pig=ls.at(i);
            if (pig->getBoundingBox().containsPoint(pTouch->getLocation()));
                //((Pig *)pig)->Click();
        }
        return true;
    };
    Vec2 op;
    Listen->onTouchMoved =[&](Touch *pTouch, Event *pEvent){
        op=pTouch->getLocation();
    };
    Listen->onTouchEnded =[&](Touch *pTouch, Event *pEvent){
        Vec2 v=pTouch->getLocation()-op;
        float ag= CC_RADIANS_TO_DEGREES(v.getAngle());
        ag=(ag>0?ag:ag+360)+90+45;
        int tg=ag/45;
        log("%d,    %f",tg,ag);
        
        /*
        auto ls=pigs->getChildren();
        for (int i,len=ls.size(); i<len; i++) {
            auto pig=ls.at(i);
            if (pigs->getTag()==1);
                //((Pig *)pig)->Click();
        }
         */

    };
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(Listen, this);
    return true;
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