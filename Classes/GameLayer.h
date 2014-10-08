#ifndef __ddgame__GameLayer__
#define __ddgame__GameLayer__
#include "cocos2d.h"
#include "IMode.h"
USING_NS_CC;

class GameLayer:public Layer
{
public:
    bool init();
    IMode mode;
    Scene* CreateScene();
    CREATE_FUNC(GameLayer);
    static GameLayer* Create(IMode mode)
    {
        auto g=new GameLayer();
        g->mode=mode;
        g->autorelease();
        return g;
    };
};






#endif /* defined(__ddgame__GameLayer__) */
