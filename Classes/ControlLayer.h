#ifndef __ddgame__ControlLayer__
#define __ddgame__ControlLayer__
#include "cocos2d.h"
#include "JoyStick.h"
USING_NS_CC;

class ControlLayer:public Layer
{
   
protected:
     Size s;
    EventListenerTouchOneByOne* listen;
    Vec2 _op;
public:
    std::function<void(int)> onDrag;
    std::function<void(Vec2)> onClick;
    std::function<void(Vec2)> onMove;
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

class RockerControl:public ControlLayer
{
public:
    RockerControl();
};


class f:public JoyStickDelegate
{
    virtual void onCCJoyStickUpdate(Node *sender, float angle, cocos2d::Point direction, float power){}
    virtual void onCCJoyStickActivated(Node *sender){}
    virtual void onCCJoyStickDeactivated(Node *sender){}
};

#endif /* defined(__ddgame__ControlLayer__) */
