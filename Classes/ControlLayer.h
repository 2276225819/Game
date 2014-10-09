#ifndef __ddgame__ControlLayer__
#define __ddgame__ControlLayer__
#include "cocos2d.h"
USING_NS_CC;

class ControlLayer:public Layer
{
protected:
    EventListenerTouchOneByOne* listen;
    Vec2 _op;
public:
    std::function<void(int)> onDrag;
    std::function<void(Vec2)> onClick;
public:
    ControlLayer();
    ~ControlLayer();
    bool init();
    CREATE_FUNC(ControlLayer);
    static ControlLayer* CreateAt(int type);
};

class TouchControl:public ControlLayer
{
public:
    TouchControl();
};

class DragControl:public ControlLayer
{
public:
    DragControl();
};



#endif /* defined(__ddgame__ControlLayer__) */
