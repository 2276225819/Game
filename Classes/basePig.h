//
//  basePig.h
//  ddgame
//
//  Created by aaa on 14-10-9.
//
//

#ifndef __ddgame__basePig__
#define __ddgame__basePig__

#include "cocos2d.h"
USING_NS_CC;
class Pig:public Sprite
{
protected:
    void shake();
    void hit();

    int Speed;
    Vec2 v;
    int Hp;
    int RectSize = 640;
public:
    int MaxHp;
public:
    virtual void Run(Vec2 v);
    virtual void RunAt(Vec2 v,Vec2 pos);
    virtual void Drag(int tag);
    virtual void Click();
    virtual void Remove();
    Vec2 FlagToVec(Vec2 v);
    bool isDie();
    void Kill();
public:
    Pig();
    Pig(int speed,int hp);
    void init(int speed,int hp);
    static Pig* create(int speed,int hp);
    //static Pig* createPig(int Tag);
};





#endif /* defined(__ddgame__basePig__) */
