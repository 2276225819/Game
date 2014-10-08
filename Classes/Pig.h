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
<<<<<<< HEAD
    void run();
    std::function<void()> onDelete;
=======
    void Run();
    void Drag(Vec2 v);
    void Click();
    //std::function<void()> onDelete;
>>>>>>> FETCH_HEAD
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
<<<<<<< HEAD
    
=======
    void Run();
>>>>>>> FETCH_HEAD
};
class PigSwap : public Pig
{
public:
    PigSwap(int speed,int hp):Pig(speed,hp) {};
};
class PigClone : public Pig
{
public:
    PigClone(int speed,int hp):Pig(speed,hp) {};
};

class PigHide: public Pig
{
public:
    PigHide(int speed,int hp):Pig(speed,hp) {
        
    
    };
};




#endif /* defined(__ddgame__Pig__) */
