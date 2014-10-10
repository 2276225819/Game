//
//  EaseMode.cpp
//  ddgame
//
//  Created by mimix on 14-10-10.
//
//

#include "EasyMode.h"

void EasyMode::start()//游戏模式一：随机创建
{
    ActionInterval* ac;
    ac=Sequence::create(CallFunc::create([&]{
        pigs->addRndPig();
    }),DelayTime::create(4), NULL);
    ac=RepeatForever::create(ac);
    runAction(ac);
}

bool EasyMode:: init()
{
    GameLayer::init();
    return true;
}