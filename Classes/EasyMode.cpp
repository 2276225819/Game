//
//  EaseMode.cpp
//  ddgame
//
//  Created by mimix on 14-10-10.
//
//

#include "EasyMode.h"



bool EasyMode:: init()//游戏模式一：随机创建
{
    GameLayer::init();
     
    ActionInterval* ac;
    ac=Sequence::create(CallFunc::create([&]{
        pigs->addRndPig();
    }),DelayTime::create(4), NULL);
    ac=RepeatForever::create(ac);
    runAction(ac);
    
    
    return true;
}


bool TestMode:: init()//游戏模式：随机创建
{
    GameLayer::init();
    
    ActionInterval* ac;
    ac=Sequence::create(CallFunc::create([&]{
        pigs->addPig(rand()%8, 1);
    }),DelayTime::create(0.5), NULL);
    ac=RepeatForever::create(ac);
    runAction(ac);
    
    
    return true;
}

