//
//  GameLayer.cpp
//  ddgame
//
//  Created by mimix on 14-10-8.
//
//

#include "GameLayer.h"
Scene* GameLayer::CreateScene()
{
    auto s=Scene::create();
    auto g=GameLayer::create();
    s->addChild(g);
    return s;
}


bool GameLayer::init()
{
    
    
    
    return true;
}