//
//  StartScene.cpp
//  ddgame
//
//  Created by mimix on 14-10-10.
//
//

#include "StartScene.h"
#include "SceneSwitch.h"

bool StartScene::init()
{
    auto l=LayerColor::create(Color4B(100, 100, 100, 255), 640, 1136);
    
    Size s=Director::getInstance()->getVisibleSize();
    auto aBtn= LabelTTF::create("疯狂模式", "", 30);
    aBtn->setColor(Color3B(255,0,0));
    auto bBtn= LabelTTF::create("简单模式", "", 30);
    
    bBtn->setColor(Color3B(255,0,0));
    auto cBtn= LabelTTF::create("Set", "", 30);
    
    auto itemA=MenuItemSprite::create(aBtn, aBtn,[](Ref* f){
        SceneSwitch::Playing(1);
    });
    auto itemB=MenuItemSprite::create(bBtn, bBtn,[](Ref* f){
        SceneSwitch::Playing(0);
    });
    
    auto itemSet=MenuItemSprite::create(cBtn, cBtn,[](Ref* f){
        SceneSwitch::Seting();
    });
    
    //itemB->setPosition(0,40);
    //itemB->setPosition(0,0);
    itemA->setPosition(640/2+80 , 300);
    itemB->setPosition(640/2-80,300);
    itemSet->setPosition(640/2,250);
    Menu* m=Menu::create(itemA,itemB, itemSet, NULL);
    m->setPosition(0,0);
    //m->ignoreAnchorPointForPosition(false);
    l->addChild(m);
    addChild(l);
    return true;
}
