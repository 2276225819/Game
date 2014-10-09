#ifndef __ddgame__StartLayer__
#define __ddgame__StartLayer__
#include "cocos2d.h"
USING_NS_CC;

class IndexLayer:public Layer
{
public:
    bool init();
    void selectMap();
    void selectMode();
    CREATE_FUNC(IndexLayer);
};




#endif /* defined(__ddgame__StartLayer__) */
