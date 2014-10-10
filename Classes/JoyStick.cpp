//
//  JoyStick.cpp
//  game
//
//  Created by DonCheung on 9/24/14.
//
//

#include "JoyStick.h"

JoyStick* JoyStick::create(int _ballRadius, int _moveAreaRadius, bool _isFollowTouch, bool _isCanVisible, bool _isAutoHide, bool _hasAnimation)
{

    JoyStick *self = new JoyStick();
    
    if (self && self->init()) {
        
        self->ballRadius = _ballRadius;
        self->moveAreaRadius = _moveAreaRadius;
        self->power = 0;
        self->angle = 0;
        
        self->isFollowTouch = _isFollowTouch;
        self->isCanVisible = _isCanVisible;
        self->isAutoHide = _isAutoHide;
        self->hasAnimation = _hasAnimation;
        
        Size size = Director::getInstance()->getWinSize();
        self->setHitAreaWithRect(Rect(0, 0, size.width*0.5, size.height*0.5));
        
        self->setBall(Sprite::create());
        self->setStick(Sprite::create());
        self->setDock(Sprite::create());
        
        self->addChild(self->dock);
        self->addChild(self->stick);
        self->addChild(self->ball);
        
        
        if (!_isCanVisible) {
            self->setVisible(false);
        }else {
        
            if (_isAutoHide) {
                self->setVisible(false);
            }
        
        }
        
        
        
        auto dispatcher = Director::getInstance()->getEventDispatcher();
        auto touchListener = EventListenerTouchOneByOne::create();
//        touchListener->setSwallowTouches(false);
        touchListener->onTouchBegan = CC_CALLBACK_2(JoyStick::onTouchBegan,self);
        touchListener->onTouchMoved = CC_CALLBACK_2(JoyStick::onTouchMoved, self);
        touchListener->onTouchEnded = CC_CALLBACK_2(JoyStick::onTouchEnded, self);
        touchListener->onTouchCancelled = CC_CALLBACK_2(JoyStick::onTouchCancel, self);
        dispatcher->addEventListenerWithSceneGraphPriority(touchListener, self);
        
        self->autorelease();
        
        return self;
        
    }

    CC_SAFE_DELETE(self);
    return NULL;
}

JoyStick::JoyStick()
{}
JoyStick::~JoyStick()
{}

bool JoyStick::init() {

    if (!Sprite::init()) {
        return false;
    }
    return true;
}

void JoyStick::onEnter()
{
    Sprite::onEnter();
    
}

void JoyStick::onExit()
{
    Sprite::onExit();
    
    
}

#pragma mark -
#pragma mark touch event
bool JoyStick::onTouchBegan(Touch *touch, Event *event)
{
    if (!this->containsTouchLocation(touch)) {
        return false;
    }
    
    Point touchPoint = touch->getLocationInView();
    touchPoint = Director::getInstance()->convertToGL(touchPoint);
    this->touchBegan(touchPoint);
    return true;
}

void JoyStick::onTouchEnded(Touch *touch, Event *event)
{
    
    if (isTouched) {
        if (isAutoHide && isCanVisible) {
            this->setVisible(false);
        }
        
        isTouched = false;
        this->stopTimer();
        this->resetTexturePosition();
    }
    
}
void JoyStick::onTouchMoved(Touch *touch , Event *event)
{
    Point touchPoint = touch->getLocationInView();
    touchPoint = Director::getInstance()->convertToGL(touchPoint);
    
    if (isTouched) {
        this->updateTouchPoint(touchPoint);
    }
}
void JoyStick::onTouchCancel(Touch *touch , Event *event)
{
}


void JoyStick::touchBegan(Point touchPoint)
{
    currentPoint = touchPoint;
    isTouched = true;
    
    if (isAutoHide && isCanVisible) {
        this->setVisible(true);
    }
    
    if (isFollowTouch) {
        this->setPosition(touchPoint);
    }
    
    this->ball->stopAllActions();
    updateTouchPoint(touchPoint);
    this->startTimer();
}

bool JoyStick::containsTouchLocation(cocos2d::Touch *touch)
{

    Point touchPoint = touch->getLocationInView();
    touchPoint = Director::getInstance()->convertToGL(touchPoint);
    if (this->activeRadius > 0) {
        if (touchPoint.distance(this->getParent()->convertToWorldSpace(this->getPosition()))< this->activeRadius) {
            return true;
        }
    }
    
    if (this->activeRect.size.width > 0 && this->activeRect.size.height > 0) {
        if (touchPoint.x > this->activeRect.origin.x && touchPoint.x < this->activeRect.origin.x + this->activeRect.size.width && touchPoint.y > this->activeRect.origin.y && touchPoint.y < this->activeRect.origin.y + this->activeRect.size.height) {
            return true;
        }
    }
    
    return false;

}
void JoyStick::resetTexturePosition()
{
    power = 0;
    angle = 0;
    
    currentPoint = Point::ZERO;
    this->stick->setPosition(Point::ZERO);
    this->stick->setScaleX(power);
    
    if (!isAutoHide && isCanVisible && hasAnimation) {
        auto action = MoveTo::create(0.5, Point::ZERO);
        this->ball->runAction(EaseElasticOut::create(action));
    }else
        this->ball->setPosition(Point::ZERO);

}

void JoyStick::setHitAreaWithRadius(int radius)
{
    this->activeRadius = radius;
    this->activeRect = Rect::ZERO;

}
void JoyStick::setHitAreaWithRect(cocos2d::Rect rect)
{
    this->activeRect = rect;
    this->activeRadius = 0;
}


void JoyStick::updateTouchPoint(Point touchPoint)
{
    Point selfposition = this->getParent()->convertToWorldSpace(this->getPosition());
    if (touchPoint.getDistance(selfposition) > (this->moveAreaRadius - this->ballRadius)) {
        
        currentPoint = ccpAdd(ccp(0, 0), ccpMult(ccpNormalize(ccpSub(ccp(touchPoint.x - selfposition.x, touchPoint.y - selfposition.y), Point::ZERO)), this->moveAreaRadius - this->ballRadius));
    }else {
        currentPoint = Vec2(touchPoint.x - selfposition.x, touchPoint.y - selfposition.y);
    }
    
    this->ball->setPosition(currentPoint);
    
    //摇杆返回参数
    angle = atan2(this->ball->getPosition().y - 0, this->ball->getPosition().x - 0)/(3.14159/180);
    power = this->ball->getPosition().getDistance(Point::ZERO)/(this->moveAreaRadius - this->ballRadius);
    direction = Vec2(cos(angle * (3.14159/180)), sin(angle*(3.14159/180)));
    
    
    Sprite *stickTexture = dynamic_cast<Sprite *>(this->stick->getChildByTag(0));
    if (stickTexture) {
        this->stick->setScaleX(this->ball->getPosition().getDistance(Point::ZERO)/stickTexture->getTextureRect().size.width);
        this->stick->setRotation(-angle);
    }
    

}
void JoyStick::startTimer()
{
    if (this->delegate) {
        this->delegate->onCCJoyStickActivated(this);
    }
    this->schedule(schedule_selector(JoyStick::timerUpdate));
}
void JoyStick::stopTimer()
{
    if (this->delegate) {
        this->delegate->onCCJoyStickDeactivated(this);
    }
    this->unschedule(schedule_selector(JoyStick::timerUpdate));
}
void JoyStick::timerUpdate(float f)
{

    if (this->delegate) {
        this->delegate->onCCJoyStickUpdate(this, angle, direction, power);
    }

}

void JoyStick::setBallWithFrameName(const std::string &filename)
{
    this->ball->removeAllChildrenWithCleanup(true);
    Sprite *ballTexture = Sprite::createWithSpriteFrameName(filename);
    this->ball->addChild(ballTexture);
}
void JoyStick::setStickWithFrameName(const std::string &filename)
{
    this->stick->removeAllChildrenWithCleanup(true);
    Sprite *stickTexture = Sprite::createWithSpriteFrameName(filename);
    stickTexture->setPosition(Vec2(stickTexture->getContentSize().width*0.5, 0));
    
    this->stick->addChild(stickTexture);
    this->stick->setScaleX(this->ball->getPosition().distance(Point::ZERO)/stickTexture->getTextureRect().size.width);
}

void JoyStick::setDockWithFrameName(const std::string &filename)
{
    this->dock->removeAllChildrenWithCleanup(true);
    
    Sprite *dockTexture = Sprite::createWithSpriteFrameName(filename);
    this->dock->addChild(dockTexture);
}


void JoyStick::setBallWithName(const std::string& filename)
{
    this->ball->removeAllChildrenWithCleanup(true);
    Sprite *s = Sprite::create(filename);
    this->ball->addChild(s);
}
void JoyStick::setStickWithName(const std::string& filename)
{
    this->stick->removeAllChildrenWithCleanup(true);
    Sprite *s = Sprite::create(filename);
    this->stick->addChild(s);
}
void JoyStick::setDockWithName(const std::string& filename)
{
    this->dock->removeAllChildrenWithCleanup(true);
    Sprite *s = Sprite::create(filename);
    this->dock->addChild(s);
}


