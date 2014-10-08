//
//  Pig.h
//  ddgame
//
//  Created by aaa on 14-10-8.
//
//

#ifndef __ddgame__Pig__
#define __ddgame__Pig__

#include <stdio.h>
#include "cocos2d.h"

class Pig
{
    int Speed;
public:
    int Hp;
    void run();
public:
    static Pig create(int Tag);
}
;

#endif /* defined(__ddgame__Pig__) */
