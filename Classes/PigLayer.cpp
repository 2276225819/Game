//
//  PigLayer.cpp
//  ddgame
//
//  Created by aaa on 14-10-8.
//
//

#include "PigLayer.h"

Vec2 Flag[8] = {Vec2(0,0),Vec2(0,0.5),Vec2(0,1),Vec2(0.5,1),Vec2(1,1),Vec2(1,0.5),Vec2(1,0),Vec2(0.5,0)};

bool PigLayer::init()
{
    return true;
}

void PigLayer::addPig(int Fx,int Type)
{
    auto p =  createPig(Type);
    p->setTag(Fx);
    p->Run(Flag[Fx]);
    this->addChild(p);
}

void PigLayer::addRndPig()
{
    int Fx = arc4random()%8;//方向
    int Tp= arc4random()%7; //小猪类型
    addPig(Fx, Tp+1);
}
void PigLayer::pigDelete()
{
    
}

void PigLayer::each(std::function<bool(Pig*)> fn)
{
    auto ls=getChildren();
    for (int i=0,len=(int)(ls.size()); i<len; i++) {
        auto p=(Pig *)ls.at(i);
        if(!fn(p))
            break;
    }
}

std::string s[] ={"普通","快速","厚血","箭猪","变轨","分身","隐形","分身猪"};

Pig* PigLayer::createPig(int pigType)
{
    Pig* p;
    
    switch (pigType) {
        case 1: //普通🐷
            p= new Pig(2, 1);
            break;
        case 2: //快速🐷
            p= new Pig(3, 1);
            break;
        case 3: //厚血🐷
            p= new Pig(1, 3);
            break;
        case 4: //箭猪🐷
            p=new PigReverse(1, 1);
            break;
        case 5: //变轨🐷
            p=new PigSwap(2, 1);
            break;
        case 6: //分身🐷
            p=new PigClone(2, 2);
            break;
        case 7: //隐形🐷
            p=new PigHide(2, 1);
            break;
        case 8://分身小猪🐷
            p=new PigClick(2,1);
            break;
        default://test小猪
            p=new Pig(3, 3);
            break;
    }
    p->addChild(LabelTTF::create(s[pigType-1], "yahai",200));//, const std::string &fontName, float fontSize)
    p->autorelease();
    p->setColor(Color3B(pigType*35, 0, 0));
    return p;
}