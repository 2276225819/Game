//
//  Seting.cpp
//  ddgame
//
//  Created by aaa on 14-10-10.
//
//

#include "Seting.h"

#define RockerUpPath ""
#define RockerDownPath ""
#define SlideUpPath ""
#define SlideDownPath ""


Scene * Seting::SceneCreate()
{
    auto s = Scene::create();
    auto l = Seting::create();
    s->addChild(l);
    return s;
}

void EnterGame(Ref* f)
{
    //UserDefault::setBoolForKey(<#const char *pKey#>, <#bool value#>)
}

bool Seting::init()
{
    auto Rocker = MenuItemImage::create(RockerUpPath, RockerDownPath,EnterGame);
    return true;
}