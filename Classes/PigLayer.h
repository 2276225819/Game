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
    void removeChild(Node* child, bool cleanup = true);
    
    bool each(std::function<bool(Pig*)> fn);
    static Pig* createPigById(int pigType);
    std::function<void(Pig*)> onFlee;
    
}
;


#endif /* defined(__ddgame__PigLayer__) */
