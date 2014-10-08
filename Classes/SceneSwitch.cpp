//
//  SceneSwitch.cpp
//  ddgame
//
//  Created by aaa on 14-10-8.
//
//

#include "SceneSwitch.h"

void SceneSwitch::Index()
{
    Scene * s = Scene::create();
    auto Index = IndexLayer::create();
    s->addChild(Index);
    Director::getInstance()->replaceScene(s);
}
void SceneSwitch::Playing()
{
    Scene * s = Scene::create();
    auto Index = IndexLayer::create();
    s->addChild(Index);
    Director::getInstance()->replaceScene(s);
}

void SceneSwitch::GameOver()
{
    Scene * s = Scene::create();
    auto Index = IndexLayer::create();
    s->addChild(Index);
    Director::getInstance()->replaceScene(s);
}
