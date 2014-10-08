//
//  GameLayer.cpp
//  ddgame
//
//  Created by mimix on 14-10-8.
//
//

#include "GameLayer.h"
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
            if (pig->getBoundingBox().containsPoint(pTouch->getLocation()))
                ((Pig *)pig)->Click();
        }
        return true;
    };
    
    
    Vec2 op;
    Listen->onTouchMoved =[&](Touch *pTouch, Event *pEvent){
        op=pTouch->getLocation();
    };
    Listen->onTouchEnded =[&](Touch *pTouch, Event *pEvent){
        
    };
    return true;
}

void GameLayer::ModeA()
{

}