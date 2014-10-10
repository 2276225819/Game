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
    void start();
    bool init();
    CREATE_FUNC(EasyMode);
};

#endif /* defined(__ddgame__EaseMode__) */
