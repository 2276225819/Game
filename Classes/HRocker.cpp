//
//  HRocker.cpp
//  game
//
//  Created by aaa on 14-9-23.
//
//

#include "HRocker.h"

HRocker* HRocker::createHRocker(const char *rockerImageName, const char *rockerBGImageName, cocos2d::Point position)
{
    HRocker* layer = HRocker::create();
    if(layer)
    {
        layer->rockerInit(rockerImageName, rockerBGImageName, position);
        return layer;
    }
    
    CC_SAFE_DELETE(layer);
    return NULL;
    
}

void HRocker::rockerInit(const char *rockerImageName, const char *rockerBGImageName, cocos2d::Point position)
{
    //添加摇杆背景图
    Sprite* spRockerBG = Sprite::create(rockerBGImageName);
    spRockerBG->setVisible(false);
    spRockerBG->setPosition(position);
    addChild(spRockerBG, 0, tag_rockerBG);
    
    //添加摇杆上方那个可移动的图
    Sprite* spRocker = Sprite::create(rockerImageName);
    spRocker->setVisible(false);
    spRocker->setPosition(position);
    addChild(spRocker, 1, tag_rocker);
    
    //摇杆背景图坐标
    rockerBGPosition = position;
    
    //摇杆背景图半径
    rockerBGR = spRockerBG->getContentSize().width*0.5;
}

//启动摇杆
void HRocker::startRocker(bool _isStopOther,Node * Obj)
{
    //精灵设置可见，设置监听
    Sprite* rocker = (Sprite*) getChildByTag(tag_rocker);
    rocker->setVisible(true);
    
    Sprite* rockerBG = (Sprite*) getChildByTag(tag_rockerBG);
    rockerBG->setVisible(true);
    //auto listener = EventListenerTouchOneByOne::create();
    auto listener = EventListenerTouchAllAtOnce::create();
    
    //listener->setSwallowTouches(true);
    listener->onTouchesBegan = CC_CALLBACK_2(HRocker::onTouchesBegan, this);
    listener->onTouchesMoved = CC_CALLBACK_2(HRocker::onTouchesMoved, this);
    listener->onTouchesEnded = CC_CALLBACK_2(HRocker::onTouchesEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, rockerBG);
}

//停止摇杆
void HRocker::stopRocker()
{
    //精灵设置不可见，取消监听
    Sprite* rocker = (Sprite*)getChildByTag(tag_rocker);
    rocker->setVisible(false);
    
    Sprite* rockerBG = (Sprite*)getChildByTag(tag_rockerBG);
    rockerBG->setVisible(false);
    
    _eventDispatcher->pauseEventListenersForTarget(this);
}

//得到两坐标的角度值
float HRocker::getRad(cocos2d::Point pos1, cocos2d::Point pos2)
{
    //得到两点的坐标x,y坐标值
    float px1 = pos1.x;
    float py1 = pos1.y;
    float px2 = pos2.x;
    float py2 = pos2.y;
    
    //求出两边长度
    float x = px2 - px1;
    float y = py1 - py2;
    
    //开方   与  几次方 公式
    float xie = sqrt(pow(x, 2) + pow(y , 2));
    float cos = x/xie;
    
    //反余弦定理，知道两边长求角度：cos = 邻边/斜边
    float rad = acos(cos);
    
    //当触屏Y坐标 <摇杆的Y坐标时，取反值
    if(py1 > py2)
    {
        rad = -rad;
    }
    
    return rad;
    
}

//得到与角度对应的半径为r的圆上一坐标点
Point HRocker::getAnglePosition(float r, float angle)
{
    return Vec2(r*cos(angle), r*sin(angle));
}


void HRocker::onTouchesBegan(std::vector<Touch *> touches, cocos2d::Event *unused_event)
{
    //log("123");

    for(int i = 0;i<touches.size();i++)
    {
        Sprite* sp = (Sprite*)getChildByTag(tag_rocker);
        
        //得到触屏点坐标
        Point point = touches.at(i)->getLocation();
        //Point point = touches.at(0)->getLocation();
        //判断是否点击到sp这个精灵：boundingBox()精灵大小之内的所有坐标
        if(sp->boundingBox().containsPoint(point))
        {
            isCanMove = true;
        }
    }
}

void HRocker::onTouchesMoved(std::vector<Touch *> touches, cocos2d::Event *unused_event)
{
    //log("move");
    if(!isCanMove)
        return;
    Sprite* sp = (Sprite*)getChildByTag(tag_rocker);
    
    
    for(int i = 0;i<touches.size();i++)
    {
        Sprite* sp = (Sprite*)getChildByTag(tag_rocker);
        
        //得到触屏点坐标
        Point point = touches.at(i)->getLocation();
        //Point point = touches.at(0)->getLocation();
        //判断是否点击到sp这个精灵：boundingBox()精灵大小之内的所有坐标
        if(sp->boundingBox().containsPoint(point))
        {
    Point point = touches.at(i)->getLocation();
    
    //判断两个圆心的距离是否大于摇杆背景的半径
    if(sqrt(pow(point.x - rockerBGPosition.x, 2) + pow(point.y - rockerBGPosition.y, 2)) >= rockerBGR)
    {
        //得到触点与摇杆背景圆心形成的角度
        angle = getRad(rockerBGPosition, point);
        
        //确保小圆运动范围在背景圆内
        sp->setPosition(getAnglePosition(rockerBGR, angle) + Vec2(rockerBGPosition.x, rockerBGPosition.y));
        
        point=getAnglePosition(rockerBGR, angle) + Vec2(rockerBGPosition.x, rockerBGPosition.y);////
        
        
        //sp->setPosition(getAnglePosition(rockerBGR, angle) + Vec2(rockerBGPosition.x, rockerBGPosition.y));
        
    }
    else {
        //触点在背景圆内则跟随触点运动
        sp->setPosition(point);
        
    } 
    //得到触点与摇杆背景圆心形成的角度
     angle = -getRad(rockerBGPosition, point);////
     v= point -rockerBGPosition;////
    
        }
    }
}

void HRocker::onTouchesEnded(std::vector<Touch *> touches, cocos2d::Event *unused_event)
{
    if(!isCanMove)
        return;
    
    Sprite* rocker = (Sprite*)getChildByTag(tag_rocker);
    
    Sprite* rockerBG = (Sprite*)getChildByTag(tag_rockerBG);
    
    rocker->stopAllActions();
    
    rocker->runAction(MoveTo::create(0.08, rockerBG->getPosition()));
    
    isCanMove = false;
     (v=Vec2(0,0));
    
}
