//
//  EaseMode.cpp
//  ddgame
//
//  Created by mimix on 14-10-10.
//
//

#include "EasyMode.h"



bool EasyMode:: init()//游戏模式一：简单模式
{
    GameLayer::init();
    pigs->addRndPig();
    return true;
}
bool EasyMode::onPigDelete(Pig* pig)
{
    if (pig->isDie())
    {
        pig->Die();
        this->addScore(pig->Score);
        pigs->addRndPig();
        return false;
    }
    return true;
}

bool TestMode:: init()//游戏模式零：test
{
    GameLayer::init();
    
    ActionInterval* ac;//4秒出一只
    ac=Sequence::create(CallFunc::create([&]{
        pigs->addRndPig();
    }),DelayTime::create(4), NULL);
    ac=RepeatForever::create(ac);
    runAction(ac);
    
    return true;
}

