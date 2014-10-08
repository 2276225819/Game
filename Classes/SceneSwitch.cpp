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
void SceneSwitch::Playing(int Number,int Flag)
{
    IMode m;
    switch (Flag) {
        case 0:
            m = IMode::getEasyMode(Number);
            break;
        case 1:
            m = IMode::getHardMode(Number);
    }
    Director::getInstance()->replaceScene(GameLayer::CreateScene(m));
}

void SceneSwitch::GameOver()
{
    Scene * s = Scene::create();
    auto Index = GameOver::create();
    s->addChild(Index);
    Director::getInstance()->replaceScene(s);
}
