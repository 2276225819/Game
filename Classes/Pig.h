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
#include "basePig.h"
USING_NS_CC;

 

class PigReverse : public Pig
{
public:
    PigReverse(int speed,int hp);
    //PigReverse( ):Pig( ) {};
    //void Drag(Vec2 v);
    void Run(Vec2 v);
};
class PigSwap : public Pig
{
public:
    void Run(Vec2 v);
     PigSwap( ):Pig( ) {};
    PigSwap(int speed,int hp);
};
class PigClone : public PigClick
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
