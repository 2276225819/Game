//
//  HardMode.cpp
//  ddgame
//
//  Created by mimix on 14-10-10.
//
//

#include "HardMode.h"

 

bool HardMode:: init()//游戏模式二：疯狂模式
{
    GameLayer::init();
    
    
        ActionInterval* ac;
    ac=Sequence::create(CallFunc::create([&]{
        pigs->addRndPig();
    }),DelayTime::create(1), NULL);
    ac=RepeatForever::create(ac);
    runAction(ac);
    
    
    
    return true;
}