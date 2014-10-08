#ifndef __ddgame__StartLayer__
#define __ddgame__StartLayer__
#include "cocos2d.h"
USING_NS_CC;

class StartLayer:public Layer
{
public:
    bool init();
    CREATE_FUNC(StartLayer);
    
    void selectMap();
    void selectMode();
};




#endif /* defined(__ddgame__StartLayer__) */
