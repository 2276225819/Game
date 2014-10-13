//
//  StartScene.h
//  ddgame
//
//  Created by mimix on 14-10-10.
//
//

#ifndef __ddgame__StartScene__
#define __ddgame__StartScene__

#include "cocos2d.h"
USING_NS_CC;


class StartScene:public Scene
{
public:
    int PigId;
    bool init();
    void PigAnimation(Node * n);
    CREATE_FUNC(StartScene);
};

#endif /* defined(__ddgame__StartScene__) */
