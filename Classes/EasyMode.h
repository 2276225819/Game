//
//  EaseMode.h
//  ddgame
//
//  Created by mimix on 14-10-10.
//
//

#ifndef __ddgame__EasyMode__
#define __ddgame__EasyMode__

#include "GameLayer.h"

class EasyMode :public GameLayer
{
public:
    bool init();
    bool onPigDelete(Pig *pig);
    CREATE_FUNC(EasyMode);
};

class TestMode :public GameLayer
{
public:
    bool init(); 
    CREATE_FUNC(TestMode);
};

#endif /* defined(__ddgame__EaseMode__) */
