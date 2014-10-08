#ifndef __ddgame__GameLayer__
#define __ddgame__GameLayer__
#include "cocos2d.h"
USING_NS_CC;

class GameLayer:public Layer
{
public:
    bool init();
    int gSize;
    CREATE_FUNC(GameLayer);
    static GameLayer* Create(int GridLenth)
    {
        auto g=new GameLayer();
        g->gSize=GridLenth;
        g->init();
        g->autorelease();
    }; 
};






#endif /* defined(__ddgame__GameLayer__) */
