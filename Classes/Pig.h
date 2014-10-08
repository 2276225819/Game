//
//  Pig.h
//  ddgame
//
//  Created by aaa on 14-10-8.
//
//

#ifndef __ddgame__Pig__
#define __ddgame__Pig__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class Pig:public Sprite
{

public:
    int Speed;
    Vec2 v;
public:
    int Hp;
 
    void Run();
    void Drag(Vec2 v);
    void Click();
    //std::function<void()> onDelete;
 
public:
    Pig(int speed,int hp);
    void init(int speed,int hp);
    static Pig* create(int speed,int hp);
    static Pig* createPig(int Tag);
};

class PigReverse : public Pig
{
public:
    PigReverse(int speed,int hp):Pig(speed,hp) {};
    void Run(); 
};
class PigSwap : public Pig
{
public:
    void Run();
    PigSwap(int speed,int hp):Pig(speed,hp) {};
};
class PigClone : public Pig
{
public:
    void Run();
    PigClone(int speed,int hp):Pig(speed,hp) {};
};

class PigHide: public Pig
{
public:
    void Run();
    PigHide(int speed,int hp):Pig(speed,hp) {};
};




#endif /* defined(__ddgame__Pig__) */
