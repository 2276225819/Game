#ifndef __ddgame__GameLayer__
#define __ddgame__GameLayer__
#include "cocos2d.h"
#include "IMode.h"
USING_NS_CC;

class GameLayer:public Layer
{
    IMode mode;
public:
    void Drag(Vec2 Flag);
    void Click();
    bool init();
    CREATE_FUNC(GameLayer);
    static Scene* CreateScene(IMode mode) ;
};






#endif /* defined(__ddgame__GameLayer__) */
