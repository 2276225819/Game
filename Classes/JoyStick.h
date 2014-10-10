//
//  JoyStick.h
//  game
//
//  Created by DonCheung on 9/24/14.
//
//

#ifndef __game__JoyStick__
#define __game__JoyStick__

#include "cocos2d.h"

USING_NS_CC;

class JoyStickDelegate
{
public:
    virtual void onCCJoyStickUpdate(Node *sender, float angle, cocos2d::Point direction, float power) = 0;
    virtual void onCCJoyStickActivated(Node *sender) = 0;
    virtual void onCCJoyStickDeactivated(Node *sender) = 0;
};

class JoyStick : public Sprite
{

protected:
    virtual bool init();
    JoyStickDelegate *delegate;
    
private:
    virtual void onExit();
    virtual void onEnter();
    
    bool			isFollowTouch;
    bool			isCanVisible;
    bool			isAutoHide;
    
    void startTimer();
    void stopTimer();
    void timerUpdate(float f);
    
    void touchBegan(cocos2d::Point touchPoint);
    void resetTexturePosition();
    
    
    bool containsTouchLocation(Touch * touch);
    void updateTouchPoint(cocos2d::Point touchPoint);
    
    
    //touch event
    bool onTouchBegan(Touch *touch , Event *event);
    void onTouchEnded(Touch *touch , Event *event);
    //
    void onTouchMoved(Touch *touch , Event *event);
    void onTouchCancel(Touch *touch , Event *event);
    
public:
    JoyStick();
    ~JoyStick();
    
    
    CREATE_FUNC(JoyStick);
    //delegate getter & setter
    virtual void setDelegate(JoyStickDelegate *var)
    {
        delegate = var;
    }
    virtual JoyStickDelegate* getDelegate(void)const{return delegate;};
    
    
    CC_SYNTHESIZE(Sprite *, ball, Ball);
    CC_SYNTHESIZE(Sprite *, stick, Stick);
    CC_SYNTHESIZE(Sprite *, dock, Dock);
    
    CC_SYNTHESIZE_READONLY(int, moveAreaRadius, MoveAreaRadius);
    CC_SYNTHESIZE_READONLY(int, ballRadius, BallRadius);
    CC_SYNTHESIZE_READONLY(cocos2d::Rect, activeRect, ActiveRect);
    CC_SYNTHESIZE_READONLY(int, activeRadius, ActiveRadius);
    CC_SYNTHESIZE_READONLY(cocos2d::Point, currentPoint, CurrentPoint);
    CC_SYNTHESIZE_READONLY(bool, isTouched, IsTouched);
    CC_SYNTHESIZE_READONLY(bool, hasAnimation, HasAnimation);
    CC_SYNTHESIZE_READONLY(float, power, Power);
    CC_SYNTHESIZE_READONLY(float, angle, Angle);
    CC_SYNTHESIZE_READONLY(cocos2d::Point, direction, Direction);
    
    
    static JoyStick *create(int _ballRadius , int _moveAreaRadius , bool _isFollowTouch , bool _isCanVisible , bool _isAutoHide , bool _hasAnimation);
    
    void setBallWithFrameName(const std::string& filename);
    void setStickWithFrameName(const std::string& filename);
    void setDockWithFrameName(const std::string& filename);
    
    
    void setBallWithName(const std::string& filename);
    void setStickWithName(const std::string& filename);
    void setDockWithName(const std::string& filename);
    
    void setHitAreaWithRadius(int radius);
    void setHitAreaWithRect(cocos2d::Rect rect);
    

};

#endif /* defined(__game__JoyStick__) */
