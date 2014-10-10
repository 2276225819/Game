//
//  SceneSwitch.cpp
//  ddgame
//
//  Created by aaa on 14-10-8.
//
//

#include "SceneSwitch.h"

#include "IndexLayer.h"
#include "GameOver.h"
#include "GameLayer.h"
#include "EasyMode.h"

Scene* CreateScene(Layer* l)
{
    auto s=Scene::create();
    s->addChild(l);
    return s;
}

void SceneSwitch::Index()
{
    Scene * s = Scene::create();
    auto Index = IndexLayer::create();
    s->addChild(Index);
    Director::getInstance()->replaceScene(s);
}

void SceneSwitch::Seting()
{
    
    
    
    
    /*
     
     
     　”开始游戏“
     《难》 《易》
       《设置》
     
     
        “设置”
     《腰杆》 《滑动》
        《返回》
     */
}

void SceneSwitch::Playing(int Flag)
{
    GameLayer* m; 
    switch (Flag) {
        case 0:
            m = EasyMode::create();
            break;
        default:
            m = GameLayer::create();
    }
    Director::getInstance()->replaceScene(CreateScene(m));
    m->start();

}

void SceneSwitch::GameOver()
{
    Scene * s = Scene::create();
    auto Index = GameOver::create();
    s->addChild(Index);
    Director::getInstance()->replaceScene(s);
}
