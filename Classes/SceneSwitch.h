//
//  SceneSwitch.h
//  ddgame
//
//  Created by aaa on 14-10-8.
//
//

#ifndef __ddgame__SceneSwitch__
#define __ddgame__SceneSwitch__

#include <stdio.h>
#include "cocos2d.h"


USING_NS_CC;

class SceneSwitch
{
public: 
    static void Seting();
    static void Starting();
    static void Playing(int Flag);
    static void GameOver();
};

#endif /* defined(__ddgame__SceneSwitch__) */
