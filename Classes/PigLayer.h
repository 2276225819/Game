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
    //virtual bool init();
    const Vec2 Flag[8] = {Vec2(0,0),Vec2(0,0.5),Vec2(0,1),Vec2(0.5,1),Vec2(1,1),Vec2(1,0.5),Vec2(1,0),Vec2(0.5,0)};
    void addPig(int Tag,Pig Flag);
    void addRndPig(int Tag);
}
;


#endif /* defined(__ddgame__PigLayer__) */
