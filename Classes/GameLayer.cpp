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
    root->addChild(pigs=PigLayer::create());
    root->addChild(labScore=LabelTTF::create("TEXT", "yahei", 30));
    ModeA();
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
        for (int i=0,len=(int)(ls.size()); i<len; i++) {
            auto pig=(Pig *)ls.at(i);
            if (pig->getBoundingBox().containsPoint(pTouch->getLocation()))
                (pig)->Click();
        }
        return true;
    };
    Listen->onTouchEnded =[&](Touch *pTouch, Event *pEvent){
        Vec2 np=pTouch->getLocation();
        Vec2 v= -_op + np;
        float ag= CC_RADIANS_TO_DEGREES(v.getAngle());
        ag=(ag>0?ag:360+ag);
        int tg= 7-((int)(ag/45 + 2.5)%8);
        log("Drag:%d",tg);
        auto ls=pigs->getChildren();
        for (int i=(int)(ls.size())-1; i>=0; i--) {
            auto pig=(Pig *)ls.at(i);
            if (pig->getTag()==tg)
            {
                (pig)->Drag(Flag[tg]);
                if (pig->isDie()) {
                    addScore(pig->MaxHp);
                    pig->Remove();
                }
            }
        }
    };
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(Listen, this);
}



int score=0;
void GameLayer::addScore(int i)
{
    score+=i;
    labScore->setString(String::createWithFormat("%d",score)->getCString());

}


void GameLayer::ModeA()//游戏模式一：随机创建
{
    ActionInterval* ac;
    ac=Sequence::create(CallFunc::create([&]{
        pigs->addRndPig();
    }),DelayTime::create(1), NULL);
    ac=RepeatForever::create(ac);
    runAction(ac);
}