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
    //const Vec2 Flag[] = {Vec2(0,0),{0,0.5},{0,1},{0.5,1},{1,1},{1,0.5},{1,0},{0.5,0}};
    void addPig(int Tag,Pig Flag);
    void addRndPig(int Tag);
}
;


#endif /* defined(__ddgame__PigLayer__) */
