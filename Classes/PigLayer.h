//
//  PigLayer.h
//  ddgame
//
//  Created by aaa on 14-10-8.
//
//

#ifndef __ddgame__PigLayer__
#define __ddgame__PigLayer__

#include <stdio.h>
#include "cocos2d.h"
#include "Pig.h"

USING_NS_CC;

class PigLayer:public Layer
{
   
public:
    void pigDelete();
    virtual bool init();
    CREATE_FUNC(PigLayer);
public:
    void addPig(int Fx,int Tp);
    void addRndPig();
    void each(std::function<bool(Pig*)> fn);
    static Pig* createPig(int pigType);
}
;

//Vec2 Flag[8] = {Vec2(0,0),Vec2(0,0.5),Vec2(0,1),Vec2(0.5,1),Vec2(1,1),Vec2(1,0.5),Vec2(1,0),Vec2(0.5,0)};


#endif /* defined(__ddgame__PigLayer__) */
