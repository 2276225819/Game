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
    auto Listen = EventListenerTouchOneByOne::create();
    Listen->onTouchBegan =[&](Touch *pTouch, Event *pEvent){
        //GameLayer::Click();
        return true;
    };
    Listen->onTouchMoved =[&](Touch *pTouch, Event *pEvent){
    
    
    };
    return true;
}