//
//  ControlLayer.cpp
//  ddgame
//
//  Created by mimix on 14-10-9.
//
//

#include "ControlLayer.h"



ControlLayer::ControlLayer()
{
    listen=EventListenerTouchOneByOne::create();
    listen->onTouchBegan =[&](Touch *pTouch, Event *pEvent){
        _op=pTouch->getLocation();
        onClick(_op);
        return true;
    };
    //listen->retain();
}
ControlLayer::~ControlLayer()
{
    //listen->release();
}
bool ControlLayer::init()
{
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(listen, this);
    return true;
}

ControlLayer* ControlLayer::CreateAt(int type)
{
    ControlLayer* ct;
    switch (type) {
        case 1:
            ct= new TouchControl();
            break;
        default:
            ct= new DragControl();
    }
    ct->init();
    ct->autorelease();
    return ct;
}



TouchControl::TouchControl():ControlLayer()
{
    
    const Vec2 Flag[8] = {Vec2(0,0),Vec2(0,0.5),Vec2(0,1),Vec2(0.5,1),Vec2(1,1),Vec2(1,0.5),Vec2(1,0),Vec2(0.5,0)};
    auto menu=Menu::create();
    menu->setContentSize(Size(100 ,100));
    menu->setPosition(640/2,-10);
    menu->ignoreAnchorPointForPosition(false);
    menu->setAnchorPoint(Vec2(0.5,1));
 
    //menu->setAnchorPoint(Vec2(1,1));

    for (int i=0; i<8; i++) {
        auto sQ=Sprite::create("CloseNormal.png");
        auto item=MenuItemSprite::create(sQ, sQ,[this,i](Ref* r){
            this->onDrag(i);
        });
        item->setPosition(Flag[i]*100);
        menu->addChild(item);
    }
    addChild(menu);
}

DragControl::DragControl():ControlLayer()
{
    listen->onTouchEnded =[&](Touch *pTouch, Event *pEvent){
        Vec2 np=pTouch->getLocation();
        Vec2 v= -_op + np;
        float ag= CC_RADIANS_TO_DEGREES(v.getAngle());
        ag=(ag>0?ag:360+ag);
        int tg= 7-((int)(ag/45 + 2.5)%8);
        onDrag(tg);
    };
}