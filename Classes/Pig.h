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
protected:
    int Speed;
    Vec2 v;
    int Hp;

public:
    int MaxHp;
public:
    virtual void Run(Vec2 v);
    void RunAt(Vec2 v,Vec2 pos);
    void Drag(Vec2 v);
    void Click();
//<<<<<<< HEAD
    Vec2 FlagToVec(Vec2 v);
    //std::function<void()> onDelete;
 
//=======
    bool isDie();
    void Remove();
//>>>>>>> FETCH_HEAD
public:
    Pig();
    Pig(int speed,int hp);
    void init(int speed,int hp);
    static Pig* create(int speed,int hp);
    static Pig* createPig(int Tag);
};

class PigReverse : public Pig
{
public:
    PigReverse(int speed,int hp);
    //PigReverse( ):Pig( ) {};
    void Drag(Vec2 v);
      void Run(Vec2 v);
};
class PigSwap : public Pig
{
public:
    void Run(Vec2 v);
     PigSwap( ):Pig( ) {};
    PigSwap(int speed,int hp);
};
class PigClone : public Pig
{
public:
    void Avatar();
      void Run(Vec2 v);
    //PigClone( ):Pig( ) {};
    PigClone(int speed,int hp);
};

class PigHide: public Pig
{
public:
      void Run(Vec2 v);
    //PigHide( ):Pig( ) {};
    PigHide(int speed,int hp);
};




#endif /* defined(__ddgame__Pig__) */
