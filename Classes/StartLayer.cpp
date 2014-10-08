//
//  StartLayer.cpp
//  ddgame
//
//  Created by mimix on 14-10-8.
//
//

#include "StartLayer.h"

bool StartLayer::init()
{
    auto sb1= LayerColor::create(Color4B(255, 255, 255, 255), 80, 25);
    sb1->setPosition(80,25);
    auto sb2= LayerColor::create(Color4B(255, 255, 255, 255), 80, 80);
    sb2->setPosition(80,25);
    auto menu=Menu::
    create(MenuItemSprite::create(sb1, sb1, [](Ref* r) {
        MessageBox("1", "3");
    }), MenuItemSprite::create(sb2, sb2, [](Ref* r)  {
        MessageBox("2", "3");
    }) , NULL);
    addChild(menu);
    
    
    return true;
}