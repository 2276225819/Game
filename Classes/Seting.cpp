//
//  Seting.cpp
//  ddgame
//
//  Created by aaa on 14-10-10.
//
//

#include "Seting.h"
#include "SceneSwitch.h"

#define RockerUpPath "RockerUp.png"
#define RockerDownPath "RockerDown.png"
#define SlideUpPath "SlideUp.png"
#define SlideDownPath "SlideDown.png"


Scene * Seting::SceneCreate()
{
    auto s = Scene::create();
    auto l = Seting::create();
    s->addChild(l);
    return s;
}

void SetRockerMode(Ref* f)
{
    UserDefault::getInstance()->setBoolForKey("IMode", 1);
    SceneSwitch::Starting();
}

void SetSlideMode(Ref *f)
{
    UserDefault::getInstance()->setBoolForKey("IMode", 0);
    SceneSwitch::Starting();
}

bool Seting::init()
{
    auto Rocker = MenuItemImage::create(RockerUpPath, RockerDownPath,SetRockerMode);
    auto Slide = MenuItemImage::create(SlideUpPath, SlideDownPath,SetSlideMode);
    Rocker->setPosition(Vec2(0, 0));
    auto s=Rocker->getBoundingBox().size.width;
    
    Slide->setPosition(Vec2(Rocker->getPosition().x + s, 0));
    auto ButtonMenu = Menu::create(Rocker,Slide,NULL);
    ButtonMenu->setPosition(Vec2(100, 100));
    this->addChild(ButtonMenu);
    return true;
}