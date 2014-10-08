//
//  SceneSwitch.cpp
//  ddgame
//
//  Created by aaa on 14-10-8.
//
//

#include "SceneSwitch.h"

  Scene* createScene(Layer* l)
{
    auto s=Scene::create();
    //auto g=GameLayer::create();
    s->addChild(g);
    return s;
}

void SceneSwitch::Index()
{
    auto Index = IndexLayer::create();
    Director::getInstance()->replaceScene(Index);
}
