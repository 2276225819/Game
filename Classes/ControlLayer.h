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

class RockerControl:public ControlLayer,JoyStickDelegate
{
public:
    RockerControl();
    int ag=0;
    virtual void onCCJoyStickUpdate(Node *sender, float angle, cocos2d::Point direction, float power){
        ag=angle;
    }
    virtual void onCCJoyStickActivated(Node *sender){
    
    }
    virtual void onCCJoyStickDeactivated(Node *sender){
        ag=(ag>0?ag:360+ag);
        int tg= 7-((int)(ag/45 + 2.5)%8);
        onDrag(tg);
    }
};

#endif /* defined(__ddgame__ControlLayer__) */
