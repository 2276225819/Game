//
//  HRocker.h
//  game
//
//  Created by aaa on 14-9-23.
//
//

#ifndef __game__HRocker__
#define __game__HRocker__

#include <iostream>
#include "box2d/box2d.h"
#include "cocos2d.h"


using namespace cocos2d;

//枚举型：用于标识摇杆与摇杆的背景
typedef enum{
    
    tag_rocker,
    tag_rockerBG,
    
}tagForHRocker;

class HRocker : public Layer
{
public:
    //std::function<void (Vec2)> func;
    
    
    //创建摇杆，摇杆图片，摇杆背景图片，起始坐标
    static HRocker* createHRocker(const char* rockerImageName, const char* rockerBGImageName, Point position);
    
    //启动摇杆
    void startRocker(bool _isStopOther,Node * Obj);
    
    //停止摇杆
    void stopRocker();
    
    float angle;//弧度
    Vec2 v;
    
private:
    
    void rockerInit(const char* rockerImageName, const char* rockerBGImageName, Point position);
    
    //得到半径为r的圆周运动上一个角度应对应的x,y坐标
    CCPoint getAnglePosition(float r, float angle);
    
    //是否可操作摇杆
    bool isCanMove;
    
    //得到摇杆与用户触屏点的角度
    float getRad(Point pos1, Point pos2);
    
    //摇杆背景的坐标
    Point rockerBGPosition;
    
    //摇杆背景的半径
    float rockerBGR;
    
    //触屏事件
    void onTouchesBegan(std::vector<Touch *> touches, cocos2d::Event *unused_event);
    void onTouchesMoved(std::vector<Touch *> touches, cocos2d::Event *unused_event);
    void onTouchesEnded(std::vector<Touch *> touches, cocos2d::Event *unused_event);
    
    
    
    CREATE_FUNC(HRocker);
};

#endif /* defined(__game__HRocker__) */
