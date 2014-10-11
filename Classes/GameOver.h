//
//  GameOver.h
//  ddgame
//
//  Created by aaa on 14-10-8.
//
//

#ifndef __ddgame__GameOver__
#define __ddgame__GameOver__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class GameOver: public Layer
{
    int gameType=0;
public:
    static GameOver* Create(int i)
    {
        auto g=GameOver::create();
        g->gameType=i;
        return g;
    }
    virtual bool init();
    CREATE_FUNC(GameOver);
    
}
;
#endif /* defined(__ddgame__GameOver__) */
